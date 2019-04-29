#include "GamePCH.h"

PauseScene::PauseScene(Game * pGame, ResourceManager * pResources, std::string name)
    : Scene(pGame, pResources, name)
{

}

PauseScene::~PauseScene()
{
}

void PauseScene::OnSurfaceChanged(unsigned int width, unsigned int height)
{
}

void PauseScene::LoadContent()
{
    Scene::LoadContent();
    m_pWorld = new World(b2Vec2(0, -9.8f));
    // Camera
    m_pGameObjects["Camera"] = new CameraObject(this, "Camera", vec3(0, 0, 0), vec3(0, 0, 0), vec3(1, 1, 1));
    ((CameraObject*)m_pGameObjects["Camera"])->SetCameraDistance(17);

    AddLight(vec3(0,0,0), vec4(1,1,1,1));
    AddLight(vec3(0, 0, 0), vec4(1, 1, 1, 1));
    AddLight(vec3(0, 0, 0), vec4(1, 1, 1, 1));

    m_pGameObjects["Meat Boy Grill"] = new GameObject(this, "Meat Boy Grill", vec3(0, 0, 0), vec3(0, 0, 0), vec3(1, 1, 1), "Box", "Meat Boy Grill Material");

}

void PauseScene::OnEvent(Event * pEvent)
{
    Scene::OnEvent(pEvent);
    if (pEvent->GetEventType() == EventType_Input)
    {
        InputEvent* pInputEvent = (InputEvent*)pEvent;
        if (pInputEvent->GetInputDeviceType() == InputDeviceType_Keyboard) // logic for pausing
        {
            if (pInputEvent->GetInputState() == InputState_Released)
            {
                if (pInputEvent->GetID() == 'P')
                {
                  
                    UnPauseEvent* Event = new UnPauseEvent(this);
                    GetGame()->QueueEvent(Event);
                
                    PopBackEvent* Event2 = new PopBackEvent(this);
                    GetGame()->QueueEvent(Event2);
                    
                }
            }
        }
    }


}

void PauseScene::Update(float deltatime)
{
    Scene::Update(deltatime);

    m_pWorld->Update(deltatime);
    
}

void PauseScene::Draw()
{
    Scene::Draw();
}
