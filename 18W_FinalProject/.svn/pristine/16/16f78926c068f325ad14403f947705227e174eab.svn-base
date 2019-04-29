#ifndef __BandageGirlObject_H__
#define __BandageGirlObject_H__

class BandageGirlObject : public GameObject
{
public:
    BandageGirlObject(Scene* pScene, std::string name, vec3 pos, vec3 rot, vec3 scale, Mesh* pMesh, Material* a_material);
    BandageGirlObject(Scene* pScene, std::string name, vec3 pos, vec3 rot, vec3 scale, std::string meshname, std::string material);
	virtual ~BandageGirlObject();


	unsigned int GetRenderOrder() { return m_RenderOrder; }
	void SetRenderOrder(unsigned int order) { m_RenderOrder = order; }

	virtual void Update(float deltatime);

	virtual void BeginContact(b2Fixture* pOtherFixture, vec2 worldPosition, vec2 worldNormal);
	virtual void EndContact(b2Fixture* pOtherFixture);

    void SetIsSaved(bool saved);
    bool GetIsSaved();

    bool m_IsSaved = false;

};




#endif //__SawBladeObject_H__

