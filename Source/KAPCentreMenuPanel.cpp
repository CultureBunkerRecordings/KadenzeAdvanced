/*
  ==============================================================================

    KAPCentreMenuPanel.cpp
    Created: 20 Dec 2021 10:30:15pm
    Author:  William

  ==============================================================================
*/

#include "KAPCentreMenuPanel.h"


KAPCentreMenuPanel::KAPCentreMenuPanel(NewProjectAudioProcessor* processor)
	: PanelBase(processor)
{
	setSize(CentreMenuPanelWidth, CentreMenuPanelHeight);

	const int width = 85;

	mFxTypeComboBox = std::make_unique<KAPParameterComboBox>(mPluginProcessor->parameters, KAPParameterID[kParameter_delayType]);
	mFxTypeComboBox->setBounds(getWidth() - width, 0, width, getHeight());
	mFxTypeComboBox->addItem("RAWRAY", 1);
	mFxTypeComboBox->addItem("RAWKUS", 2);
	mFxTypeComboBox->setSelectedItemIndex(static_cast<int>(mPluginProcessor->getParameter(kParameter_delayType)), juce::dontSendNotification);

	addAndMakeVisible(*mFxTypeComboBox);
}

KAPCentreMenuPanel::~KAPCentreMenuPanel()
{
	
};

void KAPCentreMenuPanel::addFxTypeComboboxListener(juce::ComboBox::Listener& inListener)
{
	mFxTypeComboBox->addListener(&inListener);
};
void KAPCentreMenuPanel::removeFxTypeComboboxListener(juce::ComboBox::Listener& inListener)
{
	mFxTypeComboBox->removeListener(&inListener);
};