#ifndef __Game_H__
#define __Game_H__

class ShaderProgram;



class Game : public GameCore
{
protected:
    unsigned int m_WindowWidth;
    unsigned int m_WindowHeight;
    bool m_IsGravityEnabled = true;

    std::queue<Event*> m_EventQueue;

    ResourceManager* m_pResources;
	SceneManager* m_pSceneManager;
    ImGuiManager * m_pImGuiManager;

    
    
    FBODefinition* m_FBO;

    FBODefinition* m_FBO2;

    PlayerController m_Controllers[4];

    

public:
    Game(Framework* pFramework);
    virtual ~Game();

    virtual void OnSurfaceChanged(unsigned int width, unsigned int height);
    virtual void LoadContent();

    virtual void QueueEvent(Event* pEvent);
    virtual void ProcessEvents();
    virtual void OnEvent(Event* pEvent);

    virtual void Update(float deltatime);
    virtual void Draw();

    void SetDebugMode(bool debug);


    //void SaveFile(const char* filename);

    SceneManager* GetSceneManager() { return m_pSceneManager; }

    FBODefinition* GetFBO(int selection);
    

    PlayerController* GetController(int index) { return &m_Controllers[index]; }
    friend class Scene;
};

#endif //__Game_H__
