#ifndef __TitleScene_H__
#define __TitleSelectScene_H__

#include <vector>

class Game;
class ScoreDisplay;
using namespace std;

class TitleScene : public Scene
{
protected:
    bool m_Pressed = false;
    float m_titleTimer;

public:
    TitleScene(Game* pGame, ResourceManager* pResources, std::string name);
    virtual ~TitleScene();

    virtual void OnSurfaceChanged(unsigned int width, unsigned int height);
    virtual void LoadContent();

    virtual void Update(float deltatime);
    virtual void Draw();
    void OnEvent(Event* pEvent);

};

#endif //__Scene_H__