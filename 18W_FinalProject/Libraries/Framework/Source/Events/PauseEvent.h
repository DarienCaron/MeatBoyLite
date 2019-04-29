#ifndef __PauseEvent_H__
#define __PauseEvent_H__

class Scene;

class PauseEvent : public Event
{
protected:

    Scene* m_pScene;

public:
    PauseEvent(Scene* scene) // Declare the pause scene 
    {
        m_EventType = EventType_Pause;
        m_pScene = scene;

    }

    EventTypes GetEventType() { return m_EventType; }
    Scene* GetScene() { return m_pScene; }

};

#endif //__PauseEvent_H__

