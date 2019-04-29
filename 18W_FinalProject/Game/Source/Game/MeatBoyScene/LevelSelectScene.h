#ifndef __LevelSelectScene_H__
#define __LevelSelectScene_H__

#include <vector>
enum Levels
{
    Level1,
    Level2
};

class Game;
class ScoreDisplay;
class TweenObject;
using namespace std;

class LevelSelectScene : public Scene
{
protected:

    int m_LevelIndex;
    float m_Tweenpos;
    TweenObject* m_pTweenObject;
    bool m_Selected = false;

    bool m_RIsPressed = false;
    bool m_MIsPressed = false;

    Levels m_Level;

public:
    LevelSelectScene(Game* pGame, ResourceManager* pResources, std::string name);
    virtual ~LevelSelectScene();

    virtual void OnSurfaceChanged(unsigned int width, unsigned int height);
    virtual void LoadContent();

    void OnEvent(Event* pEvent);

    virtual void Update(float deltatime);
    virtual void Draw();

    void ChangeLevels(Levels level);
};

#endif //__Scene_H__