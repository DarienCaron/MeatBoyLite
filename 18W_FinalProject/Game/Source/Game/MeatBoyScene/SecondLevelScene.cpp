#include "GamePCH.h"

const vec3 MEAT_BOY_STARTING_POINT = vec3(-1, 3, 0);
const float SAWBLADE_TIMER_DURATION = 2.0f;

SecondLevelScene::SecondLevelScene(Game* pGame, ResourceManager* pResources, std::string name)
: Scene( pGame, pResources, name )
{
    m_SawbladeTimer = SAWBLADE_TIMER_DURATION;
}

SecondLevelScene::~SecondLevelScene()
{
}

void SecondLevelScene::OnSurfaceChanged(unsigned int width, unsigned int height)
{
    Scene::OnSurfaceChanged( width, height );
}


void SecondLevelScene::LoadContent()
{
    Scene::LoadContent();
    m_pWorld = new World(b2Vec2(0, -9.8f));

    {
        m_pContactListener = new ContactListener();
        m_pWorld->GetPhysicsWorld()->SetContactListener(m_pContactListener);
        m_pSkyBox = new SkyBox(this, "SkyBox", vec3(0, 0, 0), vec3(0,0,0), vec3(1,1,1), "SkyBox", "CubeMap_Mat");

           // Camera
        m_pGameObjects["Camera"] = new CameraObject(this, "Camera", vec3(0, 0, 0), vec3(0, 0, 0), vec3(1, 1, 1));
        ((CameraObject*)m_pGameObjects["Camera"])->SetCameraDistance(17);

        // Score Display
        m_pGameObjects["Timer"] = new ScoreDisplay(this, "Timer",
            vec3(0, -4, 0), vec3(0, 0, 0), vec3(1, 1, 1),
            m_pResources->GetMesh("Box"), m_pResources->GetMaterial("Timer Numbers Material"));
        m_pGameObjects["Timer"]->SetRenderOrder(1);

        AddLight(vec3(0, 0, 0), vec4(1, 1, 1, 1));
        AddLight(vec3(0, 2, 0), vec4(1, 0, 1, 1));
        AddLight(vec3(0, 2, 1), vec4(1, 1, 1, 1));

        // Creating Game Objects
        {
             
            m_pGameObjects["Meat Boy"] = new PlayerObject(this, "Meat Boy", MEAT_BOY_STARTING_POINT, vec3(0, 0, 0), vec3(1, 1, 1), "Box", "Meat Boy Material");
            ((PlayerObject*)m_pGameObjects["Meat Boy"])->SetController(m_pGame->GetController(0));
            vec3 playerPosition = ((PlayerObject*)m_pGameObjects["Meat Boy"])->GetPosition();
            ((PlayerObject*)m_pGameObjects["Meat Boy"])->CreateBody(0);
            ((PlayerObject*)m_pGameObjects["Meat Boy"])->GetBody()->SetFixedRotation(true);
            ((PlayerObject*)m_pGameObjects["Meat Boy"])->AddBox(0.5f, 0.5f, 1.0, false, 0.0f, 0, Category_MeatBoy, Category_Sawblade | Category_Ground | Category_Missile | Category_Wall | Category_BandageGirl | Category_BandagePickup);
            ((PlayerObject*)m_pGameObjects["Meat Boy"])->GetBody()->SetActive(true);

            ((PlayerObject*)m_pGameObjects["Meat Boy"])->SetRespawnPosition(MEAT_BOY_STARTING_POINT);

            ((CameraObject*)m_pGameObjects["Camera"])->SetFocusObject(m_pGameObjects["Meat Boy"]);

            m_pGameObjects["Bandage Girl 2"] = new BandageGirlObject(this, "Bandage Girl 2", vec3(0, 26, 0), vec3(0, 0, 0), vec3(1, 1, 1), "Box", "Bandage Girl Material");
            ((BandageGirlObject*)m_pGameObjects["Bandage Girl 2"])->CreateBody(1);
            ((BandageGirlObject*)m_pGameObjects["Bandage Girl 2"])->GetBody()->SetFixedRotation(true);
            ((BandageGirlObject*)m_pGameObjects["Bandage Girl 2"])->AddBox(1, 1, 1.0, false, 0.6f, 0, Category_BandageGirl, Category_Ground | Category_MeatBoy);
            ((BandageGirlObject*)m_pGameObjects["Bandage Girl 2"])->GetBody()->SetActive(true);

            m_pGameObjects["Bandage Pickup"] = new BandagePickupObject(this, "Bandage Pickup", vec3(0, 22, 0), vec3(0, 0, 0), vec3(0.75, 0.75, 1), "Box", "Bandage Pickup Material");
            ((BandagePickupObject*)m_pGameObjects["Bandage Pickup"])->CreateBody(1);
            ((BandagePickupObject*)m_pGameObjects["Bandage Pickup"])->AddBox(0.75, 0.75, 0, false, 0, 0, Category_BandagePickup, Category_MeatBoy);
            ((BandagePickupObject*)m_pGameObjects["Bandage Pickup"])->SetRenderOrder(1);
            ((BandagePickupObject*)m_pGameObjects["Bandage Pickup"])->GetBody()->SetActive(true);


            m_pGameObjects["Sawblade Launcher"] = new GameObject(this, "Sawblade Launcher", vec3(0, 24, 0), vec3(0, 0, 90), vec3(1.5f, 1.5f, 1), "Box", "Sawblade Launcher Material");
            m_pGameObjects["Sawblade Launcher"]->CreateBody(1);

            m_pGameObjects["Sawblade in Launcher"] = new SawBladeObject(this, "Sawblade in Launcher", vec3(0, 24, 0), vec3(0, 0, 0), vec3(1.25, 1.25, 1), "Box", "Clean Sawblade Material");
            ((SawBladeObject*)m_pGameObjects["Sawblade in Launcher"])->CreateBody(0);
            ((SawBladeObject*)m_pGameObjects["Sawblade in Launcher"])->AddCircle(1.25, false, 0, 0, 1, Category_Sawblade, Category_MeatBoy);
            ((SawBladeObject*)m_pGameObjects["Sawblade in Launcher"])->SetRenderOrder(0);
            ((SawBladeObject*)m_pGameObjects["Sawblade in Launcher"])->GetBody()->SetActive(true);

            m_pGameObjects["Sawblade Right"] = new SawBladeObject(this, "Sawblade Right", vec3(-7, 21, 0), vec3(0, 0, 0), vec3(4, 4, 1), "Box", "Clean Sawblade Material");
            ((SawBladeObject*)m_pGameObjects["Sawblade Right"])->CreateBody(0);
            ((SawBladeObject*)m_pGameObjects["Sawblade Right"])->AddCircle(1, false, 0, 0, 4, Category_Sawblade, Category_MeatBoy);
            ((SawBladeObject*)m_pGameObjects["Sawblade Right"])->SetRenderOrder(0);
            ((SawBladeObject*)m_pGameObjects["Sawblade Right"])->GetBody()->SetActive(true);

            m_pGameObjects["Sawblade Left"] = new SawBladeObject(this, "Sawblade Left", vec3(7, 21, 0), vec3(0, 0, 0), vec3(4, 4, 1), "Box", "Clean Sawblade Material");
            ((SawBladeObject*)m_pGameObjects["Sawblade Left"])->CreateBody(0);
            ((SawBladeObject*)m_pGameObjects["Sawblade Left"])->AddCircle(1, false, 0, 0, 4, Category_Sawblade, Category_MeatBoy);
            ((SawBladeObject*)m_pGameObjects["Sawblade Left"])->SetRenderOrder(0);
            ((SawBladeObject*)m_pGameObjects["Sawblade Left"])->GetBody()->SetActive(true);

            m_pGameObjects["Wall Ground"] = new GameObject(this, "Wall Ground", vec3(0, 0, 0), vec3(0, 0, 0), vec3(6, 1, 1), "Box", "Ground Material");
            m_pGameObjects["Wall Ground"]->CreateBody(1);
            m_pGameObjects["Wall Ground"]->AddBox(6, 1, 1, false, 0, 0, Category_Ground, Category_MeatBoy | Category_Missile | Category_BandageGirl | Category_Sawblade);
            m_pGameObjects["Wall Ground"]->GetBody()->SetActive(true);

            m_pGameObjects["Wall Under Bandage Girl"] = new GameObject(this, "Wall Under Bandage Girl", vec3(0, 25, 0), vec3(0, 0, 0), vec3(6, 1, 1), "Box", "Ground Material");
            m_pGameObjects["Wall Under Bandage Girl"]->CreateBody(1);
            m_pGameObjects["Wall Under Bandage Girl"]->AddBox(6, 1, 1, false, 0, 0, Category_Ground, Category_MeatBoy | Category_Missile | Category_BandageGirl | Category_BloodChunk);
            m_pGameObjects["Wall Under Bandage Girl"]->GetBody()->SetActive(true);

            m_pGameObjects["Wall Platform Left"] = new GameObject(this, "Wall Platform Left", vec3(-4, 20, 0), vec3(0, 0, 0), vec3(3, 1, 1), "Box", "Ground Material");
            m_pGameObjects["Wall Platform Left"]->CreateBody(1);
            m_pGameObjects["Wall Platform Left"]->AddBox(3, 1, 1, false, 0, 0, Category_Ground, Category_MeatBoy | Category_Missile | Category_BandageGirl | Category_BloodChunk);
            m_pGameObjects["Wall Platform Left"]->GetBody()->SetActive(true);

            m_pGameObjects["Wall Platform Right"] = new GameObject(this, "Wall Platform Right", vec3(4, 20, 0), vec3(0, 0, 0), vec3(3, 1, 1), "Box", "Ground Material");
            m_pGameObjects["Wall Platform Right"]->CreateBody(1);
            m_pGameObjects["Wall Platform Right"]->AddBox(3, 1, 1, false, 0, 0, Category_Ground, Category_MeatBoy | Category_Missile | Category_BandageGirl | Category_BloodChunk);
            m_pGameObjects["Wall Platform Right"]->GetBody()->SetActive(true);

            m_pGameObjects["Wall Floating Left"] = new GameObject(this, "Wall Platform Left", vec3(-6, 24, 0), vec3(0, 0, 0), vec3(1, 3, 1), "Box", "Ground Material");
            m_pGameObjects["Wall Floating Left"]->CreateBody(1);
            m_pGameObjects["Wall Floating Left"]->AddBox(1, 3, 1, false, 0, 0, Category_Ground, Category_MeatBoy | Category_Missile | Category_BandageGirl | Category_BloodChunk);
            m_pGameObjects["Wall Floating Left"]->GetBody()->SetActive(true);

            m_pGameObjects["Wall Floating Right"] = new GameObject(this, "Wall Platform Right", vec3(6, 24, 0), vec3(0, 0, 0), vec3(1, 3, 1), "Box", "Ground Material");
            m_pGameObjects["Wall Floating Right"]->CreateBody(1);
            m_pGameObjects["Wall Floating Right"]->AddBox(1, 3, 1, false, 0, 0, Category_Ground, Category_MeatBoy | Category_Missile | Category_BandageGirl | Category_BloodChunk);
            m_pGameObjects["Wall Floating Right"]->GetBody()->SetActive(true);

            m_pGameObjects["Wall Left"] = new GameObject(this, "Wall Left", vec3(-3, 10, 0), vec3(0, 0, 0), vec3(1, 20, 1), "Box", "Ground Material");
            m_pGameObjects["Wall Left"]->CreateBody(1);
            m_pGameObjects["Wall Left"]->AddBox(1, 20, 1, false, 0, 0, Category_Ground, Category_MeatBoy | Category_Missile | Category_BandageGirl | Category_BloodChunk);
            m_pGameObjects["Wall Left"]->GetBody()->SetActive(true);

            m_pGameObjects["Wall Right"] = new GameObject(this, "Wall Right", vec3(3, 10, 0), vec3(0, 0, 0), vec3(1, 20, 1), "Box", "Ground Material");
            m_pGameObjects["Wall Right"]->CreateBody(1);
            m_pGameObjects["Wall Right"]->AddBox(1, 20, 1, false, 0, 0, Category_Ground, Category_MeatBoy | Category_Missile | Category_BandageGirl | Category_BloodChunk);
            m_pGameObjects["Wall Right"]->GetBody()->SetActive(true);

        }

        // add 50 sawblades to the pool
        for (int i = 0; i < 50; i++)
        {
            char sawbladename[50];
            sprintf_s(sawbladename, 50, "Sawblade%d", i);
            vec3 position = vec3(0.0f, 0.0f, 0.0f);
            ProjectileSawObject* pSawblade = new ProjectileSawObject(this, sawbladename, position, vec3(0, 0, 0), vec3(1.5f, 1.5f, 1), "Box", "Clean Sawblade Material");
            pSawblade->CreateBody(0);
            pSawblade->AddCircle(1.25, false, 0, 0, 1, Category_Sawblade, Category_Ground | Category_MeatBoy | Category_Wall);
            pSawblade->GetBody()->SetActive(false);
            pSawblade->SetRenderOrder(3);
            pSawblade->SetPool(&m_SawbladePool);
            m_SawbladePool.AddNewObjectToPool(pSawblade);

        }

        // creating a revolute joint within the sawblade launcher
        m_pGameObjects["Sawblade in Launcher"]->CreateRevoluteJoint(m_pGameObjects["Sawblade in Launcher"]->GetPosition().x, m_pGameObjects["Sawblade in Launcher"]->GetPosition().y,
            m_pGameObjects["Sawblade in Launcher"]->GetBody(), m_pWorld->GetGround(), true, 10, 7, false, 0, 0, false, 0, 0);

        // joints for the sawblades on the sides
        m_pGameObjects["Sawblade Right"]->CreateRevoluteJoint(m_pGameObjects["Sawblade Right"]->GetPosition().x, m_pGameObjects["Sawblade Right"]->GetPosition().y,
            m_pGameObjects["Sawblade Right"]->GetBody(), m_pWorld->GetGround(), true, 10, 7, false, 0, 0, false, 0, 0);

        m_pGameObjects["Sawblade Left"]->CreateRevoluteJoint(m_pGameObjects["Sawblade Left"]->GetPosition().x, m_pGameObjects["Sawblade Left"]->GetPosition().y,
            m_pGameObjects["Sawblade Left"]->GetBody(), m_pWorld->GetGround(), true, 10, 7, false, 0, 0, false, 0, 0);

    }
}


