/*
  ==============================================================================

    KAPDelay.h
    Created: 5 Dec 2021 9:57:10pm
    Author:  William

  ==============================================================================
*/

#pragma once
#include "KAPHelpers.h"

enum KAPDelayType
{
	kDelayType_Delay = 0,
    kDelayType_Chorus
};

class KAPDelay
{
public:
    KAPDelay();
    ~KAPDelay();

    void setSampleRate(double sampleRate);
    void reset();
    void process(float* audioin, float time, float feedback, float mix, float inType, float* modulationBuffer, float* audioout, int numSamplesToRender);
    double getInterpolatedSample(double delayTimeInSamples);

private:
    double mSampleRate;
    double mBuffer[192000];

	double mFeedbackSample;
    int mDelayIndex;
    float mTimeSmoothed;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(KAPDelay)

};