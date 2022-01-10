/*
  ==============================================================================

    KAPParameterSlider.h
    Created: 29 Dec 2021 11:12:48pm
    Author:  William

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

class KAPParameterSlider : public juce::Slider
{
public:
    KAPParameterSlider(juce::AudioProcessorValueTreeState& parameterToControl, juce::String& parameterID);
    ~KAPParameterSlider();
private:
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> mAttachment;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(KAPParameterSlider)


};
