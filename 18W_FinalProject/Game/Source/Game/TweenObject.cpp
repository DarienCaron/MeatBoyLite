#include "GamePCH.h"
#include "TweenObject.h"

TweenObject::TweenObject()
{

}

TweenObject::~TweenObject()
{

}

void TweenObject::Update(float deltatime)
{
   
    m_timeElapsed += deltatime;
}

void TweenObject::Setup(float startValue, float endValue, float totalTime, float Timeelapsed, Tweenfunctions func)
{
    m_startValue = startValue;
    m_endValue = endValue;
    m_totalTime = totalTime;
    m_timeElapsed = Timeelapsed;
    m_Tweenfunc = func;
   
}

float TweenObject::GetTween()
{
    return m_tweenFinal;
}
