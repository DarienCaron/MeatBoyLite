#ifndef __SawBladeObject_H__
#define __SawBladeObject_H__

class SawBladeObject : public GameObject
{
public:
	SawBladeObject(Scene* pScene, std::string name, vec3 pos, vec3 rot, vec3 scale, Mesh* pMesh, Material* a_material);
	SawBladeObject(Scene* pScene, std::string name, vec3 pos, vec3 rot, vec3 scale, std::string meshname, std::string material);
	virtual ~SawBladeObject();


	unsigned int GetRenderOrder() { return m_RenderOrder; }
	void SetRenderOrder(unsigned int order) { m_RenderOrder = order; }

	virtual void Update(float deltatime);
    void SetPool(SimplePool<GameObject>* Pool);

	virtual void BeginContact(b2Fixture* pOtherFixture, vec2 worldPosition, vec2 worldNormal);
	virtual void EndContact(b2Fixture* pOtherFixture);
protected:
    SimplePool<GameObject>* m_Pool;

    bool m_IsDestroyed = false;
};




#endif //__SawBladeObject_H__

