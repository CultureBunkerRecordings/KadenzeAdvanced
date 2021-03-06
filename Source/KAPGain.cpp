/*
  ==============================================================================

    KAPGain.cpp
    Created: 5 Dec 2021 9:56:49pm
    Author:  William

  ==============================================================================
*/

#include "KAPGain.h"
#include "KAPHelpers.h"

KAPGain::KAPGain() : mOutputSmoothed(0)
{
	
}

KAPGain::~KAPGain()
{
	
}

void KAPGain::process(float* audioIn, float gain, float* audioOut, int numSamplesToRender)
{

    float gainMapped = juce::jmap(gain, 0.0f, 1.0f, -24.0f, 24.0f);
    gainMapped = juce::Decibels::decibelsToGain(gainMapped, -24.0f);

    for(int i = 0; i < numSamplesToRender; i++)
    {
        audioOut[i] = audioIn[i] * gainMapped;
    }

    float absVal = fabs(audioOut[0]);
    mOutputSmoothed = MeterSmoothing * (mOutputSmoothed - absVal) + absVal;
}

float KAPGain::getMeterLevel() 
{
    return mOutputSmoothed;
}


