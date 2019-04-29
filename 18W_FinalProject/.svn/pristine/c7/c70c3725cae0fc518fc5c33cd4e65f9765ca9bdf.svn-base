#ifndef __ProjectileSawObject_H__
#define __ProjectileSawObject_H__

class ProjectileSawObject : public GameObject
{
public:
    ProjectileSawObject(Scene* pScene, std::string name, vec3 pos, vec3 rot, vec3 scale, Mesh* pMesh, Material* a_material);
    ProjectileSawObject(Scene* pScene, std::string name, vec3 pos, vec3 rot, vec3 scale, std::string meshname, std::string material);
	virtual ~ProjectileSawObject();


	unsigned int GetRenderOrder() { return m_RenderOrder; }
	void SetRenderOrder(unsigned int order) { m_RenderOrder = order; }

	virtual void Update(float deltatime);
    void SetPool(SimplePool<GameObject>* Pool);

	virtual void BeginContact(b2Fixture* pOtherFixture, vec2 worldPosition, vec2 worldNormal);
	virtual void EndContact(b2Fixture* pOtherFixture);

    SimplePool<GameObject>* GetPool() { return m_Pool; }
protected:
    SimplePool<GameObject>* m_Pool;

    bool m_IsDestroyed = false;
};




#endif //__ProjectileSawObject_H__

