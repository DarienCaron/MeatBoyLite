#include "GamePCH.h"

SoundCue::SoundCue(SoundObject * soundarray[], int size)
{
    Init(soundarray, size);
}

SoundCue::~SoundCue()
{
}

void SoundCue::Init(SoundObject * soundarray[], int size)
{
	m_SoundCount = size;
	for (int i = 0; i < size; i++)
	{
        m_Objects.push_back(soundarray[i]);
	}
	m_LastSoundIndex = 0;
}

SoundObject * SoundCue::PlaySound()
{
	// generate a random number
	int digit = (int)(randFromNegativeOneToOne() * m_SoundCount);

	if (digit < 0)
		digit *= -1;




	// Check if the random number hasn't been used

	if (digit != m_LastSoundIndex)
	{
		m_LastSoundIndex = digit;
		return m_Objects.at(m_LastSoundIndex);
	}
	else
	{
		return m_Objects.at(digit);
	}

	return 0;
		// set the random number
		// return the sound at the selected index

}
