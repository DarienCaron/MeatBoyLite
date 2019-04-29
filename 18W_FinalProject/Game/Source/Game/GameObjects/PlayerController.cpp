#include "GamePCH.h"

PlayerController::PlayerController()
{
    Clear();
}

PlayerController::~PlayerController()
{
}

void PlayerController::Clear()
{
    m_ButtonFlags = 0;
}

void PlayerController::SetButtonPressed(PlayerControllerButtons button)
{
    m_ButtonFlags |= button;
}

void PlayerController::SetButtonReleased(PlayerControllerButtons button)
{
    m_ButtonFlags &= ~button;
}

bool PlayerController::IsButtonPressed(PlayerControllerButtons button)
{
    if( m_ButtonFlags & button )
        return true;

    return false;
}

void PlayerController::OnEvent(Event* pEvent)
{
    if( pEvent->GetEventType() == EventType_Input )
    {
        InputEvent* pInputEvent = (InputEvent*)pEvent;

        if( pInputEvent->GetInputDeviceType() == InputDeviceType_Keyboard )
        {
            if( pInputEvent->GetInputState() == InputState_Pressed )
            {
                if( pInputEvent->GetID() == VK_UP || pInputEvent->GetID() == 'W' )
                    SetButtonPressed( PCB_Up );
                if( pInputEvent->GetID() == VK_DOWN || pInputEvent->GetID() == 'S' )
                    SetButtonPressed( PCB_Down );
                if( pInputEvent->GetID() == VK_LEFT || pInputEvent->GetID() == 'A' )
                    SetButtonPressed( PCB_Left );
                if( pInputEvent->GetID() == VK_RIGHT || pInputEvent->GetID() == 'D' )
                    SetButtonPressed( PCB_Right );
                if (pInputEvent->GetID() == VK_SPACE)
                    SetButtonPressed(PCB_Spacebar);

            }

            if( pInputEvent->GetInputState() == InputState_Released )
            {
                if( pInputEvent->GetID() == VK_UP || pInputEvent->GetID() == 'W' )
                    SetButtonReleased( PCB_Up );
                if( pInputEvent->GetID() == VK_DOWN || pInputEvent->GetID() == 'S' )
                    SetButtonReleased( PCB_Down );
                if( pInputEvent->GetID() == VK_LEFT || pInputEvent->GetID() == 'A' )
                    SetButtonReleased( PCB_Left );
                if( pInputEvent->GetID() == VK_RIGHT || pInputEvent->GetID() == 'D' )
                    SetButtonReleased( PCB_Right );
                if (pInputEvent->GetID() == VK_SPACE)
                    SetButtonReleased(PCB_Spacebar);

            }
        }

        if( pInputEvent->GetInputDeviceType() == InputDeviceType_Gamepad )
        {
            if( pInputEvent->GetInputState() == InputState_Held )
            {
                if( pInputEvent->GetGamepadID() == GamepadID_LeftStick )
                {
                    if( pInputEvent->GetPosition().y > 0 )
                        SetButtonReleased( PCB_Up );
                    if( pInputEvent->GetPosition().y < 0 )
                        SetButtonReleased( PCB_Down );
                    if( pInputEvent->GetPosition().x < 0 )
                        SetButtonReleased( PCB_Left );
                    if( pInputEvent->GetPosition().x > 0 )
                        SetButtonReleased( PCB_Right );

                    if( pInputEvent->GetPosition().y == 0 )
                    {
                        SetButtonReleased( PCB_Up );
                        SetButtonReleased( PCB_Down );
                    }
                    if( pInputEvent->GetPosition().x == 0 )
                    {
                        SetButtonReleased( PCB_Left );
                        SetButtonReleased( PCB_Right );
                    }
                }
            }
        }
    }
}