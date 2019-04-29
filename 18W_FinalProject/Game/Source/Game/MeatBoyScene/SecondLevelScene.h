#ifndef __SecondLevelScene_H__
#define __SecondLevelScene_H__

#include <vector>


class Game;
class ScoreDisplay;
class Skybox;
using namespace std;
class SecondLevelScene : public Scene
{
protected:
    vec3 m_rotate;
    ContactListener* m_pContactListener;
    SimplePool<GameObject> m_SawbladePool;



    bool m_RIsPressed = false;
    bool m_MIsPressed = false;
   

    

    bool m_LevelIsBeaten;

    float m_DeathTimer;
    float m_SawbladeTimer = 2;
    bool m_IsBeingRendered = false;
    SkyBox* m_pSkyBox;
    bool m_IsBandageCollected;
  

public:
    SecondLevelScene(Game* pGame, ResourceManager* pResources, std::string name);
    virtual ~SecondLevelScene();

    virtual void OnSurfaceChanged(unsigned int width, unsigned int height);
    virtual void LoadContent();
    virtual void OnEvent(Event* pEvent);

    virtual void ShootSawblade();

    virtual void Update(float deltatime);
    virtual void Draw();

    void SetIsBeingRendered(bool condition) { m_IsBeingRendered = condition; }
    bool GetIsBeingRendered() { return m_IsBeingRendered; }

    virtual void SetIsBeaten(bool condition) { m_LevelIsBeat = condition; }

    virtual bool GetIsBeaten() { return m_LevelIsBeat; }

    void SetBandageIsCollected(bool collected) { m_IsBandageCollected = collected; }
    bool GetBandageIsCollected() { return m_IsBandageCollected; }

    void SetIsPaused(bool condition) { m_IsPaused = condition; }

};

#endif //__SecondLevelScene_H__
