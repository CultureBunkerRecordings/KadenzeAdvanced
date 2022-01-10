/*
  ==============================================================================

    KAPParameterSlider.cpp
    Created: 29 Dec 2021 11:12:48pm
    Author:  William

  ==============================================================================
*/

#include "KAPParameterSlider.h"

KAPParameterSlider::KAPParameterSlider(juce::AudioProcessorValueTreeState& parameterToControl, juce::String& parameterID)
	: juce::Slider(parameterID)
{
	setSliderStyle(SliderStyle::RotaryHorizontalVerticalDrag);
	setTextBoxStyle(juce::Slider::TextEntryBoxPosition::TextBoxBelow, false, 0, 0);
	setRange(0.0f, 1.0f, 0.001f);
	mAttachment = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(parameterToControl, parameterID, *this);
};

KAPParameterSlider::~KAPParameterSlider()
{
	
};