/*
  ==============================================================================

    KAPHelpers.h
    Created: 5 Dec 2021 9:56:17pm
    Author:  William

  ==============================================================================
*/

#pragma once

#include <juceHeader.h>

#define ParameterSmoothBlock 0.04f
#define ParameterSmoothSample 0.002f
#define MeterSmoothing 0.2f


const static int MaxBufferSize = 192000;

inline float KAPLinearInterpolation(float v0, float v1, float t)
{
    return (1 - t)* v0 + t * v1;
}

inline float KAPDenormalise(float value) 
{
    float absVal = fabs(value);

    if (absVal < 0.00000000000001) {
        return 0;
    } 
    else {
        return value;
    }
}

inline float dbToNormalisedGain(float inAudio) 
{
    float inAudioDb = juce::Decibels::gainToDecibels(inAudio + 0.000001f);
    inAudioDb = (inAudioDb + 96.0f) / 96.0f;
    return inAudioDb;
}
