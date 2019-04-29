#pragma once

enum StateType
{
    StateType_Colliding,
    StateType_NotColliding
};

class MultipleBallEvent : public Event
{
public:
    StateType m_StateType;

    MultipleBallEvent(StateType type)
    {
        m_EventType = EventType_Ball;
        m_StateType = type;
    }

};