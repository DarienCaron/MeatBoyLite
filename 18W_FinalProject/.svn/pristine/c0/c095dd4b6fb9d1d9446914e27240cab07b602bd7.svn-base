#include "GamePCH.h"



SawBladeObject::SawBladeObject(Scene* pScene, std::string name, vec3 pos, vec3 rot, vec3 scale, Mesh* pMesh, Material* a_Material)
	: GameObject(pScene, name, pos, rot, scale, pMesh, a_Material)
{
	
}

SawBladeObject::SawBladeObject(Scene* pScene, std::string name, vec3 pos, vec3 rot, vec3 scale, std::string meshname, std::string a_Material)
	: GameObject(pScene, name, pos, rot, scale, meshname, a_Material)
{

}
SawBladeObject::~SawBladeObject()
{
}



void SawBladeObject::Update(float deltatime)
{
	GameObject::Update(deltatime);

    
}

void SawBladeObject::SetPool(SimplePool<GameObject>* Pool)
{
    m_Pool = Pool;
}

void SawBladeObject::BeginContact(b2Fixture * pOtherFixture, vec2 worldPosition, vec2 worldNormal)
{
	GameObject::BeginContact(pOtherFixture, worldPosition, worldNormal);

	GameObject* Obj = (GameObject*)pOtherFixture->GetBody()->GetUserData();

	std::string Name = ((PlayerObject*)Obj)->GetName();

	if (Name.compare("Meat Boy") == 0)
	{
		Material* mat = m_pScene->GetResourceManager()->GetMaterial("Bloody Sawblade Material");
		SetMaterial(mat);
	}
    
	
}

void SawBladeObject::EndContact(b2Fixture * pOtherFixture)
{
    
}