void SecondLevelScene::Update(float deltatime)
{
    if (m_IsPaused == false)
    {

        




        Scene::Update(deltatime);
        m_pWorld->Update(deltatime);
        ((ScoreDisplay*)m_pGameObjects["Timer"])->Update(deltatime);



        // every 2 seconds the sawblade launcher will deploy a sawblade downwards towards Meat Boy
        if (m_SawbladeTimer > 0)
        {
            m_SawbladeTimer -= deltatime;

            if (m_SawbladeTimer <= 0)
            {
                m_pResources->GetSoundPlayer("Level1_SoundPlayer")->PlaySound(GetResourceManager()->GetSoundCueObject("Saw Launching")->PlaySound());
                ShootSawblade();
                m_SawbladeTimer = SAWBLADE_TIMER_DURATION;
            }
        }

        if (m_IsBeingRendered == true)
        {
            ((PlayerObject*)m_pGameObjects["Meat Boy"])->DisableController();
        }
        else
        {
            ((PlayerObject*)m_pGameObjects["Meat Boy"])->EnableController();
        }
    }
}

void SecondLevelScene::Draw()
{
    //((ScoreDisplay*)m_pGameObjects["Timer"])->Draw(1, ((CameraObject*)m_pGameObjects["Camera"])->GetPosition());

    
    m_pSkyBox->Draw(((CameraObject*)m_pGameObjects["Camera"])->GetPosition());

   

    Scene::Draw();

    ((ScoreDisplay*)m_pGameObjects["Timer"])->Draw(1, m_pGameObjects["Camera"]->GetPosition());

}


