#pragma once

class Game;
class Mesh;

class ScoreDisplay : public GameObject
{
public:
    // a position is passed into the score display so that we can 
    // set the position of each digit individually
    ScoreDisplay(Scene* pScene, std::string name, vec3 pos, vec3 rot, vec3 scale, Mesh* pMesh, Material* a_material);
    ScoreDisplay(Scene* pScene, std::string name, vec3 pos, vec3 rot, vec3 scale, std::string meshname, std::string material);

    ~ScoreDisplay();

    void Draw(int renderorder, vec3 campos);
    void Update(float deltatime);
    
    // Getters and setters for the player's score and position
    int GetScore();
    void SetScore(int score);

    void SetHasCompleted(bool complete);
    
  

private:
    int m_Score;
    float m_scoreTimer = 30;
    vec3 m_Position;
    bool m_hasCompleted = false;

    // using the texture shader because since it is not a GameObject
    // by default it would not have a shader program
    ShaderProgram* m_scoreShader;
    Material* m_scoreMaterial;

    GLuint m_NumberTextureList[10]; // There are 10 different digit textures (0-9). This array is used as a resource
    GLuint m_NumberDigit[6]; // each digit will have its own separate texture
    GLuint m_NumberSpriteSheet;


    int m_DigitValues[4];
    Mesh* m_NumberMesh[4];
    vec3 m_Digitpos[4];// Score can only go up to 999999 hence the 6 array indeces
                           // each digit is also its own entity

};