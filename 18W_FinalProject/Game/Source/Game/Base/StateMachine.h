#ifndef __StateMachine_H__
#define __StateMachine_H__

class StateMachine;
typedef void (GameObject::*AIStateFunction)(bool enteringstate, float deltatime);


class StateMachine
{
public:
    StateMachine(GameObject* obj);
    ~StateMachine();

    void SetState(AIStateFunction state);
    void Update(float deltatime);

protected:
    GameObject* m_pGameObject;
    AIStateFunction m_pState;
};





#endif //__StateMachine_H__