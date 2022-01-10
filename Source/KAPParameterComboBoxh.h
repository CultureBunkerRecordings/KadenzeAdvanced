/*
  ==============================================================================

    KAPParameterComboBoxh.h
    Created: 29 Dec 2021 11:13:43pm
    Author:  William

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

class KAPParameterComboBox : public juce::ComboBox
{
public:
    KAPParameterComboBox(juce::AudioProcessorValueTreeState& parameterToControl, juce::String& parameterID);
    ~KAPParameterComboBox();
private:
    std::unique_ptr<juce::AudioProcessorValueTreeState::ComboBoxAttachment> mAttachment;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(KAPParameterComboBox)


};