#include "GamePCH.h"



BandageGirlObject::BandageGirlObject(Scene* pScene, std::string name, vec3 pos, vec3 rot, vec3 scale, Mesh* pMesh, Material* a_Material)
	: GameObject(pScene, name, pos, rot, scale, pMesh, a_Material)
{
	
}

BandageGirlObject::BandageGirlObject(Scene* pScene, std::string name, vec3 pos, vec3 rot, vec3 scale, std::string meshname, std::string a_Material)
	: GameObject(pScene, name, pos, rot, scale, meshname, a_Material)
{

}
BandageGirlObject::~BandageGirlObject()
{
}



void BandageGirlObject::Update(float deltatime)
{
	GameObject::Update(deltatime);

        
    
}

void BandageGirlObject::BeginContact(b2Fixture * pOtherFixture, vec2 worldPosition, vec2 worldNormal)
{
	GameObject::BeginContact(pOtherFixture, worldPosition, worldNormal);

	GameObject* Obj = (GameObject*)pOtherFixture->GetBody()->GetUserData();

	std::string Name = ((PlayerObject*)Obj)->GetName();

	if (Name.compare("Meat Boy") == 0)
	{
        SetIsSaved(true);
        LevelWonEvent* Event = new LevelWonEvent(m_pScene);
        m_pScene->GetGame()->QueueEvent(Event);
	}

	
}

void BandageGirlObject::EndContact(b2Fixture * pOtherFixture)
{
}

void BandageGirlObject::SetIsSaved(bool saved)
{
    m_IsSaved = saved;
}

bool BandageGirlObject::GetIsSaved()
{
    return m_IsSaved;
}
