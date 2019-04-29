#include "GamePCH.h"



PlayerObject::PlayerObject(Scene* pScene, std::string name, vec3 pos, vec3 rot, vec3 scale, Mesh* pMesh, Material* a_Material)
: GameObject( pScene, name, pos, rot, scale, pMesh, a_Material)
,m_BloodPool()
{
    m_pController = 0;
	InitPool(pScene);
	m_Placed = false;
    m_Killed = false;
    m_DeathTimer = DEATH_TIMER_DURATION;
    m_jumpStrength = 1.85f;
}

PlayerObject::PlayerObject(Scene* pScene, std::string name, vec3 pos, vec3 rot, vec3 scale, std::string meshname, std::string a_Material)
: GameObject( pScene, name, pos, rot, scale, meshname, a_Material)
{
    m_pController = 0;
	InitPool(pScene);
	m_Placed = false;
    m_Killed = false;
    m_jumpStrength = 1.85f;
}

PlayerObject::~PlayerObject()
{
}

void PlayerObject::SetController(PlayerController* pController)
{
    m_pController = pController;
}

void PlayerObject::Update(float deltatime)
{
    if (m_PressedM1 == true)
    {
        ImGui::Begin("Meat Boy Methods Level 1");
        ImGui::SliderFloat("JumpStrength", &m_jumpStrength, 0, 5, "%.2f");
        ImGui::Checkbox("Kill", &m_Killed);
        ImGui::Checkbox("Skip to Goal", &m_Skipped1);
        ImGui::End(); // debugging related to handling Meat Boy
    }

    if (m_PressedM2 == true)
    {
        ImGui::Begin("Meat Boy Methods Level 2");
        ImGui::SliderFloat("JumpStrength", &m_jumpStrength, 0, 5, "%.2f");
        ImGui::Checkbox("Kill", &m_Killed);
        ImGui::Checkbox("Skip to Goal", &m_Skipped2);
        ImGui::End(); // debugging related to handling Meat Boy
    }


    if( m_pController == 0 )
        return;

    if (m_Position.y <= -15 || m_Position.x >= 15 || m_Position.x <=-15) // if Meat Boy falls to his death set him to killed
    {
        m_Killed = true;
    }

    if (m_Killed == true) 
    {
        m_pBody->SetTransform(b2Vec2(-1000, -1000), 0); // port Meat Boy to a random unreachable location when he dies 
        m_DeathTimer -= deltatime;                      // before quickly respawning at the starting point
        if (m_DeathTimer <= 0)
        {
            KillMeatBoy(); 
        }   
    }


    // if the player uses the 'skip' debug option it will jump to the end of the level so they don't have to play through all of it. 
    if (m_Skipped1 == true)
    {
        m_pBody->SetTransform(b2Vec2(MEAT_BOY_SKIPPING_POINT1.x, MEAT_BOY_SKIPPING_POINT1.y), 0);
    }

    if (m_Skipped2 == true)
    {
        m_pBody->SetTransform(b2Vec2(MEAT_BOY_SKIPPING_POINT2.x, MEAT_BOY_SKIPPING_POINT2.y), 0);
    }




    if (m_Saved == true)
    {
        //m_pScene->GetGame()->GetSceneManager()->PopScene();
        //m_pScene->GetGame()->GetSceneManager()->PushScene("Level Select");


        Scene* pScene = m_pScene->GetGame()->GetSceneManager()->GetScene("Level Select");
        PopBackEvent* pEvent2 = new PopBackEvent(pScene);
        m_pScene->GetGame()->QueueEvent(pEvent2);


        PushSceneEvent* pEvent = new PushSceneEvent(pScene);
        m_pScene->GetGame()->QueueEvent(pEvent);
    }

    GameObject::Update( deltatime );

    
    vec3 dir(0, 0, 0);
    if(m_ControllerDisabled != true)
    {
        if (m_pController->IsButtonPressed(PCB_Left))
        {
            dir.x -= 1;
            m_IsRunning = true;
        }
        else
        {
            m_IsRunning = false;
        }
            

            if (m_pController->IsButtonPressed(PCB_Right))
            {
                dir.x += 1;
                m_IsRunning = true;
            }
            else
            {
                m_IsRunning = false;
            }

        dir.Normalize();

        float speed = 100;
        //Then replace that entire line with m_pBody->ApplyForce(b2Vec2(formula that you erased.x, formula that you erased.y)

        m_pBody->ApplyForce(b2Vec2((dir * speed * deltatime).x, (dir * speed * deltatime).y), b2Vec2(m_Position.x, m_Position.y), true);
        if (m_pController->IsButtonPressed(PCB_Spacebar) && m_Jump == true)
        {
            m_pBody->ApplyLinearImpulseToCenter(b2Vec2(0, 2), true);
            m_Jump = false;
            m_wallJump = false;
            m_pScene->GetResourceManager()->GetSoundPlayer("Level1_SoundPlayer")->PlaySound(m_pScene->GetResourceManager()->GetSoundCueObject("Jumping")->PlaySound());
        }

        if (m_pController->IsButtonPressed(PCB_Spacebar) && m_wallJump == true)
        {

            if (m_WallCollisionNormal.x >= 1)
            {
                dir.y += 1;
                m_pBody->ApplyLinearImpulseToCenter(b2Vec2(m_WallCollisionNormal.x * -1, dir.y * m_jumpStrength), true);
                m_Jump = false;
                m_wallJump = false;
                m_pScene->GetResourceManager()->GetSoundPlayer("Level1_SoundPlayer")->PlaySound(m_pScene->GetResourceManager()->GetSoundCueObject("Jumping")->PlaySound());
            }

            else if (m_WallCollisionNormal.x <= 1)
            {
                dir.y += 1;
                m_pBody->ApplyLinearImpulseToCenter(b2Vec2(m_WallCollisionNormal.x * -1, dir.y * m_jumpStrength), true);
                m_Jump = false;
                m_wallJump = false;
                m_pScene->GetResourceManager()->GetSoundPlayer("Level1_SoundPlayer")->PlaySound(m_pScene->GetResourceManager()->GetSoundCueObject("Jumping")->PlaySound());
            }

        }
    }


    if (m_IsRunning == true && m_Jump == true)
    {
        m_BloodChunkTimer += deltatime;
        if (m_BloodChunkTimer >= 0.5f)
        {
            SpawnBloodChunk(dir);
            m_BloodChunkTimer = 0;
        }

    }
}

