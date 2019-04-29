#ifndef __PushSceneEvent_H__
#define __PushSceneEvent_H__

class Scene;

class PushSceneEvent : public Event
{
protected:
   
    Scene* m_pScene;

public:
    PushSceneEvent(Scene* scene)
    {
        m_EventType = EventType_PushScene;
        m_pScene = scene;
    }

    EventTypes GetEventType() { return m_EventType; }
    Scene* GetScene() { return m_pScene; }
};

#endif //__PushSceneEvent_H__
