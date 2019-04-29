#include "GamePCH.h"

LevelSelectScene::LevelSelectScene(Game * pGame, ResourceManager * pResources, std::string name)
    : Scene(pGame, pResources,name)
{
}

LevelSelectScene::~LevelSelectScene()
{
    delete m_pTweenObject; 
}

void LevelSelectScene::OnSurfaceChanged(unsigned int width, unsigned int height)
{
    Scene::OnSurfaceChanged(width, height);
}

void LevelSelectScene::LoadContent()
{
    Scene::LoadContent();

    m_pWorld = new World(b2Vec2(0, -9.8f));

    m_LevelIndex = 0;
    //Camera
    m_pGameObjects["Camera"] = new CameraObject(this, "Camera", vec3(0, 0, 0), vec3(0, 0, 0), vec3(1, 1, 1));
    ((CameraObject*)m_pGameObjects["Camera"])->SetCameraDistance(15);

   // GameObjects

    m_pGameObjects["Meat Boy"] = new GameObject(this, "Meat Boy", vec3(-3.5, -4.5, 0), vec3(0, 0, 0), vec3(1.5, 1.5, 1), "Box", "Meat Boy on Map Material");
    m_pGameObjects["Meat Boy"]->SetRenderOrder(1);

    m_pGameObjects["Level Banner"] = new GameObject(this, "Level Banner", vec3(0, -8, 0), vec3(0, 0, 0), vec3(9, 3, 1), "Box", "Level 1 Banner Material");
    m_pGameObjects["Level Banner"]->SetRenderOrder(1);
    
    m_pGameObjects["Level 1 Square"] = new GameObject(this, "Level 1 Square", vec3(-3.5, -5, 0), vec3(0, 0, 0), vec3(2.5, 1.5, 1), "Box", "Level Square White Material");
    m_pGameObjects["Level 1 Square"]->SetRenderOrder(1);

    m_pGameObjects["Level 2 Square"] = new GameObject(this, "Level 2 Square", vec3(4, -5, 0), vec3(0, 0, 0), vec3(2.5, 1.5, 1), "Box", "Level Square White Material");
    m_pGameObjects["Level 2 Square"]->SetRenderOrder(1);

    m_pGameObjects["Level 1 Bandage Icon"] = new GameObject(this, "Level 1 Bandage Icon", vec3(-100, -100, 0), vec3(0, 0, 0), vec3(1, 0.75, 1), "Box", "Bandage Icon Material");
    m_pGameObjects["Level 1 Bandage Icon"]->SetRenderOrder(1);

    m_pGameObjects["Level 2 Bandage Icon"] = new GameObject(this, "Level 2 Bandage Icon", vec3(-100, -100, 0), vec3(0, 0, 0), vec3(1, 0.75, 1), "Box", "Bandage Icon Material");
    m_pGameObjects["Level 2 Bandage Icon"]->SetRenderOrder(1);

    m_pGameObjects["Level Select"] = new GameObject(this, "Level Select", vec3(0, 0, 0), vec3(0, 0, 0), vec3(20, 20, 1), "Box", "Level Select Screen Material");
    m_pGameObjects["Level Select"]->SetRenderOrder(0);

    ((CameraObject*)m_pGameObjects["Camera"])->SetFocusObject(m_pGameObjects["Level Select"]);
    m_Tweenpos = 0;

    m_pGameObjects["Level1_Window"] = new GameObject(this, "Level1_Window", vec3(0, 4, 0), vec3(0, 0, 0), vec3(10, 10, 1), "Box", "Frame_Window_Mat");
    m_pGameObjects["Level1_Window"]->SetRenderOrder(1);

    m_pGameObjects["Rendered Level Preview"] = new GameObject(this, "Rendered Level Preview", vec3(0, 4, 0), vec3(0,0,0), vec3(8, 8, 1), "Box", "Rendered Scene Material");
    m_pGameObjects["Rendered Level Preview"]->SetRenderOrder(0);

    float xpos = m_pGameObjects["Meat Boy"]->GetPosition().x;
    float* value = &xpos;


    m_pTweenObject = new TweenObject();

    AddLight(vec3(0,0,0), vec4(1,1,1,1));
    AddLight(vec3(0, 0, 0), vec4(1, 1, 1, 1));
    AddLight(vec3(0, 0, 0), vec4(1, 1, 1, 1));

    m_pGame->GetSceneManager()->SetRenderToTextureScene("Sample",1);
    ((SampleScene*)m_pGame->GetSceneManager()->GetRenderToTextureScene(1))->SetIsBeingRendered(true);

    m_pGame->GetSceneManager()->SetRenderToTextureScene("Second Level", 2);
    ((SecondLevelScene*)m_pGame->GetSceneManager()->GetRenderToTextureScene(2))->SetIsBeingRendered(true);




   
}

