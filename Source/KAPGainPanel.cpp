/*
  ==============================================================================

    KAPMainPanel.cpp
    Created: 20 Dec 2021 10:28:19pm
    Author:  William

  ==============================================================================
*/

#include "KAPGainPanel.h"
#include "KAPParameters.h"

KAPGainPanel::KAPGainPanel(NewProjectAudioProcessor* processor)
	: PanelBase(processor)
{
	setSize(GainPanelWidth, GainPanelHeight);
};
KAPGainPanel::~KAPGainPanel()
{
	delete(mParameterSlider);
};

void KAPGainPanel::setParameterID(int parameterID)
{
	mParameterSlider = new KAPParameterSlider(mPluginProcessor->parameters, KAPParameterID[parameterID]);
	const int slider_size = 54;
	mParameterSlider->setBounds((getWidth() * 0.5) - (slider_size * 0.5), (getHeight() * 0.5) - (slider_size * 0.5), slider_size, slider_size);
	addAndMakeVisible(mParameterSlider);
};

void KAPGainPanel::paint(juce::Graphics& g)
{
	PanelBase::paint(g);
	paintComponentLabel(g, mParameterSlider);
}
