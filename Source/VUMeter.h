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

    const juce::Colour Colour1 = juce::Colour(105, 105, 105);
    const juce::Colour Colour2 = juce::Colour(0, 0, 0).withAlpha(0.0f);
    const juce::Colour Colour3 = juce::Colour(0, 0, 0).withAlpha(0.3f);
    const juce::Colour Colour4 = juce::Colour(0, 0, 0).withAlpha(0.6f);
    const juce::Colour Colour5 = juce::Colour(105, 105, 105).withAlpha(0.3f);
    const juce::Colour Colour6 = juce::Colour(0, 0, 0).withAlpha(0.8f);
    const juce::Colour Colour7 = juce::Colour(125, 125, 125);
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(VUMeter)

};