/*
  ==============================================================================

    KAPLfo.h
    Created: 5 Dec 2021 9:57:26pm
    Author:  William

  ==============================================================================
*/

#pragma once
#include "KAPHelpers.h"

class KAPLfo
{
public:
    KAPLfo();
    ~KAPLfo();
    void reset();
    void setSampleRate(double sampleRate);
    void process(float rate, float depth, int numSamples);
    float* getBuffer();

private:
    double mSampleRate;
    float mPhase;
    float mBuffer[MaxBufferSize];
};