#ifndef __BloodTrail_H__
#define __BloodTrail_H__

class BloodTrail : public GameObject
{
public:
	BloodTrail(Scene* pScene, std::string name, vec3 pos, vec3 rot, vec3 scale, Mesh* pMesh, Material* a_material);
	BloodTrail(Scene* pScene, std::string name, vec3 pos, vec3 rot, vec3 scale, std::string meshname, std::string material);
	virtual ~BloodTrail();


	unsigned int GetRenderOrder() { return m_RenderOrder; }
	void SetRenderOrder(unsigned int order) { m_RenderOrder = order; }

	virtual void Update(float deltatime);

	virtual void BeginContact(b2Fixture* pOtherFixture, vec2 worldPosition, vec2 worldNormal);
	virtual void EndContact(b2Fixture* pOtherFixture);
	void SetPool(SimplePool<GameObject>* Pool);
protected:
	SimplePool<GameObject>* m_Pool;
};




#endif //__BloodTrail_H__
