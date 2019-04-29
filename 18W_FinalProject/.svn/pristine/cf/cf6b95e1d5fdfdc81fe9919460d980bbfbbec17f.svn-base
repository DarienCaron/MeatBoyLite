#include "GamePCH.h"

BloodChunkObject::BloodChunkObject(Scene * pScene, std::string name, vec3 pos, vec3 rot, vec3 scale, Mesh * pMesh, Material * a_material)
:GameObject(pScene, name, pos, rot, scale, pMesh, a_material)
{
    m_Pool = 0;
    m_AnimationTimer = 0;
}

BloodChunkObject::BloodChunkObject(Scene * pScene, std::string name, vec3 pos, vec3 rot, vec3 scale, std::string meshname, std::string material)
    : GameObject(pScene, name, pos, rot, scale, meshname, material)
{
    m_Pool = 0;
    m_AnimationTimer = 0;
}

BloodChunkObject::~BloodChunkObject()
{
    
}

void BloodChunkObject::Update(float deltatime)
{
    GameObject::Update(deltatime);

    if (m_IsActivated == true)
    {
        m_AnimationTimer += deltatime;
        if (m_AnimationTimer >= 0.2f)
        {
            Material* mat = m_pScene->GetResourceManager()->GetMaterial("BloodGib_Animation1_Mat");
            SetMaterial(mat);
            if (m_AnimationTimer >= 0.3f)
            {
                Material* mat = m_pScene->GetResourceManager()->GetMaterial("BloodGib_Animation2_Mat");
                SetMaterial(mat);
                if (m_AnimationTimer >= 0.5f)
                {
                    Material* mat = m_pScene->GetResourceManager()->GetMaterial("BloodGib_Animation3_Mat");
                    SetMaterial(mat);
                   
                }
            }
        }
    }

    if (m_AnimationTimer >= 0.6f)
    {
        m_AnimationTimer = 0;
        m_IsActivated = false;
        m_Destroy = true;
        Material* mat = m_pScene->GetResourceManager()->GetMaterial("BloodGib_Animation1_Mat");
        SetMaterial(mat);
    }

    if (m_Destroy == true)
    {
        RemoveFromPoolEvent* pEvent2 = new RemoveFromPoolEvent(this);
        m_pScene->GetGame()->QueueEvent(pEvent2);
        m_Destroy = false;
    }
}

void BloodChunkObject::SetPool(SimplePool<GameObject>* Pool)
{
    m_Pool = Pool;

    
}

void BloodChunkObject::Destroy()
{

}

void BloodChunkObject::BeginContact(b2Fixture * pOtherFixture, vec2 worldPosition, vec2 worldNormal)
{
    GameObject::BeginContact(pOtherFixture, worldPosition, worldNormal);
  
}

void BloodChunkObject::EndContact(b2Fixture * pOtherFixture)
{
    GameObject::EndContact(pOtherFixture);
}
