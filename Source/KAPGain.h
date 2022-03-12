/*
  ==============================================================================

    KAPGain.h
    Created: 5 Dec 2021 9:56:49pm
    Author:  William

  ==============================================================================
*/

#pragma once

class KAPGain
{
public:
    KAPGain();
    ~KAPGain();
    void process(float* audioIn, float gain, float* audioOut, int numSamplesToRender);
    float getMeterLevel();
private:
    float mOutputSmoothed;  
};