void PlayerObject::BeginContact(b2Fixture * pOtherFixture, vec2 worldPosition, vec2 worldNormal)
{
	GameObject::BeginContact(pOtherFixture, worldPosition, worldNormal);

	GameObject* Obj = (GameObject*)pOtherFixture->GetBody()->GetUserData();

	std::string Name = Obj->GetName();

	if (Name.compare(0,6,"Ground") == 0)
	{
		m_Jump = true;
		if (m_Placed == false)
		{
			GameObject* pBloodtrail = m_BloodPool.GetObjectFromPool();
			pBloodtrail->AddToScene(m_pScene);
			std::string name = pBloodtrail->GetName();
			m_pScene->GetGameObject(name)->SetPosition(vec3(m_Position.x, m_Position.y - 0.5f, m_Position.z));
			m_pScene->GetGameObject(name)->SetRenderOrder(0);
			m_Placed = true;
		}
        return;
	}

    if (Name.compare(0, 4,"Wall") == 0)
    {
        m_wallJump = true;
        m_WallCollisionNormal = worldNormal ;
    }

    if (Name.compare(0, 8, "Sawblade") == 0) // kill Meat Boy if he comes in contact with sawblades or missiles
    {
        m_Killed = true;
        m_pScene->GetResourceManager()->GetSoundPlayer("Level1_SoundPlayer")->PlaySound(m_pScene->GetResourceManager()->GetSoundCueObject("Death")->PlaySound());
        //((SampleScene*)m_pScene)->SpawnBloodChunks(this->GetPosition(), 30);
    }
    
	if (Name.compare(0,7,"Missile") == 0)
	{
		m_Killed = true;   
        m_pScene->GetResourceManager()->GetSoundPlayer("Level1_SoundPlayer")->PlaySound(m_pScene->GetResourceManager()->GetSoundCueObject("Death")->PlaySound());
        //((SampleScene*)m_pScene)->SpawnBloodChunks(this->GetPosition(), 30);
	}
	
}

