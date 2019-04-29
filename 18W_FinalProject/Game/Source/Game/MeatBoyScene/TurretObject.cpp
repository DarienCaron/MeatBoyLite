#include "GamePCH.h"



TurretObject::TurretObject(Scene* pScene, std::string name, vec3 pos, vec3 rot, vec3 scale, Mesh* pMesh, Material* a_Material)
	: GameObject(pScene, name, pos, rot, scale, pMesh, a_Material)
{
	m_pBrain = new StateMachine(this);
	m_pBrain->SetState((AIStateFunction)&TurretObject::State_Idle);
	m_pStateFlag = false;
}

TurretObject::TurretObject(Scene* pScene, std::string name, vec3 pos, vec3 rot, vec3 scale, std::string meshname, std::string a_Material)
	: GameObject(pScene, name, pos, rot, scale, meshname, a_Material)
{
	m_pBrain = new StateMachine(this);
	m_pBrain->SetState((AIStateFunction)&TurretObject::State_Idle);
	m_pStateFlag = false;
	
}

TurretObject::~TurretObject()
{
	delete m_pBrain;
}



void TurretObject::Update(float deltatime)
{
	GameObject::Update(deltatime);
	if (m_pStateFlag == true)
	{
		m_pBrain->SetState((AIStateFunction)&TurretObject::State_Follow);
	}



	if (m_pStateFlag == false)
	{
		m_pBrain->SetState((AIStateFunction)&TurretObject::State_Idle);
	}
    
}

void TurretObject::BeginContact(b2Fixture * pOtherFixture, vec2 worldPosition, vec2 worldNormal)
{
	GameObject::BeginContact(pOtherFixture, worldPosition, worldNormal);

	GameObject* Obj = (GameObject*)pOtherFixture->GetBody()->GetUserData();

	std::string Name = ((PlayerObject*)Obj)->GetName();

	


}

void TurretObject::EndContact(b2Fixture * pOtherFixture)
{
}

void TurretObject::SetAngleBetweenMeatBoy(vec3 meatPos)
{
    // first, calculate the angle between the turret and Meat Boy
    // then convert the difference to degrees
    // then multiply the quotient by -1 so that the inverse angle actually ends up being the proper angle. 
    m_angleBetweenMeatBoy = ((atan2(meatPos.y - m_Position.y, meatPos.x - m_Position.x)) * 180 / PI) * -1;
}

float TurretObject::GetAngleBetweenMeatBoy()
{
    return m_angleBetweenMeatBoy;
}


void TurretObject::State_Idle(bool enteringstate, float deltatime)
{
	SetRotation(vec3(0, 0, 0));
}

void TurretObject::State_Follow(bool enteringstate, float deltatime)
{
	SetRotation(vec3(0, 0, m_angleBetweenMeatBoy)); // every frame set the turret's angle on the z-axis
													// to the angle between it and Meat Boy
}
