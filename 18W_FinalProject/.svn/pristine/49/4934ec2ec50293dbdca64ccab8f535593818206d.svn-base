#include "GamePCH.h"



ProjectileSawObject::ProjectileSawObject(Scene* pScene, std::string name, vec3 pos, vec3 rot, vec3 scale, Mesh* pMesh, Material* a_Material)
	: GameObject(pScene, name, pos, rot, scale, pMesh, a_Material)
{
	
}

ProjectileSawObject::ProjectileSawObject(Scene* pScene, std::string name, vec3 pos, vec3 rot, vec3 scale, std::string meshname, std::string a_Material)
	: GameObject(pScene, name, pos, rot, scale, meshname, a_Material)
{

}
ProjectileSawObject::~ProjectileSawObject()
{
}



void ProjectileSawObject::Update(float deltatime)
{
	GameObject::Update(deltatime);

    if (m_IsDestroyed == true)
    {
        RemoveFromPoolEvent* pEvent2 = new RemoveFromPoolEvent(this);
        m_pScene->GetGame()->QueueEvent(pEvent2);
        m_IsDestroyed = false;
    }
}

void ProjectileSawObject::SetPool(SimplePool<GameObject>* Pool)
{
    m_Pool = Pool;
}

void ProjectileSawObject::BeginContact(b2Fixture * pOtherFixture, vec2 worldPosition, vec2 worldNormal)
{
	GameObject::BeginContact(pOtherFixture, worldPosition, worldNormal);

	GameObject* Obj = (GameObject*)pOtherFixture->GetBody()->GetUserData();

	std::string Name = ((PlayerObject*)Obj)->GetName();
    m_IsDestroyed = true;

	if (Name.compare("Meat Boy") == 0)
	{
		Material* mat = m_pScene->GetResourceManager()->GetMaterial("Bloody Sawblade Material");
		SetMaterial(mat);
	}
    
	
}

void ProjectileSawObject::EndContact(b2Fixture * pOtherFixture)
{
    
}
