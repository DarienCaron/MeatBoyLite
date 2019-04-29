#include "GamePCH.h"

GameObject::GameObject(Scene* pScene, std::string name, vec3 pos, vec3 rot, vec3 scale, Mesh* pMesh, Material* a_material)
{
    Init( pScene, name, pos, rot, scale, pMesh,a_material);
}

GameObject::GameObject(Scene* pScene, std::string name, vec3 pos, vec3 rot, vec3 scale, std::string meshname, std::string material)
{
    ResourceManager* pResources = pScene->GetResourceManager();
    Init( pScene, name, pos, rot, scale, pResources->GetMesh( meshname ), pResources->GetMaterial(material));
}

GameObject::~GameObject()
{
   
}

void GameObject::Init(Scene* pScene, std::string name, vec3 pos, vec3 rot, vec3 scale, Mesh* pMesh, Material * a_Material)
{
    m_pScene = pScene;

    m_RenderOrder = 0;

    m_Name = name;

    m_Position = pos;
    m_Rotation = rot;
    m_Scale = scale;

    m_pMesh = pMesh;

    m_pMaterial = a_Material;

    m_pBody = 0;


   fixturedef.shape = nullptr;
   fixturedef.userData = nullptr;
   fixturedef.friction = 0.0f;
   fixturedef.restitution = 0.0f;
   fixturedef.density = 0.0f;
   fixturedef.isSensor = false;

   for (int i = 0; i<20; i++)
   {

	   //TweenObject* Tweenobj = new TweenObject();
  
   }

}

void GameObject::Update(float deltatime)
{
    if (m_pBody != 0)
    {
        m_Position.x = m_pBody->GetPosition().x;
        m_Position.y = m_pBody->GetPosition().y;

        float angle = m_pBody->GetAngle();
        m_Rotation.z = -angle *180/PI;
        
    }
    RotWorld.CreateSRT(1, m_Rotation, 0);
}

void GameObject::Draw(int renderorder, mat4* pMatView, mat4* pMatProj, vec3 campos)
{
    if (m_pMesh == 0)
    {
        return;
    }

    if (m_pMaterial == 0)
    {
        return;
    }

    mat4 world;
    world.CreateSRT(m_Scale, m_Rotation, m_Position);


    unsigned int LightCount = m_pScene->GetLights().size();

    Lightpositions = new vec3[3];
    LightColors = new vec4[3];


    for (unsigned int i = 0; i < 3; i++)
    {
        Lightpositions[i] = m_pScene->GetLights()[i].position;

        int bp = 0;
    }
    for (unsigned int i = 0; i < 3; i++)
    {
        LightColors[i] = m_pScene->GetLights()[i].color;
        int bp = 0;
    }

    
    
 


    m_pMesh->SetupAttributes(m_pMaterial->GetShader());
    m_pMesh->SetupUniforms( &world, pMatView, pMatProj,campos,m_pMaterial,0, LightCount, Lightpositions, LightColors, &RotWorld);
    m_pMesh->Draw(m_pMaterial->GetShader());

    delete[] Lightpositions;
    delete[] LightColors;
}

void GameObject::RemoveFromScene()
{
    if (m_pScene)
    {
        m_pScene->RemoveFromScene(this);
        m_pScene = 0;
    }
}

void GameObject::RemoveFromSceneWithPool()
{
    if (m_pScene)
    {
        m_pScene->RemoveFromScene(this);
       

    }
}


// As of now, the fixture creating process also takes in a PhysicsCategory enum, so when the fixture is created, based on the enum passed in
// said fixture will have ceratin masks applied to it.

void GameObject::AddCircle(float32 density, bool a_issensor, float32 a_friction, float32 a_Restitution, float32 a_Radius, uint16 category, uint16 mask)
{
    b2CircleShape circleshape;
    circleshape.m_radius =  a_Radius/2;

    SetFixture(&circleshape, density , a_issensor, a_friction, a_Restitution, category, mask);
}

void GameObject::AddBox(float32 halfWidth, float32 halfHeight, float32 density, bool isSensor, float32 friction, float32 restitution, uint16 category, uint16 mask)
{
    b2PolygonShape boxshape;
    boxshape.SetAsBox(halfWidth/2, halfHeight/2);
    SetFixture(&boxshape , density , isSensor, friction, restitution, category, mask);
 
}

