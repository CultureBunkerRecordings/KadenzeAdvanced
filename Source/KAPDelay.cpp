/*
  ==============================================================================

    KAPDelay.cpp
    Created: 5 Dec 2021 9:57:10pm
    Author:  William

  ==============================================================================
*/

#include "KAPDelay.h"
#include "JuceHeader.h"
#include "KAPHelpers.h"

KAPDelay::KAPDelay():mSampleRate(-1.0), mFeedbackSample(0), mDelayIndex(0), mTimeSmoothed(0.0f)
{
	
}
KAPDelay::~KAPDelay()
{
	
}

void KAPDelay::setSampleRate(double sampleRate)
{
	mSampleRate = sampleRate;
}
void KAPDelay::reset()
{
	mTimeSmoothed = 0.f;
	juce::zeromem(mBuffer, sizeof(double) * MaxBufferSize);
}

void KAPDelay::process(float* audioin, float time, float feedback, float mix, float inType, float* modulationBuffer, float* audioout, int numSamplesToRender)
{
	const float wet = mix;
	const float dry = 1.0f - wet;

	const float mappedFeedback = juce::jmap(feedback, 0.0f, 1.0f, 0.0f, 0.95f);


	for(int i = 0; i < numSamplesToRender; i++)
	{
		if((int)inType == kDelayType_Delay)
		{
			mTimeSmoothed = mTimeSmoothed - ParameterSmoothSample * (mTimeSmoothed - time);
		}
		else
		{
			double delayTimeModulation = 0.003 + 0.002 * modulationBuffer[0];
			mTimeSmoothed = mTimeSmoothed - ParameterSmoothSample * (mTimeSmoothed - (delayTimeModulation));
			
		}

		const double delayTimeInSamples = ((double)mTimeSmoothed) * mSampleRate;
		const double delaySample = getInterpolatedSample(delayTimeInSamples);

		mBuffer[mDelayIndex] = audioin[i] + (mFeedbackSample * mappedFeedback);

		mFeedbackSample = delaySample;

		audioout[i] = audioin[i]*dry + delaySample*wet;

		mDelayIndex += 1;

		if (mDelayIndex >= MaxBufferSize)
		{
			mDelayIndex -= MaxBufferSize;
		}
	}
	
}

double KAPDelay::getInterpolatedSample(double delayTimeinSamples)
{
	double readPos = static_cast<double>(mDelayIndex - delayTimeinSamples);

	if (readPos < 0.0)
	{
		readPos += MaxBufferSize;
	}

	int prev = static_cast<int>(readPos - 1);

	if(prev <= 0.0)
	{
		prev += MaxBufferSize;
	}

	int next = static_cast<int>(readPos);

	if (next > MaxBufferSize)
	{
		next -= MaxBufferSize;
	}

	float samplePrev = mBuffer[prev];
	float sampleNext = mBuffer[next];
	const float t = readPos - (int)readPos;

	double sampleOut = KAPLinearInterpolation(samplePrev, sampleNext, t);

	return sampleOut;
}

