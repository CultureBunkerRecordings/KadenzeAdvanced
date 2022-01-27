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

	const int meterWidth = 64;
	mVUmeter = std::make_unique<VUMeter>(processor);
	mVUmeter->setBounds((getWidth() * 0.5) - (meterWidth * 0.5), (getHeight() * 0.55) - (meterWidth * 0.5), meterWidth, getHeight() * 0.55);
	addAndMakeVisible(mVUmeter.get());
};
KAPGainPanel::~KAPGainPanel()
{
	delete(mParameterSlider);
};

void KAPGainPanel::setParameterID(int parameterID)
{
	mParameterSlider = new KAPParameterSlider(mPluginProcessor->parameters, KAPParameterID[parameterID]);
	const int slider_size = 54;
	mParameterSlider->setBounds((getWidth() * 0.5) - (slider_size * 0.5), (getHeight() * 0.25) - (slider_size * 0.5) - 10, slider_size, slider_size);
	addAndMakeVisible(mParameterSlider);

	mVUmeter->setParameterID(parameterID);
};

void KAPGainPanel::paint(juce::Graphics& g)
{
	PanelBase::paint(g);
	paintComponentLabel(g, mParameterSlider);
}
