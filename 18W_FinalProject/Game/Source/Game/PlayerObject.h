#ifndef __PlayerObject_H__
#define __PlayerObject_H__


#define MEAT_BOY_BLOODCHUNK_TIMER 2.0f

class PlayerObject : public GameObject
{
protected:
    PlayerController* m_pController;
	SimplePool<GameObject> m_BloodPool;
    SimplePool<GameObject> m_BloodGibPool;
    vec2 m_WallCollisionNormal; // normal that will be used to store the direction Meat Boy hit the wall from. 

    bool m_Saved = false;
	bool m_Placed;
    bool m_Killed = false;
    bool m_Skipped1 = false;
    bool m_Skipped2 = false;
	bool m_Jump = false;
    bool m_wallJump = false;

    bool m_PressedM1 = false;
    bool m_PressedM2 = false;


    float m_DeathTimer;
    float m_jumpStrength = 0;
    vec3 m_respawnPos = 0;

    bool m_ControllerDisabled = false;

    bool m_IsRunning = false;

    float m_BloodChunkTimer = 0;

public:
    PlayerObject(Scene* pScene, std::string name, vec3 pos, vec3 rot, vec3 scale, Mesh* pMesh, Material* a_Material);
    PlayerObject(Scene* pScene, std::string name, vec3 pos, vec3 rot, vec3 scale, std::string meshname, std::string a_Material);
    virtual ~PlayerObject();

    void SetController(PlayerController* pController);

    virtual void Update(float deltatime);
	virtual void BeginContact(b2Fixture* pOtherFixture, vec2 worldPosition, vec2 worldNormal);
	virtual void EndContact(b2Fixture* pOtherFixture);

	void ReturnBloodToPool(GameObject* obj);
    void KillMeatBoy();

	void InitPool(Scene* scene);

    void DisableController() { m_ControllerDisabled = true; }
    void EnableController() { m_ControllerDisabled = false; }

    vec3 GetRespawnPosition();
    void SetRespawnPosition(vec3 pos);

    void SetFirstDebugMode(bool debug);
    void SetSecondDebugMode(bool debug);


    void SpawnBloodChunk(vec3 dir);
	const vec3 MEAT_BOY_STARTING_POINT = vec3(3, 0, 0);
	const vec3 MEAT_BOY_SKIPPING_POINT1 = vec3(-4, -0.15f, 0);
	const vec3 MEAT_BOY_SKIPPING_POINT2 = vec3(-1, 26, 0);
	const float DEATH_TIMER_DURATION = 0.4f;




	
};

#endif //__PlayerObject_H__