#include "GamePCH.h"

const vec3 MEAT_BOY_STARTING_POINT = vec3(3, 0, 0);
const float MISSILE_TIMER_DURATION = 0.8f;

SampleScene::SampleScene(Game* pGame, ResourceManager* pResources, std::string name)
: Scene( pGame, pResources, name )
{
    m_MissileTimer = MISSILE_TIMER_DURATION;
}

SampleScene::~SampleScene()
{
}

void SampleScene::OnSurfaceChanged(unsigned int width, unsigned int height)
{
    Scene::OnSurfaceChanged( width, height );
}


void SampleScene::LoadContent()
{
    Scene::LoadContent();
    m_pWorld = new World(b2Vec2(0, -9.8f));


    {         
        m_pContactListener = new ContactListener();
        m_pWorld->GetPhysicsWorld()->SetContactListener(m_pContactListener);
       m_pSkyBox = new SkyBox(this, "SkyBox", vec3(0, 0, 0), vec3(0,0,0), vec3(1,1,1), "SkyBox", "CubeMap_Mat");

          // Camera
        m_pGameObjects["Camera"] = new CameraObject( this, "Camera", vec3(0,0,0), vec3(0,0,0), vec3(1,1,1) );
        ((CameraObject*)m_pGameObjects["Camera"])->SetCameraDistance(17);

        // Score Display
        m_pGameObjects["Timer"] = new ScoreDisplay(this, "Timer",
            vec3(0, -4, 0), vec3(0, 0, 0), vec3(1, 1, 1),
            m_pResources->GetMesh("Box"), m_pResources->GetMaterial("Timer Numbers Material"));
        m_pGameObjects["Timer"]->SetRenderOrder(1);

        AddLight(vec3(0, 1, 0), vec4(0, 0, 1, 1));
        AddLight(vec3(0, 0, 1), vec4(1, 0, 0, 1));
        AddLight(vec3(0, 0, 1), vec4(1, 0, 0, 1));
        
        


        // Creating Game Objects
        {
            // as of now when it is a player object it is not affected by gravity. 
            m_pGameObjects["Meat Boy"] = new PlayerObject(this, "Meat Boy", MEAT_BOY_STARTING_POINT, vec3(0,0,0), vec3(1,1,1), "Box","Meat Boy Material");
            ((PlayerObject*)m_pGameObjects["Meat Boy"])->SetController(m_pGame->GetController(0));
            vec3 playerPosition = ((PlayerObject*)m_pGameObjects["Meat Boy"])->GetPosition();
            ((PlayerObject*)m_pGameObjects["Meat Boy"])->CreateBody(0);
            ((PlayerObject*)m_pGameObjects["Meat Boy"])->GetBody()->SetFixedRotation(true);
            ((PlayerObject*)m_pGameObjects["Meat Boy"])->AddBox(0.5f, 0.5f, 1.0, false, 0.6f, 0, Category_MeatBoy, Category_Sawblade | Category_Ground | Category_Missile | Category_Wall | Category_BandageGirl | Category_BandagePickup);
            ((PlayerObject*)m_pGameObjects["Meat Boy"])->GetBody()->SetActive(true);

            ((PlayerObject*)m_pGameObjects["Meat Boy"])->SetRespawnPosition(MEAT_BOY_STARTING_POINT);

            ((CameraObject*)m_pGameObjects["Camera"])->SetFocusObject(m_pGameObjects["Meat Boy"]);

            

            //--------------------------------Sawblades

            m_pGameObjects["Sawblade"] = new SawBladeObject(this, "Sawblade", vec3(0, 0, 0), vec3(0, 0, 0), vec3(4, 4, 1), "Box", "Clean Sawblade Material");
            ((SawBladeObject*)m_pGameObjects["Sawblade"])->CreateBody(0);
			((SawBladeObject*)m_pGameObjects["Sawblade"])->AddCircle( 1, false, 0, 0, 4, Category_Sawblade, Category_MeatBoy);
            ((SawBladeObject*)m_pGameObjects["Sawblade"])->SetRenderOrder(0);
            ((SawBladeObject*)m_pGameObjects["Sawblade"])->GetBody()->SetActive(true);

            m_pGameObjects["Sawblade Bottom"] = new SawBladeObject(this, "Sawblade Bottom", vec3(-2, 8, 0), vec3(0, 0, 0), vec3(4, 4, 1), "Box", "Clean Sawblade Material");
            ((SawBladeObject*)m_pGameObjects["Sawblade Bottom"])->CreateBody(0);
            ((SawBladeObject*)m_pGameObjects["Sawblade Bottom"])->AddCircle(1, false, 0, 0, 4, Category_Sawblade, Category_MeatBoy);
            ((SawBladeObject*)m_pGameObjects["Sawblade Bottom"])->SetRenderOrder(0);
            ((SawBladeObject*)m_pGameObjects["Sawblade Bottom"])->GetBody()->SetActive(true);

            m_pGameObjects["Sawblade Pit"] = new SawBladeObject(this, "Sawblade Pit", vec3(8, 0, 0), vec3(0, 0, 0), vec3(3.5, 3.5, 1), "Box", "Clean Sawblade Material");
            ((SawBladeObject*)m_pGameObjects["Sawblade Pit"])->CreateBody(0);
            ((SawBladeObject*)m_pGameObjects["Sawblade Pit"])->AddCircle(1, false, 0, 0, 4, Category_Sawblade, Category_MeatBoy);
            ((SawBladeObject*)m_pGameObjects["Sawblade Pit"])->SetRenderOrder(0);
            ((SawBladeObject*)m_pGameObjects["Sawblade Pit"])->GetBody()->SetActive(true);

            m_pGameObjects["Bandage Girl 1"] = new BandageGirlObject(this, "Bandage Girl 1", vec3(-3, -0.15f, 0), vec3(0, 0, 0), vec3(1, 1, 1), "Box", "Bandage Girl Material");
            ((BandageGirlObject*)m_pGameObjects["Bandage Girl 1"])->CreateBody(1);
            ((BandageGirlObject*)m_pGameObjects["Bandage Girl 1"])->GetBody()->SetFixedRotation(true);
            ((BandageGirlObject*)m_pGameObjects["Bandage Girl 1"])->AddBox(1, 1, 1.0, false, 0.6f, 0, Category_BandageGirl, Category_Ground | Category_MeatBoy);
            ((BandageGirlObject*)m_pGameObjects["Bandage Girl 1"])->GetBody()->SetActive(true);

            m_pGameObjects["Turret"] = new TurretObject(this, "Turret", vec3(-10, 11.5, 0), vec3(0, 0, 0), vec3(2.5, 1, 1), "Box", "Turret Material");
            ((TurretObject*)m_pGameObjects["Turret"])->CreateBody(1);
            ((TurretObject*)m_pGameObjects["Turret"])->AddCircle(1, false, 0, 0, 4, Category_Turret, Category_Sawblade | Category_Ground |  Category_Wall);
            ((TurretObject*)m_pGameObjects["Turret"])->GetBody()->SetActive(true);

            m_pGameObjects["Bandage Pickup"] = new BandagePickupObject(this, "Bandage Pickup", vec3(8, 6, 0), vec3(0, 0, 0), vec3(0.75, 0.75, 1), "Box", "Bandage Pickup Material");
            ((BandagePickupObject*)m_pGameObjects["Bandage Pickup"])->CreateBody(1);
            ((BandagePickupObject*)m_pGameObjects["Bandage Pickup"])->AddBox(0.75, 0.75, 0, false, 0, 0, Category_BandagePickup, Category_MeatBoy);
            ((BandagePickupObject*)m_pGameObjects["Bandage Pickup"])->SetRenderOrder(1);
            ((BandagePickupObject*)m_pGameObjects["Bandage Pickup"])->GetBody()->SetActive(true);


           // m_pGameObjects["Cube"] = new GameObject(this, "Cube", vec3(0, 0, 0), vec3(0, 0, 0), vec3(1, 1, 1), "Cube", "CubeMap_Mat");

            // Environment

			m_pGameObjects["Ground"] = new GameObject(this, "Ground", vec3(-1,-0.75,0), vec3(0,0,0), vec3(1, 0.25, 0.25), "Platform", "Ground Material");
			m_pGameObjects["Ground"]->CreateBody(1);
			m_pGameObjects["Ground"]->AddBox(8, 1, 1, false, 0.2f, 0, Category_Ground, Category_MeatBoy | Category_Missile | Category_BloodChunk);
			m_pGameObjects["Ground"]->SetRenderOrder(4);
            m_pGameObjects["Ground"]->GetBody()->SetActive(true);

            m_pGameObjects["Ground with Saw"] = new GameObject(this, "Ground with Saw", vec3(-2, 8, 0), vec3(0, 0, 0), vec3(1, 0.25, 0.25), "Platform", "Ground Material");
            m_pGameObjects["Ground with Saw"]->CreateBody(1);
            m_pGameObjects["Ground with Saw"]->AddBox(8, 1, 1, false, 0.2f, 0, Category_Ground, Category_MeatBoy | Category_Missile | Category_BloodChunk);
            m_pGameObjects["Ground with Saw"]->SetRenderOrder(4);
            m_pGameObjects["Ground with Saw"]->GetBody()->SetActive(true);

            m_pGameObjects["Ground with Ceiling Saw"] = new GameObject(this, "Ground with Ceiling Saw", vec3(-1, -3.75, 0), vec3(0, 0, 0), vec3(1, 0.25, 0.25), "Platform", "Ground Material");
            m_pGameObjects["Ground with Ceiling Saw"]->CreateBody(1);
            m_pGameObjects["Ground with Ceiling Saw"]->AddBox(8, 1, 1, false, 0.2f, 0, Category_Ground, Category_MeatBoy | Category_Missile | Category_BloodChunk);
            m_pGameObjects["Ground with Ceiling Saw"]->SetRenderOrder(4);
            m_pGameObjects["Ground with Ceiling Saw"]->GetBody()->SetActive(true);

            m_pGameObjects["Wall"] = new GameObject(this, "Wall", vec3(6, 4, 0), vec3(0, 0, 90), vec3(1, 0.25, 0.25), "Platform", "Ground Material");
            m_pGameObjects["Wall"]->CreateBody(1);
            m_pGameObjects["Wall"]->AddBox(8, 1, 1, false, 0.2f, 0, Category_Ground, Category_MeatBoy | Category_Missile | Category_BloodChunk);
            m_pGameObjects["Wall"]->SetRenderOrder(4);
            m_pGameObjects["Wall"]->GetBody()->SetActive(true);

            m_pGameObjects["Wall Bandage"] = new GameObject(this, "Wall Bandage", vec3(10, 4, 0), vec3(0, 0, 90), vec3(1, 0.25, 0.25), "Platform", "Ground Material");
            m_pGameObjects["Wall Bandage"]->CreateBody(1);
            m_pGameObjects["Wall Bandage"]->AddBox(8, 1, 1, false, 0.2f, 0, Category_Ground, Category_MeatBoy | Category_Missile | Category_BloodChunk);
            m_pGameObjects["Wall Bandage"]->SetRenderOrder(4);
            m_pGameObjects["Wall Bandage"]->GetBody()->SetActive(true);

            m_pGameObjects["Wall Temp "] = new GameObject(this, "Wall Temp", vec3(1, 4.5, 0), vec3(0, 0, 90), vec3(0.75, 0.25, 0.25), "Platform", "Ground Material");
            m_pGameObjects["Wall Temp "]->CreateBody(1);
            m_pGameObjects["Wall Temp "]->AddBox(8, 1, 1, false, 0.2f, 0, Category_Ground, Category_MeatBoy | Category_Missile | Category_BloodChunk);
            m_pGameObjects["Wall Temp "]->SetRenderOrder(4);
            m_pGameObjects["Wall Temp "]->GetBody()->SetActive(true);

            m_pGameObjects["ReflectTest"] = new GameObject(this, "ReflectTest", vec3(1, -15, 0), vec3(0, 0, 0), vec3(0.25f, 0.25f, 0.25f), "Sphere", "Reflect_Mat");

     

			// add 20 missiles to the pool
			for (int i = 0; i < 20; i++)
			{
				char missilename[50];
				sprintf_s(missilename, 50, "Missile%d", i);
				vec3 position = vec3(0.0f, 0.0f, 0.0f);
				MissileObject* pMissile = new MissileObject(this, missilename, position, vec3(0, 0, 0), vec3(1.5, 0.75, 1), "Box", "Missile Material");
                pMissile->CreateBody(0);
                pMissile->AddBox(1,1, 1.0, false, 0, 0, Category_Missile, Category_Sawblade | Category_Ground | Category_MeatBoy | Category_Wall);
                pMissile->GetBody()->SetActive(false);
				pMissile->SetRenderOrder(3);
				pMissile->SetPool(&m_MissilePool);
				m_MissilePool.AddNewObjectToPool(pMissile);

			}

        }

        // Creating joints
        m_pGameObjects["Sawblade"]->CreateRevoluteJoint(m_pGameObjects["Sawblade"]->GetPosition().x, m_pGameObjects["Sawblade"]->GetPosition().y,
            m_pGameObjects["Sawblade"]->GetBody(), m_pWorld->GetGround(), true, 10, 7, false, 0, 0, false, 0, 0 );

        m_pGameObjects["Sawblade Pit"]->CreateRevoluteJoint(m_pGameObjects["Sawblade Pit"]->GetPosition().x, m_pGameObjects["Sawblade Pit"]->GetPosition().y,
            m_pGameObjects["Sawblade Pit"]->GetBody(), m_pWorld->GetGround(), true, 10, 7, false, 0, 0, false, 0, 0);

        m_pGameObjects["Sawblade Bottom"]->CreateRevoluteJoint(m_pGameObjects["Sawblade Bottom"]->GetPosition().x, m_pGameObjects["Sawblade Bottom"]->GetPosition().y,
            m_pGameObjects["Sawblade Bottom"]->GetBody(), m_pWorld->GetGround(), true, 10, 7, false, 0, 0, false, 0, 0);

    }

}


