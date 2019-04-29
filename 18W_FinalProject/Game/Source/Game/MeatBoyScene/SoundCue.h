#ifndef __SoundCue_H__
#define __SoundCue_H__

class SoundCue
{
public:

    SoundCue(SoundObject* array[], int size);
    virtual ~SoundCue();

    void Init(SoundObject* array[], int size);

	SoundObject* PlaySound();

protected:
    int m_SoundCount;
	int m_LastSoundIndex;
    std::vector<SoundObject*> m_Objects;

};
#endif //__SoundCue_H__
