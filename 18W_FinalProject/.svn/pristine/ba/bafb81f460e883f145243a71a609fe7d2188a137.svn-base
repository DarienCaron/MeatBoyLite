#include "GamePCH.h"

SceneManager::SceneManager()
{
    m_RenderToTextureScene = 0;
    m_RenderToTextureScene2 = 0;
}

SceneManager::~SceneManager()
{
    for (auto object : m_pScenes)
        delete object.second;
}

void SceneManager::LoadContent()
{
    for (auto object : m_pScenes)
    {
        object.second->LoadContent();
    }
}

void SceneManager::OnEvent(Event * pEvent)
{
    
    
  
    if (pEvent->GetEventType() == EventType_PushScene)
    {
        PushSceneEvent* pActiveEvent = (PushSceneEvent*)pEvent;
        std::string pName = pActiveEvent->GetScene()->GetName();
        PushScene(pName);
    }
    if (pEvent->GetEventType() == EventType_PopBackScene)
    {
        PopBackEvent* pInactiveEvent = (PopBackEvent*)pEvent;
        std::string name = pInactiveEvent->GetScene()->GetName();
        PopScene();
    }

    for (unsigned int i = m_ActiveScenes.size() - 1; m_ActiveScenes.size() > i; --i)
    {
        m_ActiveScenes[i]->OnEvent(pEvent);

    }


}

void SceneManager::Update(float deltatime)
{


    for (unsigned int i = m_ActiveScenes.size() - 1; m_ActiveScenes.size() > i; --i)
    {
        m_ActiveScenes[i]->Update(deltatime);
    }



    if (m_ActiveScenes.back() == GetScene("Level Select"))
    {
        m_RenderToTextureScene->Update(deltatime);


        m_RenderToTextureScene2->Update(deltatime);
    }



}

void SceneManager::Draw()
{
    for (unsigned int i = 0; i < m_ActiveScenes.size(); i++)
    {

        m_ActiveScenes.at(i)->Draw();
    }
}

void SceneManager::PushScene(std::string name)
{
    m_ActiveScenes.push_back((this->GetScene(name)));

  
}

void SceneManager::PopScene()
{
    m_ActiveScenes.pop_back();
   

}
