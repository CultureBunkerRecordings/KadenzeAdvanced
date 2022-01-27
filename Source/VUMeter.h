/*
  ==============================================================================

    VUMeter.h
    Created: 25 Jan 2022 2:16:49pm
    Author:  William

  ==============================================================================
*/

#pragma once

#include <juceheader.h>
#include "PluginProcessor.h"

class VUMeter : public juce::Component, juce::Timer
{
public:
    VUMeter(NewProjectAudioProcessor* processor);
    ~VUMeter();

    void paint(juce::Graphics& g) override;

    void setParameterID(int ParameterID);

    void timerCallback() override;

private:
    NewProjectAudioProcessor* mProcessor;
    int mParameterID;

    float channel0Level;
    float channel1Level;


};