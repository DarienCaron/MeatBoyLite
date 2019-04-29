#ifndef __TurretObject_H__
#define __TurretObject_H__
class StateMachine;
class TurretObject : public GameObject
{
public:
	TurretObject(Scene* pScene, std::string name, vec3 pos, vec3 rot, vec3 scale, Mesh* pMesh, Material* a_material);
	TurretObject(Scene* pScene, std::string name, vec3 pos, vec3 rot, vec3 scale, std::string meshname, std::string material);
	virtual ~TurretObject();

    float m_angleBetweenMeatBoy;


	unsigned int GetRenderOrder() { return m_RenderOrder; }
	void SetRenderOrder(unsigned int order) { m_RenderOrder = order; }

	virtual void Update(float deltatime);

	virtual void BeginContact(b2Fixture* pOtherFixture, vec2 worldPosition, vec2 worldNormal);
	virtual void EndContact(b2Fixture* pOtherFixture);

    void SetAngleBetweenMeatBoy(vec3 meatPos);
    float GetAngleBetweenMeatBoy();

	void State_Idle(bool enteringstate, float deltatime);
	void State_Follow(bool enteringstate, float deltatime);

	void SetState(bool state) { m_pStateFlag = state; }

protected:

	StateMachine* m_pBrain;
	bool m_pStateFlag;
};


#endif //__TurretObject_H__