void SampleScene::Update(float deltatime)
{

    if (m_IsPaused == false)
    {

        Scene::Update(deltatime);
        m_pWorld->Update(deltatime);



 
        ((ScoreDisplay*)m_pGameObjects["Timer"])->Update(deltatime);

        if (m_IsBeingRendered == true)
        {
            ((PlayerObject*)m_pGameObjects["Meat Boy"])->DisableController();
        }
        else
        {
            ((PlayerObject*)m_pGameObjects["Meat Boy"])->EnableController();
        }





        // every frame pass in Meat Boy's position so the angle between the turret and Meat Boy can be calculated
        ((TurretObject*)m_pGameObjects["Turret"])->SetAngleBetweenMeatBoy(m_pGameObjects["Meat Boy"]->GetPosition());

        // setting up ray casting functionality for turret objects
        RayCastResultCallback turretResult;
        b2Vec2 turretRayA = b2Vec2(m_pGameObjects["Turret"]->GetPosition().x, m_pGameObjects["Turret"]->GetPosition().y);
        b2Vec2 turretRayB = b2Vec2(m_pGameObjects["Turret"]->GetPosition().x + 15, m_pGameObjects["Turret"]->GetPosition().y);

        m_pWorld->GetPhysicsWorld()->RayCast(&turretResult, turretRayA, turretRayB);


        // TURRET LOGIC

        {
            // when the ray of the turret collides with Meat Boy a method that fires a missile will be triggered
            if (turretResult.m_Hit == true)
            {
                GameObject* meat = (GameObject*)turretResult.m_pBody->GetUserData();

                // if the dynamic object that collides with the ray is Meat Boy
                if (meat->GetName().compare("Meat Boy") == 0)
                {
                    m_SeenByTurret = true;
                    ((TurretObject*)m_pGameObjects["Turret"])->SetState(true);
                }
            }


            if (m_SeenByTurret == true) // if Meat Boy is seen a missile is fired after 0.4 seconds
            {
                m_MissileTimer -= deltatime;

                if (m_MissileTimer <= 0)
                {
                    SpawnMissile();
                    m_MissileTimer = MISSILE_TIMER_DURATION;
                    m_SeenByTurret = false;
                    ((TurretObject*)m_pGameObjects["Turret"])->SetState(false);
                }
            }
        }



    }
    

    
}

