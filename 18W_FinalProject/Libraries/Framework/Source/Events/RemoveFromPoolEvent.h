#ifndef __RemoveFromPoolEvent_H__
#define __RemoveFromPoolEvent_H__
class GameObject;
class RemoveFromPoolEvent : public Event
{
public:
    RemoveFromPoolEvent(GameObject* obj)
    {
        m_Object = obj;
        m_EventType = EventType_RemoveFromPool;
    }
    GameObject* GetGameObject() { return m_Object; }
protected:
    GameObject* m_Object;
};
#endif //__RemoveFromSceneEvent_H__
