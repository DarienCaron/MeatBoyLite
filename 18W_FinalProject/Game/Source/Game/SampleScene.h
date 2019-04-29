#ifndef __SampleScene_H__
#define __SampleScene_H__

#include <vector>


class Game;
class ScoreDisplay;
using namespace std;
class SampleScene : public Scene
{
protected:
    vec3 m_rotate;
    ContactListener* m_pContactListener;
    SimplePool<GameObject> m_MissilePool;
    SimplePool<GameObject> m_BloodChunkPool;
    float m_MissileTimer;
    float m_DeathTimer;
    bool m_SeenByTurret = false;

    bool m_MIsPressed = false;
    bool m_RIsPressed = false;

    bool m_IsBeat = false;
    bool m_IsBeingRendered = false;

    bool m_IsBandageCollected = false;
    SkyBox* m_pSkyBox;


    bool debug = false;
  

public:
    SampleScene(Game* pGame, ResourceManager* pResources, std::string name);
    virtual ~SampleScene();

    virtual void OnSurfaceChanged(unsigned int width, unsigned int height);
    virtual void LoadContent();
    void SpawnMissile();
    virtual void OnEvent(Event* pEvent);


    virtual void Update(float deltatime);
    virtual void Draw();

    void SetIsBeingRendered(bool condition) { m_IsBeingRendered = condition; }
    bool GetIsBeingRendered() { return m_IsBeingRendered; }


    void SetBandageIsCollected(bool collected);
    bool GetBandageIsCollected();

    void SpawnBloodChunks(vec3 spawnpos, unsigned int numchunks);

    void SetIsPaused(bool condition) { m_IsPaused = condition; }

    virtual void SetIsBeaten(bool condition) { m_LevelIsBeat = condition; }

    virtual bool GetIsBeaten() { return m_LevelIsBeat; }

};

#endif //__Scene_H__
