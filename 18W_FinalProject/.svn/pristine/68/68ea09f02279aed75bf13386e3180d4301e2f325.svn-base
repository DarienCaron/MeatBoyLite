#include "GamePCH.h"
#include "World.h"

World::World(b2Vec2 a_Gravity)
{
    m_PhysicsWorld = new b2World(a_Gravity);

    b2BodyDef bodydef;
    m_pGround = m_PhysicsWorld->CreateBody(&bodydef);
    m_totalUnusedTime = 0;
}

World::~World()
{
    delete m_PhysicsWorld;
}

void World::Update(float delta)
{
    if (m_IsActive != false)
    {
        float timeStep = 1 / 60.0f;

        m_totalUnusedTime += delta;

        while (m_totalUnusedTime > timeStep)
        {
            m_PhysicsWorld->Step(timeStep, 8, 3);
            m_totalUnusedTime -= timeStep;
        }
    }
}



b2World * World::GetPhysicsWorld()
{
    return m_PhysicsWorld;
}
