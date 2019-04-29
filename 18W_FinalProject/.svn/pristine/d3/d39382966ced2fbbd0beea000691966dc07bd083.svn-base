#include "GamePCH.h"



BandagePickupObject::BandagePickupObject(Scene* pScene, std::string name, vec3 pos, vec3 rot, vec3 scale, Mesh* pMesh, Material* a_Material)
	: GameObject(pScene, name, pos, rot, scale, pMesh, a_Material)
{
	
}

BandagePickupObject::BandagePickupObject(Scene* pScene, std::string name, vec3 pos, vec3 rot, vec3 scale, std::string meshname, std::string a_Material)
	: GameObject(pScene, name, pos, rot, scale, meshname, a_Material)
{

}
BandagePickupObject::~BandagePickupObject()
{
}



void BandagePickupObject::Update(float deltatime)
{
	GameObject::Update(deltatime);

    if (m_isCollected == true)
    {
        BandageCollectedEvent* pEvent2 = new BandageCollectedEvent(m_pScene);
        m_pScene->GetGame()->QueueEvent(pEvent2);
    }
}

void BandagePickupObject::BeginContact(b2Fixture * pOtherFixture, vec2 worldPosition, vec2 worldNormal)
{
	GameObject::BeginContact(pOtherFixture, worldPosition, worldNormal);

	GameObject* Obj = (GameObject*)pOtherFixture->GetBody()->GetUserData();

	std::string Name = ((PlayerObject*)Obj)->GetName();

	if (Name.compare(0, 8, "Meat Boy") == 0)
	{
		// get collected
        
         SetCollectedStatus(true);
         m_pScene->GetResourceManager()->GetSoundPlayer("Level1_SoundPlayer")->PlaySound(m_pScene->GetResourceManager()->GetSoundObject("Bandage Pickup"));
	}	
}

void BandagePickupObject::RemoveFromScene()
{
    GameObject::RemoveFromScene();
}

void BandagePickupObject::EndContact(b2Fixture * pOtherFixture)
{
}

void BandagePickupObject::SetCollectedStatus(bool collected)
{
    m_isCollected = collected;
}

bool BandagePickupObject::GetCollectedStatus()
{
    return m_isCollected;
}
