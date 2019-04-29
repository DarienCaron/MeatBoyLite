#ifndef __Scene_H__
#define __Scene_H__


struct LightInfo
{
    vec3 position;
    vec4 color;
};

class Game;
class GameObject;
class World;
class ScoreDisplay;
class Scene
{
protected:
    Game* m_pGame;
    ResourceManager* m_pResources;

    std::map<std::string, GameObject*> m_pGameObjects;

    std::vector<LightInfo> m_Lights;


    bool m_SceneIsActive = false;

    std::string m_pName;

    World* m_pWorld;


    bool m_IsPaused = false;

    bool m_LevelIsBeat = false;

public:
    Scene(Game* pGame, ResourceManager* pResources, std::string name);
    virtual ~Scene();

    virtual void OnSurfaceChanged(unsigned int width, unsigned int height);
    virtual void LoadContent();

    //virtual void OnEvent(Event* pEvent);

    virtual void OnEvent(Event* pEvent);

    virtual void Update(float deltatime);
    virtual void Draw();

    virtual void SetIsPaused(bool condition) { m_IsPaused = condition; }

    virtual void SetIsBeaten(bool condition) { m_LevelIsBeat = condition; }

    virtual bool GetIsBeaten() { return m_LevelIsBeat; }


    void LoadFiles();
    void SaveFiles();


    

	void AddToScene(std::string name, GameObject* obj);
	void RemoveFromScene(GameObject* obj);

    Game* GetGame() { return m_pGame; }
    ResourceManager* GetResourceManager() { return m_pResources; }

    GameObject* GetGameObject(const char* name) { return m_pGameObjects[name]; }
	GameObject* GetGameObject(std::string name) { return m_pGameObjects[name]; }

    World* GetWorld() { return m_pWorld; }

    void SetName(std::string name) { m_pName = name; }
    std::string GetName() { return m_pName; }


    void AddLight(vec3 position, vec4 color)
    {
        LightInfo Light;

        Light.color = color;
        Light.position = position;

        m_Lights.push_back(Light);
    }

    std::vector<LightInfo> GetLights() { return m_Lights; }


    void LoadSceneFile(const char* filename);

    void SetSceneIsActive(bool active) { m_SceneIsActive = active; }
    bool GetSceneIsActive() { return m_SceneIsActive; }

};

#endif //__Scene_H__
