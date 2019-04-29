#ifndef __BandagePickupObject_H__
#define __BandagePickupObject_H__

class BandagePickupObject : public GameObject
{
public:
    BandagePickupObject(Scene* pScene, std::string name, vec3 pos, vec3 rot, vec3 scale, Mesh* pMesh, Material* a_material);
    BandagePickupObject(Scene* pScene, std::string name, vec3 pos, vec3 rot, vec3 scale, std::string meshname, std::string material);
	virtual ~BandagePickupObject();

    virtual void RemoveFromScene();

	unsigned int GetRenderOrder() { return m_RenderOrder; }
	void SetRenderOrder(unsigned int order) { m_RenderOrder = order; }

    void SetCollectedStatus(bool collected);
    bool GetCollectedStatus();

	virtual void Update(float deltatime);

	virtual void BeginContact(b2Fixture* pOtherFixture, vec2 worldPosition, vec2 worldNormal);
	virtual void EndContact(b2Fixture* pOtherFixture);

   

protected:
    
    bool m_isCollected = false;
};




#endif //__SawBladeObject_H__

