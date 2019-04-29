#ifndef __LevelWonEvent_H__
#define __LevelWonEvent_H__

class Scene;

class LevelWonEvent : public Event
{
protected:

    Scene* m_pScene;

public:
    LevelWonEvent(Scene* scene)
    {
        m_EventType = EventType_LevelWon;
        m_pScene = scene;

    }

    EventTypes GetEventType() { return m_EventType; }
    Scene* GetScene() { return m_pScene; }

};

#endif //__LevelWonEvent_H__