void LevelSelectScene::Update(float deltatime)
{
    m_pWorld->Update(deltatime);
    Scene::Update(deltatime);
    // Check what the level we are currently on is
    {
        if (m_LevelIndex == 0)
        {
            m_Level = Level1;

            Material* mat = GetResourceManager()->GetMaterial("Rendered Scene Material");
            m_pGameObjects["Rendered Level Preview"]->SetMaterial(mat);

            m_pTweenObject->Setup(m_pGameObjects["Meat Boy"]->GetPosition().x, m_pGameObjects["Level 1 Square"]->GetPosition().x, 1.0f, deltatime, TweenTypeLinear);
            m_pTweenObject->Update(deltatime);

        }
        else if (m_LevelIndex == 1)
        {
            m_Level = Level2;

            Material* mat = GetResourceManager()->GetMaterial("Rendered Scene Material2"); // Checks for the current level and will change the FBO material to the appropriate render scene
            m_pGameObjects["Rendered Level Preview"]->SetMaterial(mat);

            m_pTweenObject->Setup(m_pGameObjects["Meat Boy"]->GetPosition().x, m_pGameObjects["Level 2 Square"]->GetPosition().x, 1.0f, deltatime, TweenTypeLinear);
            m_pTweenObject->Update(deltatime);


        }
    }
    
    


    if (m_Selected == true)
    {
       
        ChangeLevels(m_Level);     
    }

    // Check if the level is beaten or not
    {
        bool Level1IsBeat = ((SampleScene*)GetGame()->GetSceneManager()->GetScene("Sample"))->GetIsBeaten();
        bool Level2IsBeat = ((SecondLevelScene*)GetGame()->GetSceneManager()->GetScene("Second Level"))->GetIsBeaten();
        if (Level1IsBeat == true)
        {
            Material* mat = GetResourceManager()->GetMaterial("Level Square Red Material");
            m_pGameObjects["Level 1 Square"]->SetMaterial(mat);

        }
        if (Level2IsBeat == true)
        {
            Material* mat = GetResourceManager()->GetMaterial("Level Square Red Material");
            m_pGameObjects["Level 2 Square"]->SetMaterial(mat);
        }
    }

        

    

}

void LevelSelectScene::Draw()
{
    Scene::Draw();
}

void LevelSelectScene::ChangeLevels(Levels level)
{
    if (level == Level1)
    {

        PopBackEvent* pEvent2 = new PopBackEvent(this);
        GetGame()->QueueEvent(pEvent2);

        Scene* pScene = this->GetGame()->GetSceneManager()->GetScene("Sample");
        PushSceneEvent* pEvent = new PushSceneEvent(pScene);
        GetGame()->QueueEvent(pEvent);

        ((SampleScene*)m_pGame->GetSceneManager()->GetRenderToTextureScene(1))->SetIsBeingRendered(false);
        m_Selected = false;


    }
    if (level == Level2)
    {

        PopBackEvent* pEvent2 = new PopBackEvent(this);
        GetGame()->QueueEvent(pEvent2);

        Scene* pScene = this->GetGame()->GetSceneManager()->GetScene("Second Level");
        PushSceneEvent* pEvent = new PushSceneEvent(pScene);
        GetGame()->QueueEvent(pEvent);

        ((SecondLevelScene*)m_pGame->GetSceneManager()->GetRenderToTextureScene(2))->SetIsBeingRendered(false);
        m_Selected = false;

    }

}

void LevelSelectScene::OnEvent(Event* pEvent)
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
                    m_Selected = true;
                    
                }

                if (pInputEvent->GetID() == VK_LEFT)
                {
                    m_LevelIndex--;
                    if (m_LevelIndex < 0)
                    {
                        m_LevelIndex = 0;
                    }
                }

                if (pInputEvent->GetID() == VK_RIGHT)
                {
                    m_LevelIndex++;
                    if (m_LevelIndex > 1)//Amount of levels
                    {
                        m_LevelIndex = 1;
                    }
                }

                else if (pInputEvent->GetID() == 'M') // setting the debugging modes for Meat Boy's stats
                {
                    if (m_MIsPressed == false)
                    {
                        ((PlayerObject*)m_pGameObjects["Meat Boy"])->SetSecondDebugMode(true);
                        m_MIsPressed = true;
                    }
                    else if (m_MIsPressed == true)
                    {
                        ((PlayerObject*)m_pGameObjects["Meat Boy"])->SetSecondDebugMode(false);
                        m_MIsPressed = false;
                    }
                }

                else if (pInputEvent->GetID() == 'R') //setting the debugging modes for the camera's rotation
                {
                    if (m_RIsPressed == false)
                    {
                        ((CameraObject*)m_pGameObjects["Camera"])->SetSecondDebugMode(true);
                        m_RIsPressed = true;
                    }
                    else if (m_RIsPressed == true)
                    {
                        ((CameraObject*)m_pGameObjects["Camera"])->SetSecondDebugMode(false);
                        m_RIsPressed = false;
                    }
                }
            }
        }
    }
   
}
