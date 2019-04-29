#ifndef __GameCore_H__
#define __GameCore_H__

class GameCore;

class Scene;
class ResourceManager;

class GameCore
{
protected:
    Scene* m_pScene;

    ResourceManager* m_pResources;

    unsigned int m_WindowWidth;
    unsigned int m_WindowHeight;

    std::queue<Event*> m_EventQueue;

    PlayerController m_Controllers[4];

public:
    GameCore();
    virtual ~GameCore();

    virtual void OnSurfaceChanged(unsigned int width, unsigned int height);
    virtual void LoadContent();

    virtual void QueueEvent(Event* pEvent);
    virtual void ProcessEvents();
    virtual void OnEvent(Event* pEvent);

    virtual void Update(float deltatime);
    virtual void Draw();

    PlayerController* GetController(int index) { return &m_Controllers[index]; }
};

#endif //__GameCore_H__
