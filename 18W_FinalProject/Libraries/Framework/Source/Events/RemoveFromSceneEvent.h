#ifndef __RemoveFromSceneEvent_H__
#define __RemoveFromSceneEvent_H__
class GameObject;
class RemoveFromSceneEvent : public Event
{
public:
    RemoveFromSceneEvent(GameObject* obj)
    {
        m_Object = obj;
        m_EventType = EventType_RemoveFromScene;
    }
    GameObject* GetGameObject() { return m_Object; }
protected:
    GameObject* m_Object;
};
#endif //__RemoveFromSceneEvent_H__
