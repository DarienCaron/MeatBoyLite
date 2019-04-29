#ifndef __SetSceneToActiveEvent_H__
#define __SetSceneToActiveEvent_H__

class Scene;

class SetSceneToActiveEvent : public Event
{
protected:

    Scene* m_pScene;

public:
    SetSceneToActiveEvent(Scene* scene)
    {
        m_EventType = EventType_SetActiveScene;
        m_pScene = scene;
    }

    EventTypes GetEventType() { return m_EventType; }
    Scene* GetScene() { return m_pScene; }
};

#endif //__SetSceneToActiveEvent_H__
