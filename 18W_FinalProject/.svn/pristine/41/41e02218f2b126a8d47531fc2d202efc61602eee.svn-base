#include "GamePCH.h"

SkyBox::SkyBox(Scene * pScene, std::string name, vec3 pos, vec3 rot, vec3 scale, Mesh * pMesh, Material * a_material) 
    : GameObject(pScene, name, pos, rot, scale, pMesh, a_material)
{
    m_pMesh = pMesh;
}

SkyBox::SkyBox(Scene * pScene, std::string name, vec3 pos, vec3 rot, vec3 scale, std::string meshname, std::string material) 
    : GameObject(pScene, name, pos, rot, scale, meshname, material)
{
    m_pMesh = pScene->GetResourceManager()->GetMesh(meshname);
}

SkyBox::~SkyBox()
{

}

void SkyBox::Update(float deltatime)
{

}

void SkyBox::Draw(vec3 campos)
{
    
    
    CameraObject* pCamera = (CameraObject*)m_pScene->GetGameObject("Camera");
    
    mat4* pMatView = pCamera->GetViewMatrix();
    mat4* pMatProj = pCamera->GetProjMatrix();


    m_pMesh->SetupAttributes(m_pMaterial->GetShader());
    m_pMesh->SetupUniforms(0, pMatView, pMatProj, campos, m_pMaterial, 0,0,0,0, 0);
    glDepthMask(GL_FALSE);
    m_pMesh->Draw(m_pMaterial->GetShader());
    glDepthMask(GL_TRUE);
}
