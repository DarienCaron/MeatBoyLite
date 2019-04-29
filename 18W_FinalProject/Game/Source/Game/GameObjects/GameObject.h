#ifndef __GameObject_H__
#define __GameObject_H__




class ShaderProgram;
class Mesh;
class Scene;
class World;
class Material;
class StateMachine;
class SampleScene;

enum MeatBoyCollisionCategories // creating the categories for collision filtering
{
    Category_MeatBoy       =  0x0001,
    Category_Sawblade      =  0x0002,
    Category_Ground        =  0x0004,
    Category_Missile       =  0x0008,
    Category_BandageGirl   =  0x0010,
    Category_Wall          =  0x0020,
    Category_BandagePickup =  0x0040,
    Category_Turret        =  0x0080,
    Category_BloodChunk    =  0x0160,
    Category_BloodTrail    =  0x0320,
};

class GameObject
{
protected:

    Scene* m_pScene;

    unsigned int m_RenderOrder;

    std::string m_Name;

    vec3 m_Position;
    vec3 m_Rotation;
    vec3 m_Scale;

    Mesh* m_pMesh;

    Material * m_pMaterial;

	b2Body*  m_pBody;

    b2FixtureDef fixturedef;

    vec3* Lightpositions;
    vec4* LightColors;
    mat4 RotWorld;

	

public:
    GameObject(Scene* pScene, std::string name, vec3 pos, vec3 rot, vec3 scale, Mesh* pMesh,Material* a_material);
    GameObject(Scene* pScene, std::string name, vec3 pos, vec3 rot, vec3 scale, std::string meshname, std::string material);
    virtual ~GameObject();

    unsigned int GetRenderOrder() { return m_RenderOrder; }
    void SetRenderOrder(unsigned int order) { m_RenderOrder = order; }

    virtual void Init(Scene* pScene, std::string name, vec3 pos, vec3 rot, vec3 scale, Mesh* pMesh, Material * a_Material);

    virtual void Update(float deltatime);
    virtual void Draw(int renderorder, mat4* pMatView, mat4* pMatProj, vec3 campos);
	virtual void BeginContact(b2Fixture* pOtherFixture, vec2 worldPosition, vec2 worldNormal);
	virtual void EndContact(b2Fixture* pOtherFixture);

    virtual void RemoveFromScene();

    virtual void RemoveFromSceneWithPool();

	void AddCircle(float32 density, bool a_issensor, float32 a_friction, float32 a_Restitution, float32 a_Radius, uint16 category, uint16 mask);
	void AddBox(float32 halfWidth, float32 halfHeight, float32 density, bool isSensor, float32 friction, float32 restitution, uint16 category, uint16 mask);
    void SetFixture(b2Shape *shape, float32 density, bool a_issensor, float32 a_friction, float32 a_Restitution, uint16 category, uint16 mask);

	void CreateRevoluteJoint(float posx, float posy, b2Body* bodyA, b2Body* bodyB, bool motor, float speed, float torque, bool angeLimit, float lowerInDegrees, float upperInDegrees,
        bool localAnchor, float anchorX, float anchorY);

    void CreatePrismaticJoint(b2Body * bodyA, b2Body * bodyB, float posX, float posY, b2Vec2 axis, bool motor, float speed, float torque, bool translationLimit, float lower, float upper);
      


	void CreateBody(bool type);

	void AddToScene(Scene* scene);

    Mesh* GetMesh() { return m_pMesh; }
	void SetMesh(Mesh* pMesh) { m_pMesh = pMesh; }

    void SetPosition(vec3 pos) { m_Position = pos; }
    void SetRotation(vec3 rot) { m_Rotation = rot; }
    void SetScale(vec3 scale) { m_Scale = scale; }

    void SetFixtureDef(b2FixtureDef def);
    b2FixtureDef GetFixtureDef();

    vec3 GetPosition() { return m_Position; }
    vec3 GetRotation() { return m_Rotation; }
    vec3 GetScale()  { return m_Scale; }
    b2Body* GetBody() { return m_pBody; }


	std::string GetName() { return m_Name; }
	Material* GetMaterial() { return m_pMaterial; }

	void SetName(std::string name) { m_Name = name; }
	void SetMaterial(Material* pMaterial) { m_pMaterial = pMaterial; }



};

#endif //__GameObject_H__