void SecondLevelScene::OnEvent(Event * pEvent)
{
    Scene::OnEvent(pEvent);

    if (pEvent->GetEventType() == EventType_RemoveFromPool)
    {
        RemoveFromPoolEvent* pRemoveEvent = (RemoveFromPoolEvent*)pEvent;

        GameObject* obj = pRemoveEvent->GetGameObject();

        obj->GetBody()->SetAngularVelocity(0);
        obj->GetBody()->SetLinearVelocity(b2Vec2(0, 0));
        obj->GetBody()->SetTransform(b2Vec2(m_pGameObjects["Sawblade Launcher"]->GetPosition().x, m_pGameObjects["Sawblade Launcher"]->GetPosition().y), 0);
        obj->GetBody()->SetActive(true);

        ((ProjectileSawObject*)pRemoveEvent->GetGameObject())->GetPool()->ReturnObject(obj);

        obj->RemoveFromSceneWithPool();

    }
    if (pEvent->GetEventType() == EventType_RemoveFromScene)
    {
        RemoveFromSceneEvent* pRemoveEvent = (RemoveFromSceneEvent*)pEvent;

        GameObject* obj = pRemoveEvent->GetGameObject();

        obj->GetBody()->SetActive(false);
        obj->GetBody()->SetAngularVelocity(0);
        obj->GetBody()->SetLinearVelocity(b2Vec2(0, 0));




        obj->RemoveFromScene();

    }
    if (pEvent->GetEventType() == EventType_BandageCollected)
    {
        BandageCollectedEvent* pRemoveEvent = (BandageCollectedEvent*)pEvent;

        SetBandageIsCollected(true);


        RemoveFromSceneEvent* pEvent2 = new RemoveFromSceneEvent(m_pGameObjects["Bandage Pickup"]);
        GetGame()->QueueEvent(pEvent2);





    }
   

    if (pEvent->GetEventType() == EventType_Input)
    {
        InputEvent* pInputEvent = (InputEvent*)pEvent;
        if (pInputEvent->GetInputDeviceType() == InputDeviceType_Keyboard) // logic for pausing
        {
            if (pInputEvent->GetInputState() == InputState_Pressed)
            {
                

                if (pInputEvent->GetID() == 'R') //setting the debugging modes for the camera's rotation
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

               if (pInputEvent->GetID() == 'M') //setting the debugging modes for the camera's rotation
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
                
            }
            if (pInputEvent->GetInputState() == InputState_Released)
            {
                if (m_IsPaused == false)
                {



                    if (pInputEvent->GetID() == 'P')
                    {
                        Scene* scene = GetGame()->GetSceneManager()->GetScene("Pause");
                        PushSceneEvent* Event = new PushSceneEvent(scene);
                        GetGame()->QueueEvent(Event);
                        m_IsPaused = true;
                    }
                }
            }
        }
    }

    if (pEvent->GetEventType() == EventType_LevelWon)
    {
        SetIsBeaten(true);

        ((PlayerObject*)m_pGameObjects["Meat Boy"])->GetBody()->SetTransform(b2Vec2(MEAT_BOY_STARTING_POINT.x, MEAT_BOY_STARTING_POINT.y), 0);
        PopBackEvent* pEvent2 = new PopBackEvent(this);
        GetGame()->QueueEvent(pEvent2);

        Scene* pScene = this->GetGame()->GetSceneManager()->GetScene("Level Select");
        PushSceneEvent* pEvent = new PushSceneEvent(pScene);
        GetGame()->QueueEvent(pEvent);

        
        
    }
    if (pEvent->GetEventType() == EventType_BandageCollected)
    {
        SetBandageIsCollected(true);
    }
    if (pEvent->GetEventType() == EventType_UnPause)
    {
        m_IsPaused = false;



    }
}

void SecondLevelScene::ShootSawblade()
{

    GameObject* obj = m_SawbladePool.GetObjectFromPool();
    std::string objName = obj->GetName();
    obj->AddToScene(this);
    m_pGameObjects[objName]->GetBody()->SetActive(true);
    m_pGameObjects[objName]->GetBody()->SetTransform(b2Vec2(m_pGameObjects["Sawblade Launcher"]->GetPosition().x, m_pGameObjects["Sawblade Launcher"]->GetPosition().y), 0);
    

    //m_pResources->GetSoundPlayer("Level1_SoundPlayer")->PlaySound(m_pResources->GetSoundObject("Shoot"));
    m_pGameObjects[objName]->GetBody()->ApplyLinearImpulseToCenter(b2Vec2(0, -5), true);
}