void SampleScene::Draw()
{
    //((ScoreDisplay*)m_pGameObjects["Timer"])->Draw(1, ((CameraObject*)m_pGameObjects["Camera"])->GetPosition());

    
    m_pSkyBox->Draw(((CameraObject*)m_pGameObjects["Camera"])->GetPosition());

   

    Scene::Draw();

    ((ScoreDisplay*)m_pGameObjects["Timer"])->Draw(1, m_pGameObjects["Camera"]->GetPosition());

}



void SampleScene::SetBandageIsCollected(bool collected)
{
    m_IsBandageCollected = collected;
}

bool SampleScene::GetBandageIsCollected()
{
    return m_IsBandageCollected;
}

void SampleScene::SpawnBloodChunks(vec3 spawnpos, unsigned int numchunks)
{

    GameObject* pGameObject = m_BloodChunkPool.GetObjectFromPool();

    GameObject* obj = m_BloodChunkPool.GetObjectFromPool();
    std::string objName = obj->GetName();

    float pos = randFromNegativeOneToOne() * 5.0f;
    pGameObject->AddToScene(this);

    // apply a linear impulse in a random direction
    ((BloodChunkObject*)m_pGameObjects[objName])->GetBody()->SetActive(true);
    ((BloodChunkObject*)m_pGameObjects[objName])->GetBody()->ApplyLinearImpulse(b2Vec2(pos *-1, 5), b2Vec2(spawnpos.x, spawnpos.y), true);
    ((BloodChunkObject*)m_pGameObjects[objName])->GetBody()->SetAngularVelocity(180.0);
    pGameObject->SetPosition(spawnpos);

}

