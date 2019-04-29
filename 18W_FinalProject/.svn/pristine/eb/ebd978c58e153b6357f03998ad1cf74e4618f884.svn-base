#include "GamePCH.h"
#include "ScoreDisplay.h"

ScoreDisplay::ScoreDisplay(Scene* pScene, std::string name, vec3 pos, vec3 rot, vec3 scale, Mesh* pMesh, Material* a_material)
    : GameObject(pScene, name, pos, rot, scale, pMesh, a_material)
{
    // Initialziation
    m_Score = 0;

    // creating a mesh for each digit in the score
    for (int i = 0; i < 4; i++)
    {
        m_NumberMesh[i] = pMesh;
        m_Digitpos[i] = vec3(pos.x - (i *0.9f), pos.y, pos.z);
        m_DigitValues[i] = 0;

    }

}
ScoreDisplay::ScoreDisplay(Scene* pScene, std::string name, vec3 pos, vec3 rot, vec3 scale, std::string meshname, std::string material)
    : GameObject(pScene, name, pos, rot, scale, meshname, material)
{
    // Initialziation
    m_Score = 0;

    // creating a mesh for each digit in the score
    for (int i = 0; i < 4; i++)
    {
        m_NumberMesh[i] = pScene->GetResourceManager()->GetMesh(meshname);
        m_Digitpos[i] = vec3(pos.x - (i *0.9f), pos.y, pos.z);
        m_DigitValues[i] = 0;
    }

}

ScoreDisplay::~ScoreDisplay()
{
    // deleting the textures
    glDeleteTextures(1, &m_NumberSpriteSheet);

}

void ScoreDisplay::Draw(int renderorder, vec3 campos)
{
    // displaying each digit on the screen
    for (int i = 0; i < 4; i++)
    {
    // this ugly math is here so that the first digit (the ones) is drawn the farthest
        if (m_NumberMesh[i] == 0)
            return;
        mat4 world;
        world.CreateSRT(m_Scale, m_Rotation, m_Digitpos[i]);
        CameraObject* pCamera = (CameraObject*)m_pScene->GetGameObject("Camera");
        vec3 campos = pCamera->GetPosition();
        mat4* pMatView = pCamera->GetViewMatrix();
        mat4* pMatProj = pCamera->GetProjMatrix();


        m_NumberMesh[i]->SetupAttributes(m_pMaterial->GetShader());
        m_NumberMesh[i]->SetupUniforms(&world, pMatView, pMatProj, campos, m_pMaterial , m_DigitValues[i], 0, 0, 0, 0);
        m_NumberMesh[i]->Draw(m_pMaterial->GetShader());
    }

}

void ScoreDisplay::Update(float deltatime)
{
    if (m_hasCompleted == false)  // if the level isn't finished keep incrementing the score
    {
        m_scoreTimer--;
        if (m_scoreTimer == 0)
        {
            m_Score++;
            m_scoreTimer = 30;
        }
    }

    int leftover = 0;

    if (m_Score >= 9999)
    {
        // error handling so that the score never exceeds the limit of 999999
        m_Score = 9999;
    }

    m_DigitValues[0] = ((m_Score % 100) - leftover) / 10;
    leftover += (m_DigitValues[1] * 10);

    m_DigitValues[1] = ((m_Score % 100) - leftover) / 10;
    leftover += (m_DigitValues[1] * 10);

    m_DigitValues[2] = ((m_Score % 1000) - leftover) / 100;
    leftover += (m_DigitValues[2] * 100);

    m_DigitValues[3] = ((m_Score % 10000) - leftover) / 1000;
    leftover += (m_DigitValues[2] * 1000);

}

int ScoreDisplay::GetScore()
{
    return m_Score;
}

void ScoreDisplay::SetScore(int score)
{
    m_Score = score;
}

void ScoreDisplay::SetHasCompleted(bool complete)
{
    m_hasCompleted = complete;
}

