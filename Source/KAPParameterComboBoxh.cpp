/*
  ==============================================================================

    KAPParameterComboBoxh.cpp
    Created: 29 Dec 2021 11:13:43pm
    Author:  William

  ==============================================================================
*/

#include "KAPParameterComboBoxh.h"

KAPParameterComboBox::KAPParameterComboBox(juce::AudioProcessorValueTreeState& parameterToControl, juce::String& parameterID)
	:ComboBox(parameterID)
{
	mAttachment = std::make_unique<juce::AudioProcessorValueTreeState::ComboBoxAttachment>(parameterToControl, parameterID, *this);
};
KAPParameterComboBox::~KAPParameterComboBox()
{
	
};