void SampleScene::SpawnMissile()
{
    vec3 dVector = (m_pGameObjects["Meat Boy"]->GetPosition().x - m_pGameObjects["Turret"]->GetPosition().x,
                    m_pGameObjects["Meat Boy"]->GetPosition().y - m_pGameObjects["Turret"]->GetPosition().y,
                    m_pGameObjects["Meat Boy"]->GetPosition().z - m_pGameObjects["Turret"]->GetPosition().z);
    
    GameObject* obj = m_MissilePool.GetObjectFromPool();
    std::string objName = obj->GetName();
    obj->AddToScene(this);
    m_pGameObjects[objName]->GetBody()->SetActive(true);
    m_pGameObjects[objName]->GetBody()->SetTransform(b2Vec2(m_pGameObjects["Turret"]->GetPosition().x, m_pGameObjects["Turret"]->GetPosition().y), 0);
    m_pGameObjects[objName]->SetRotation(vec3(0, 0, m_pGameObjects["Turret"]->GetRotation().z));
    ((MissileObject*)m_pGameObjects[objName])->SetHasFired(true);
	m_pResources->GetSoundPlayer("Level1_SoundPlayer")->PlaySound(m_pResources->GetSoundObject("Shoot"));
    m_pGameObjects[objName]->GetBody()->SetLinearVelocity(b2Vec2(50, 0));
    //applying an impulse to the missiles
}

