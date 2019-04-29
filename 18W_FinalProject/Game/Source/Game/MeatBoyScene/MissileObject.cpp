#include "GamePCH.h"



MissileObject::MissileObject(Scene* pScene, std::string name, vec3 pos, vec3 rot, vec3 scale, Mesh* pMesh, Material* a_Material)
	: GameObject(pScene, name, pos, rot, scale, pMesh, a_Material)
{
    
    m_FireTimer = 0;
}

MissileObject::MissileObject(Scene* pScene, std::string name, vec3 pos, vec3 rot, vec3 scale, std::string meshname, std::string a_Material)
	: GameObject(pScene, name, pos, rot, scale, meshname, a_Material)
{
    
    m_FireTimer = 0;
}
MissileObject::~MissileObject()
{
}



void MissileObject::Update(float deltatime)
{
	GameObject::Update(deltatime);
    if (m_IsDestroyed == true)
    {
        
        RemoveFromPoolEvent* pEvent2 = new RemoveFromPoolEvent(this);
        m_pScene->GetGame()->QueueEvent(pEvent2);
        m_HasFired = false;
        m_FireTimer = 0;
        m_IsDestroyed = false;
    }

    if (m_HasFired == true)
    {
        m_FireTimer += deltatime;

        if (m_FireTimer >= 5.0f)
        {
            m_IsDestroyed = true;

        }
    }
}

void MissileObject::BeginContact(b2Fixture * pOtherFixture, vec2 worldPosition, vec2 worldNormal)
{
	GameObject::BeginContact(pOtherFixture, worldPosition, worldNormal);

	GameObject* Obj = (GameObject*)pOtherFixture->GetBody()->GetUserData();

	std::string Name = ((PlayerObject*)Obj)->GetName();

    m_IsDestroyed = true;

	
}

void MissileObject::EndContact(b2Fixture * pOtherFixture)
{
}

void MissileObject::SetPool(SimplePool<GameObject>* Pool)
{
    m_Pool = Pool;
}
