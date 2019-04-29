#ifndef __MissileObject_H__
#define __MissileObject_H__

class MissileObject : public GameObject
{
public:
	MissileObject(Scene* pScene, std::string name, vec3 pos, vec3 rot, vec3 scale, Mesh* pMesh, Material* a_material);
	MissileObject(Scene* pScene, std::string name, vec3 pos, vec3 rot, vec3 scale, std::string meshname, std::string material);
	virtual ~MissileObject();


	unsigned int GetRenderOrder() { return m_RenderOrder; }
	void SetRenderOrder(unsigned int order) { m_RenderOrder = order; }

	virtual void Update(float deltatime);
    void SetPool(SimplePool<GameObject>* Pool);

	virtual void BeginContact(b2Fixture* pOtherFixture, vec2 worldPosition, vec2 worldNormal);
	virtual void EndContact(b2Fixture* pOtherFixture);

    SimplePool<GameObject>* GetPool() { return m_Pool; }

    void SetHasFired(bool condition) { m_HasFired = condition; }

protected:
    SimplePool<GameObject>* m_Pool;

    bool m_IsDestroyed = false;
    bool m_HasFired = false;

    float m_FireTimer;
};




#endif //__MissileObject_H__