void GameObject::SetFixture(b2Shape *shape, float32 density,bool a_issensor,float32 a_friction,float32 a_Restitution, uint16 category, uint16 mask)
{
    
    fixturedef.shape = shape;
    fixturedef.density = density;
    fixturedef.isSensor = a_issensor;
    fixturedef.friction = a_friction;
    fixturedef.restitution = a_Restitution;

    // collision filtering
    fixturedef.filter.categoryBits = category;
    fixturedef.filter.maskBits = mask;
 

    m_pBody->CreateFixture(&fixturedef);
}

// to reduced repeated code a method has been made for each stage of initializing a joint

void GameObject::CreateRevoluteJoint(float posx, float posy, b2Body* bodyA, b2Body* bodyB, bool motor, float speed, float torque, bool angeLimit, float lowerInDegrees, float upperInDegrees,
    bool localAnchor, float anchorX, float anchorY)
{
	b2RevoluteJointDef jointDef;
	b2Vec2 anchorPos(posx, posy);
	jointDef.Initialize(bodyA, bodyB, anchorPos);
	

    if (motor == true)
    {
    // Initialize the motor on the joint
    jointDef.enableMotor = true;
    jointDef.motorSpeed = speed; // positive values will go counter-clockwise, negative clockwise
    jointDef.maxMotorTorque = torque;

    }

    if (angeLimit == true)
    {
        // Initialize the joint’s angle limits, in radians
        jointDef.enableLimit = true;
        jointDef.lowerAngle = lowerInDegrees * PI / 180;
        jointDef.upperAngle = upperInDegrees * PI / 180;

    }

    if (localAnchor == true)
    {
        jointDef.bodyA = bodyA;
        jointDef.bodyB = bodyB;
        jointDef.localAnchorA = b2Vec2( anchorX, anchorY);
        jointDef.localAnchorB = b2Vec2( anchorX, anchorY);

    }
    
   m_pScene->GetWorld()->GetPhysicsWorld()->CreateJoint(&jointDef);
}

void GameObject::CreatePrismaticJoint(b2Body * bodyA, b2Body * bodyB, float posX, float posY, b2Vec2 axis, bool motor, float speed, float torque, bool translationLimit, float lower, float upper)
{
    b2PrismaticJointDef jointDef;
    b2Vec2 anchorpos (posX, posY); //change to posx and posy
    jointDef.Initialize(bodyA, bodyB, anchorpos, axis); // the fourth value dictates where the joint is moving. 
   
    if (motor == true)
    {
        // Initialize the motor on the joint
        jointDef.enableMotor = true;
        jointDef.motorSpeed = speed; // positive values will go counter-clockwise, negative clockwise
        jointDef.maxMotorForce = torque;

    }

    if (translationLimit == true)
    {
        // Initialize the joint’s angle limits, in radians
        jointDef.enableLimit = true;
        jointDef.lowerTranslation= lower;
        jointDef.upperTranslation = upper;
}
    

    m_pScene->GetWorld()->GetPhysicsWorld()->CreateJoint(&jointDef);

}

void GameObject::CreateBody(bool type)
{
	b2BodyDef bodydef;
	bodydef.position = b2Vec2(m_Position.x, m_Position.y);
	bodydef.angle = -m_Rotation.z/180.0f * PI;
	if (type == 0)
	{

		bodydef.type = b2_dynamicBody;
	}
	else if (type == 1)
	{
		bodydef.type = b2_staticBody;
	}
	

	bodydef.userData = this;
    m_pBody = m_pScene->GetWorld()->GetPhysicsWorld()->CreateBody(&bodydef);
}

void GameObject::AddToScene(Scene * scene)
{
	scene->AddToScene(m_Name, this);
}

void GameObject::SetFixtureDef(b2FixtureDef def)
{
    fixturedef = def;
}

b2FixtureDef GameObject::GetFixtureDef()
{
    return fixturedef;
}



void GameObject::BeginContact(b2Fixture* pOtherFixture, vec2 worldPosition, vec2 worldNormal)
{
	//OutputMessage( "Normal: %s, %0.2f, %0.2f\n", m_Name.c_str(), worldNormal.x, worldNormal.y );
}

void GameObject::EndContact(b2Fixture* pOtherFixture)
{
	//OutputMessage( "Normal: %s, %0.2f, %0.2f\n", m_Name.c_str(), worldNormal.x, worldNormal.y );
}

