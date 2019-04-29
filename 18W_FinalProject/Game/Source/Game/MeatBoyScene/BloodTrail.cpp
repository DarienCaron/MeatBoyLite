#include "GamePCH.h"

BloodTrail::BloodTrail(Scene * pScene, std::string name, vec3 pos, vec3 rot, vec3 scale, Mesh * pMesh, Material * a_material) :
	GameObject(pScene, name, pos, rot, scale, pMesh, a_material)
{
	m_Pool = 0;
}

BloodTrail::BloodTrail(Scene * pScene, std::string name, vec3 pos, vec3 rot, vec3 scale, std::string meshname, std::string material) :
	GameObject(pScene, name, pos, rot, scale, meshname, material)
{
	m_Pool = 0;
}

BloodTrail::~BloodTrail()
{
}

void BloodTrail::Update(float deltatime)
{
}

void BloodTrail::BeginContact(b2Fixture * pOtherFixture, vec2 worldPosition, vec2 worldNormal)
{
	GameObject::BeginContact(pOtherFixture, worldPosition, worldNormal);

	GameObject* Obj = (GameObject*)pOtherFixture->GetBody()->GetUserData();

	std::string Name = Obj->GetName();

	if (Name.compare("BloodTrail") == 0)
	{
		GameObject* Player = m_pScene->GetGameObject("Meat Boy");
		((PlayerObject*)Player)->ReturnBloodToPool(Obj);
	}
}

void BloodTrail::EndContact(b2Fixture * pOtherFixture)
{
}

void BloodTrail::SetPool(SimplePool<GameObject>* Pool)
{
	m_Pool = Pool;
}
