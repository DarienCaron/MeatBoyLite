#ifndef __BloodChunkObject_H__
#define __BloodChunkObject_H__

class BloodChunkObject : public GameObject
{
public:
    BloodChunkObject(Scene* pScene, std::string name, vec3 pos, vec3 rot, vec3 scale, Mesh* pMesh, Material* a_material);
    BloodChunkObject(Scene* pScene, std::string name, vec3 pos, vec3 rot, vec3 scale, std::string meshname, std::string material);
    virtual ~BloodChunkObject();


    unsigned int GetRenderOrder() { return m_RenderOrder; }
    void SetRenderOrder(unsigned int order) { m_RenderOrder = order; }

    virtual void Update(float deltatime);
    void SetPool(SimplePool<GameObject>* Pool);

    void Destroy();

    virtual void BeginContact(b2Fixture* pOtherFixture, vec2 worldPosition, vec2 worldNormal);
    virtual void EndContact(b2Fixture* pOtherFixture);

    SimplePool<GameObject>* GetPool() { return m_Pool; }

    void SetIsActivated(bool condition) { m_IsActivated = condition; }

protected:
    SimplePool<GameObject>* m_Pool;
    float m_AnimationTimer;
    bool m_IsActivated = false;
    bool m_Destroy = false;

};

#endif //__BloodChunkObject_H__