void SampleScene::OnEvent(Event * pEvent)
{
    Scene::OnEvent(pEvent);

    if (pEvent->GetEventType() == EventType_RemoveFromPool)
    {
        RemoveFromPoolEvent* pRemoveEvent = (RemoveFromPoolEvent*)pEvent;

        GameObject* obj = pRemoveEvent->GetGameObject();

        obj->GetBody()->SetActive(true);
        obj->GetBody()->SetAngularVelocity(0);
        obj->GetBody()->SetLinearVelocity(b2Vec2(0, 0));

        ((MissileObject*)pRemoveEvent->GetGameObject())->GetPool()->ReturnObject(obj);


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

  
        if (pEvent->GetEventType() == EventType_LevelWon)
        {
            SetIsBeaten(true);

            ((PlayerObject*)m_pGameObjects["Meat Boy"])->GetBody()->SetTransform(b2Vec2(MEAT_BOY_STARTING_POINT.x, MEAT_BOY_STARTING_POINT.y),0);
            PopBackEvent* pEvent2 = new PopBackEvent(this);
            GetGame()->QueueEvent(pEvent2);

            Scene* pScene = this->GetGame()->GetSceneManager()->GetScene("Level Select");
            PushSceneEvent* pEvent = new PushSceneEvent(pScene);
            GetGame()->QueueEvent(pEvent);
            
        }

        if (pEvent->GetEventType() == EventType_UnPause)
        {
            m_IsPaused = false;


          
        }
    


    if (pEvent->GetEventType() == EventType_Input)
    {
        InputEvent* pInputEvent = (InputEvent*)pEvent;
        if (pInputEvent->GetInputDeviceType() == InputDeviceType_Keyboard) // logic for pausing
        {
           
            
                if (pInputEvent->GetInputState() == InputState_Pressed)
                {
                    
                    if (pInputEvent->GetID() == 'H')
                    {
                        debug = true;
                    }


                    else if (pInputEvent->GetID() == 'M') // setting the debugging modes for Meat Boy's stats
                    {
                        if (m_MIsPressed == false)
                        {
                            ((PlayerObject*)m_pGameObjects["Meat Boy"])->SetFirstDebugMode(true);
                            m_MIsPressed = true;
                        }
                        else if (m_MIsPressed == true)
                        {
                            ((PlayerObject*)m_pGameObjects["Meat Boy"])->SetFirstDebugMode(false);
                            m_MIsPressed = false;
                        }
                    }

                    else if (pInputEvent->GetID() == 'R') //setting the debugging modes for the camera's rotation
                    {
                        if (m_RIsPressed == false)
                        {
                            ((CameraObject*)m_pGameObjects["Camera"])->SetFirstDebugMode(true);
                            m_RIsPressed = true;
                        }
                        else if (m_RIsPressed == true)
                        {
                            ((CameraObject*)m_pGameObjects["Camera"])->SetFirstDebugMode(false);
                            m_RIsPressed = false;
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

}
