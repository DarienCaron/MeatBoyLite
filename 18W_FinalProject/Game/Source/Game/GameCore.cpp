#include "pch.h"

GameCore::GameCore()
{
    m_pScene = 0;
    m_pResources = 0;
}

GameCore::~GameCore()
{
    while( m_EventQueue.size() != 0 )
    {
        Event* pEvent = m_EventQueue.front();
        m_EventQueue.pop();
        delete pEvent;
    }

    delete m_pScene;
    delete m_pResources;
}

void GameCore::OnSurfaceChanged(unsigned int width, unsigned int height)
{
    glViewport( 0, 0, width, height );

    m_WindowWidth = width;
    m_WindowHeight = height;
}

void GameCore::LoadContent()
{
    // turn on depth buffer testing.
    glEnable( GL_DEPTH_TEST );
    glDepthFunc( GL_LESS );

    // turn on alpha blending.
    glEnable( GL_BLEND );
    glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );

    m_pResources = new ResourceManager();

    m_pScene = new SampleScene( this, m_pResources );
    m_pScene->LoadContent();

    CheckForGLErrors();
}

void GameCore::QueueEvent(Event* pEvent)
{
    m_EventQueue.push( pEvent );
}

void GameCore::ProcessEvents()
{
    while( m_EventQueue.size() != 0 )
    {
        Event* pEvent = m_EventQueue.front();
        m_EventQueue.pop();

        OnEvent( pEvent );
        delete pEvent;
    }
}

void GameCore::OnEvent(Event* pEvent)
{
    m_pScene->OnEvent( pEvent );

    if( pEvent->GetEventType() == EventType_Input )
    {
        InputEvent* pInput = (InputEvent*)pEvent;

#if _WIN32
        if( pInput->GetInputDeviceType() == InputDeviceType_Keyboard )
        {
            int id = pInput->GetID();

            if( pInput->GetInputState() == InputState_Pressed )
            {
                if( id == VK_UP || id == 'W' )
                    m_Controllers[0].SetButtonPressed( PCB_Up );
                if( id == VK_DOWN || id == 'S' )
                    m_Controllers[0].SetButtonPressed( PCB_Down );
                if( id == VK_LEFT || id == 'A' )
                    m_Controllers[0].SetButtonPressed( PCB_Left );
                if( id == VK_RIGHT || id == 'D' )
                    m_Controllers[0].SetButtonPressed( PCB_Right );
            }

            if( pInput->GetInputState() == InputState_Released )
            {
                if( id == VK_UP || id == 'W' )
                    m_Controllers[0].SetButtonReleased( PCB_Up );
                if( id == VK_DOWN || id == 'S' )
                    m_Controllers[0].SetButtonReleased( PCB_Down );
                if( id == VK_LEFT || id == 'A' )
                    m_Controllers[0].SetButtonReleased( PCB_Left );
                if( id == VK_RIGHT || id == 'D' )
                    m_Controllers[0].SetButtonReleased( PCB_Right );
            }
        }
#endif // _WIN32

        if( pInput->GetInputDeviceType() == InputDeviceType_Gamepad )
        {
            if( pInput->GetInputState() == InputState_Held )
            {
                if( pInput->GetGamepadID() == GamepadID_LeftStick )
                {
                    if( pInput->GetPosition().y > 0 )
                        m_Controllers[0].SetButtonPressed( PCB_Up );
                    if( pInput->GetPosition().y < 0 )
                        m_Controllers[0].SetButtonPressed( PCB_Down );
                    if( pInput->GetPosition().x < 0 )
                        m_Controllers[0].SetButtonPressed( PCB_Left );
                    if( pInput->GetPosition().x > 0 )
                        m_Controllers[0].SetButtonPressed( PCB_Right );

                    if( pInput->GetPosition().y == 0 )
                    {
                        m_Controllers[0].SetButtonReleased( PCB_Up );
                        m_Controllers[0].SetButtonReleased( PCB_Down );
                    }
                    if( pInput->GetPosition().x == 0 )
                    {
                        m_Controllers[0].SetButtonReleased( PCB_Left );
                        m_Controllers[0].SetButtonReleased( PCB_Right );
                    }
                }
            }
        }
    }
}

void GameCore::Update(float deltatime)
{
    CheckForGLErrors();

    ProcessEvents();
    m_pScene->Update( deltatime );

    CheckForGLErrors();
}

void GameCore::Draw()
{
    CheckForGLErrors();

    // clear the screen to dark blue.
    glClearColor( 0.0f, 0.0f, 0.3f, 0.0f );
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

    m_pScene->Draw();

    CheckForGLErrors();
}
