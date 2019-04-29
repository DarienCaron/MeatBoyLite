#pragma once

class World
{

public: 

    World(b2Vec2 a_Gravity);
    ~World();
    void Update(float delta);
    b2World* GetPhysicsWorld();
    float m_totalUnusedTime;
    bool m_IsActive;

    b2Body* GetGround() { return m_pGround; }
    void SetIsActive(bool set) { m_IsActive = set; }

protected:

    b2World* m_PhysicsWorld;
    b2Vec2 m_Position;
    b2Body* m_pGround;
   

};