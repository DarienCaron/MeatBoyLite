#ifndef __UnPauseEvent_H__
#define __UnPauseEvent_H__

class Scene;

class UnPauseEvent : public Event
{
protected:

    Scene* m_pScene;

public:
    UnPauseEvent(Scene* scene) // Declare the pause scene 
    {
        m_EventType = EventType_UnPause;
        m_pScene = scene;

    }

    EventTypes GetEventType() { return m_EventType; }
    Scene* GetScene() { return m_pScene; }

};

#endif //__UnPauseEvent_H__