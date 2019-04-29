#ifndef __BandageCollectedEvent_H__
#define __BandageCollectedEvent_H__

class Scene;

class BandageCollectedEvent : public Event
{
protected:

    Scene* m_pScene;

public:
    BandageCollectedEvent(Scene* scene)
    {
        m_EventType = EventType_BandageCollected;
        m_pScene = scene;
     
    }

    EventTypes GetEventType() { return m_EventType; }
    Scene* GetScene() { return m_pScene; }

};

#endif //__BandageCollectedEvent_H__

