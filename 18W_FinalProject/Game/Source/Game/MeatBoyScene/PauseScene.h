#ifndef __PauseScene_H__
#define __PauseScene_H__

class Game;

class PauseScene : public Scene
{
public:
    PauseScene(Game* pGame, ResourceManager* pResources, std::string name);
    virtual ~PauseScene();

    virtual void OnSurfaceChanged(unsigned int width, unsigned int height);
    virtual void LoadContent();

    void OnEvent(Event* pEvent);

    virtual void Update(float deltatime);
    virtual void Draw();

protected:

    bool m_UnPause = false;
};




#endif //__Pause_H__