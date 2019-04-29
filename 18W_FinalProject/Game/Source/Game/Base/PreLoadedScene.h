#ifndef __PreLoadedScene_H__
#define __PreLoadedScene_H__



class Game;
class ScoreDisplay;
using namespace std;
class PreLoadedScene : public Scene
{
protected:
	

public:
	PreLoadedScene(Game* pGame, ResourceManager* pResources, std::string name);
	virtual ~PreLoadedScene();

	virtual void OnSurfaceChanged(unsigned int width, unsigned int height);
	virtual void LoadContent();

	virtual void Update(float deltatime);
	virtual void Draw();

};

#endif //__Scene_H__
