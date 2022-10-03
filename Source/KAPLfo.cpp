/*
  ==============================================================================

    KAPLfo.cpp
    Created: 5 Dec 2021 9:57:26pm
    Author:  William

  ==============================================================================
*/

#define _USE_MATH_DEFINES
#include <math.h>
#include <JuceHeader.h>
#include "KAPLfo.h"


KAPLfo::KAPLfo(): mSampleRate(-1), mPhase(0.0f), mBuffer{0}  
{
	reset();
};
KAPLfo::~KAPLfo()
{
	
};
void KAPLfo::reset()
{
	mPhase = 0.0;
	juce::zeromem(mBuffer, MaxBufferSize * sizeof(float));
};
void KAPLfo::setSampleRate(double sampleRate)
{
	mSampleRate = sampleRate;
};
void KAPLfo::process(float rate, float depth, int numSamples)
{
	float mappedRate = juce::jmap(rate, 0.f, 1.f, 0.01f, 10.0f);

	for(int i = 0; i < numSamples; i++)
	{
		mPhase = mPhase + (mappedRate / mSampleRate);
		if (mPhase > 1.0f)
		{
			mPhase -= 1.0f;
		}

		const float lfoPos = sinf(mPhase * M_PI_2) * depth;
		mBuffer[i] = lfoPos;
	}

	
};

float* KAPLfo::getBuffer()
{
	return mBuffer;
}
