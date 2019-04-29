#ifndef __PopBackEvent_H__
#define __PopBackEvent_H__

class Scene;

class PopBackEvent : public Event
{
protected:

    Scene* m_pScene;

public:
    PopBackEvent(Scene* scene)
    {
        m_EventType = EventType_PopBackScene;
        m_pScene = scene;
    }

    EventTypes GetEventType() { return m_EventType; }
    Scene* GetScene() { return m_pScene; }
};

#endif //__PopBackEvent_H__
