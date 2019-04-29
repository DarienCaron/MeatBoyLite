#ifndef __SceneManager_H__
#define __SceneManager_H__

#include <vector>



class SceneManager;
class Scene;
class SceneManager
{
public:
	SceneManager();
	virtual ~SceneManager();

    void LoadContent();

   void OnEvent(Event* pEvent);
   void Update(float deltatime);
   void Draw();




	void AddScene(const char* name, Scene* pScene) { m_pScenes[name] = pScene; }
	Scene* GetScene(const char* name) { return m_pScenes[name]; }
	Scene* GetScene(std::string name) { return m_pScenes[name]; }

    void SetRenderToTextureScene(const char* name, int digit) 
    { 
        if (digit == 1)
        {
            m_RenderToTextureScene = m_pScenes[name];
        }
        if (digit == 2)
        {
            m_RenderToTextureScene2 = m_pScenes[name];
        }
    }

    void SetRenderToTextureScene(std::string  name, int digit) 
    {
        
        if (digit == 1)
        {
            m_RenderToTextureScene = m_pScenes[name];
        }
        if (digit == 2)
        {
            m_RenderToTextureScene2 = m_pScenes[name];
        }
    }

   
    Scene* GetRenderToTextureScene(int digit) {
        if (digit == 1)
        {
            return m_RenderToTextureScene;
            }
        if (digit == 2)
        {
            return m_RenderToTextureScene2;
        }

        return 0;
         }

    Scene* GetFrontScene() { return m_ActiveScenes.front(); }

    void PushScene(std::string name);
    void PopScene();

    //std::vector<Scene*> GetActiveScene() { return m_ActiveScenes; }
    std::vector<Scene*> m_ActiveScenes;

protected:
	std::map<std::string, Scene*> m_pScenes;

    Scene* m_RenderToTextureScene;
    Scene* m_RenderToTextureScene2;
    

};



#endif //__SceneManager_H__

