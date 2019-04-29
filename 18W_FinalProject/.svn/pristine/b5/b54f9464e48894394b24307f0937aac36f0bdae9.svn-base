#ifndef __SetSceneToInactiveEvent_H__
#define __SetSceneToInactiveEvent_H__

class Scene;

class SetSceneToInactiveEvent : public Event
{
protected:

    Scene* m_pScene;

public:
    SetSceneToInactiveEvent(Scene* scene)
    {
        m_EventType = EventType_SetInactiveScene;
        m_pScene = scene;
    }

    EventTypes GetEventType() { return m_EventType; }
    Scene* GetScene() { return m_pScene; }
};

#endif //__SetSceneToInactiveEvent_H__
