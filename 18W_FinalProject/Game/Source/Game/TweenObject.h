#ifndef __TweenObject_H__
#define __TweenObject_H__

typedef float(*TweenFunction)(float startvalue, float valuerange,
    double timepassed, double totaltime);

enum Tweenfunctions
{
    TweenTypeLinear,
    TweenTypeEaseIn,
    TweenTypeBounceIn

};

class TweenObject
{
public:
    
    TweenObject();
    ~TweenObject();
    void Update(float deltatime);

    float* variable;
    float m_startValue;
    float m_endValue;
    float m_totalTime;
    float m_timeElapsed;

    float m_tweenFinal;

    Tweenfunctions m_Tweenfunc;
    void Setup(float startValue, float endValue, float totalTime, float Timeelapsed, Tweenfunctions func);

    float GetTween();
    

};

#endif //__TweenObject_H__