#include "GamePCH.h"

const float TITLE_SCREEN_TIMER_DURATION = 1.0f;

TitleScene::TitleScene(Game * pGame, ResourceManager * pResources, std::string name)
    : Scene(pGame, pResources, name)
{
    m_titleTimer = TITLE_SCREEN_TIMER_DURATION;
}

TitleScene::~TitleScene()
{
}

void TitleScene::OnSurfaceChanged(unsigned int width, unsigned int height)
{
    Scene::OnSurfaceChanged(width, height);
}

void TitleScene::LoadContent()
{
    Scene::LoadContent();
    m_pWorld = new World(b2Vec2(0, -9.8f));

 

    // Camera
    m_pGameObjects["Camera"] = new CameraObject(this, "Camera", vec3(0, 0, 0), vec3(0, 0, 0), vec3(1, 1, 1));
    ((CameraObject*)m_pGameObjects["Camera"])->SetCameraDistance(15);
    AddLight(vec3(0, 0, 0), vec4(1, 1, 1, 1));
    AddLight(vec3(0, 0, 0), vec4(1, 1, 1, 1));
    AddLight(vec3(0, 0, 0), vec4(1, 1, 1, 1));

    m_pGameObjects["Sawblade"] = new GameObject(this, "Sawblade", vec3(-1.20f, 0, 0), vec3(0, 0, 0), vec3(2, 2, 1), "Box", "Title Screen Sawblade Material");
    m_pGameObjects["Sawblade"]->CreateBody(0);
    m_pGameObjects["Sawblade"]->AddCircle(1, false, 0, 0, 4, 0, 0);
    m_pGameObjects["Sawblade"]->SetRenderOrder(1);
    m_pGameObjects["Sawblade"]->SetRenderOrder(1);

    // Load our default title card
    m_pGameObjects["Title Screen"] = new GameObject(this, "Title Screen", vec3(0, 0, 0), vec3(0, 0, 0), vec3(20, 20, 1), "Box", "Title-Default Material");

    ((CameraObject*)m_pGameObjects["Camera"])->SetFocusObject(m_pGameObjects["Title Screen"]);

    this->GetResourceManager()->GetSoundPlayer("Title_MusicPlayer")->PlaySound(this->GetResourceManager()->GetSoundObject("Main Theme"));

    // Creating a revolute joint on the title screen for added juice
    m_pGameObjects["Sawblade"]->CreateRevoluteJoint(m_pGameObjects["Sawblade"]->GetPosition().x, m_pGameObjects["Sawblade"]->GetPosition().y,
        m_pGameObjects["Sawblade"]->GetBody(), m_pWorld->GetGround(), true, 25, 5, false, 0, 0, false, 0, 0);


    
}

void TitleScene::Update(float deltatime)
{
    Scene::Update(deltatime);

    m_pWorld->Update(deltatime);
   
        // when the player presses "start" (enter) the title screen card changes for a brief amount of time before the game starts. 
    if (m_Pressed == true)
    {
        Material* mat = this->GetResourceManager()->GetMaterial("Title-Pressed Material");
        m_pGameObjects["Title Screen"]->SetMaterial(mat);
        m_titleTimer -= deltatime; 
    }
    if (m_titleTimer <= 0) // after a short delay, change the scene to the level select screen
    {
        //GetGame()->GetSceneManager()->PopScene(this);
        //GetGame()->GetSceneManager()->PushScene("Level Select");

        Scene* pScene = GetGame()->GetSceneManager()->GetScene("Level Select");
        PopBackEvent* pEvent2 = new PopBackEvent(this);
        GetGame()->QueueEvent(pEvent2);


        PushSceneEvent* pEvent = new PushSceneEvent(pScene);
        GetGame()->QueueEvent(pEvent);

    }
    
}

void TitleScene::OnEvent(Event* pEvent)
{
    Scene::OnEvent(pEvent);

    if (pEvent->GetEventType() == EventType_Input)
    {
        InputEvent* pInputEvent = (InputEvent*)pEvent;

        if (pInputEvent->GetInputDeviceType() == InputDeviceType_Keyboard)
        {
            if (pInputEvent->GetInputState() == InputState_Pressed)
            {
                if (pInputEvent->GetID() == VK_RETURN) // play a punch sound when the user hits "start"
                {
                    m_Pressed = true;
                   // this->GetResourceManager()->GetSoundPlayer("Title_SoundPlayer")->PlaySound(this->GetResourceManager()->GetSoundObject("Punch"));
                   
                }
            }
        }
    }


}


void TitleScene::Draw()
{
    Scene::Draw();
}