void PlayerObject::EndContact(b2Fixture * pOtherFixture)
{
	GameObject::EndContact(pOtherFixture);
}

void PlayerObject::ReturnBloodToPool(GameObject * obj)
{
	m_BloodPool.ReturnObject(obj);
}

void PlayerObject::KillMeatBoy()
{
   
    m_pBody->SetLinearVelocity(b2Vec2(0,0));
    m_pBody->SetTransform(b2Vec2(m_respawnPos.x, m_respawnPos.y), 0);
	m_Killed = false;
	m_DeathTimer = DEATH_TIMER_DURATION;
}

void PlayerObject::InitPool(Scene * scene)
{
	for (int i = 0; i<50; i++)
	{
		char tempstr[50];
		sprintf_s(tempstr, 50, "BloodTrail%d", i);
		BloodTrail* pTrail = new BloodTrail(scene, tempstr, vec3(-10000, -10000, 0), vec3(0, 0, 0), vec3(0.5f, 0.5f, 0.5f), "Box", "BloodTrail Material");
		pTrail->CreateBody(1);
		pTrail->AddBox(0.5f, 0.5f, 0, true, 0, 0, Category_BloodTrail, Category_Ground);
		pTrail->GetBody()->SetActive(false);
		pTrail->SetRenderOrder(0);
		

		m_BloodPool.AddNewObjectToPool(pTrail);
		pTrail->SetPool(&m_BloodPool);
	}

    for (int i = 0; i<50; i++)
    {


        char tempstr[50];
        sprintf_s(tempstr, 50, "BloodChunk%d", i);
        BloodChunkObject* pChunk = new BloodChunkObject(scene, tempstr, vec3(-10000, -10000, 0), vec3(0, 0, 0), vec3(1.0f, 1.0f, 1.0f), "Box", "BloodGib_Animation1_Mat");
        pChunk->CreateBody(0);
        pChunk->AddBox(0.5f, 0.5f, 0, false, 0, 0, Category_BloodChunk, Category_Ground);
        pChunk->GetBody()->SetActive(false);
        pChunk->SetRenderOrder(0);


        m_BloodGibPool.AddNewObjectToPool(pChunk);
        pChunk->SetPool(&m_BloodGibPool);
    }


}

vec3 PlayerObject::GetRespawnPosition()
{
    return m_respawnPos;
}

void PlayerObject::SetRespawnPosition(vec3 pos)
{
    m_respawnPos = pos;
}

void PlayerObject::SetFirstDebugMode(bool debug)
{
    m_PressedM1 = debug;
}

void PlayerObject::SetSecondDebugMode(bool debug)
{
    m_PressedM2 = debug;
}

void PlayerObject::SpawnBloodChunk(vec3 dir)
{
    GameObject* pGameObject = m_BloodGibPool.GetObjectFromPool();

    
    std::string objName = pGameObject->GetName();


    pGameObject->AddToScene(m_pScene);

    // apply a linear impulse in a random direction
    ((BloodChunkObject*)m_pScene->GetGameObject(objName))->GetBody()->SetTransform(b2Vec2(m_Position.x, m_Position.y), 0);
    ((BloodChunkObject*)m_pScene->GetGameObject(objName))->SetIsActivated(true);
    ((BloodChunkObject*)m_pScene->GetGameObject(objName))->GetBody()->SetActive(true);
    ((BloodChunkObject*)m_pScene->GetGameObject(objName))->GetBody()->ApplyLinearImpulseToCenter(b2Vec2(dir.x, 1.5f), true);
 
  
}

