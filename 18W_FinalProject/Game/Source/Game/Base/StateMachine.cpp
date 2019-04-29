#include "GamePCH.h"

StateMachine::StateMachine(GameObject * obj)
{
    m_pGameObject = obj;
}

StateMachine::~StateMachine()
{
}

void StateMachine::SetState(AIStateFunction state)
{
    m_pState = state;
    (m_pGameObject->*m_pState)(true, 0);
}

void StateMachine::Update(float deltatime)
{
    if(m_pState)
     (m_pGameObject->*m_pState)(false, deltatime);
}
