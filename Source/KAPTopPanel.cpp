/*
  ==============================================================================

    KAPTopPanel.cpp
    Created: 20 Dec 2021 10:32:02pm
    Author:  William

  ==============================================================================
*/


#include "KAPTopPanel.h"

KAPTopPanel::KAPTopPanel(NewProjectAudioProcessor* processor)
	: PanelBase(processor)
{
	setSize(TopPanelWidth, TopPanelHeight);

	int buttonX = 15;
	const int buttonY = 10;
	const int buttonWidth = 55;
	const int buttonHeight = 25;

	newPreset = std::make_unique<juce::TextButton>();
	newPreset->setButtonText("New");
	newPreset->setBounds(buttonX, buttonY, buttonWidth, buttonHeight);
	newPreset->addListener(this);
	addAndMakeVisible(*newPreset);

	buttonX += buttonWidth;

	savePreset = std::make_unique<juce::TextButton>();
	savePreset->setButtonText("Save");
	savePreset->setBounds(buttonX, buttonY, buttonWidth, buttonHeight);
	savePreset->addListener(this);
	addAndMakeVisible(*savePreset);

	buttonX += buttonWidth;

	saveAsPreset = std::make_unique<juce::TextButton>();
	saveAsPreset->setButtonText("Save as");
	saveAsPreset->setBounds(buttonX, buttonY, buttonWidth, buttonHeight);
	saveAsPreset->addListener(this);
	addAndMakeVisible(*saveAsPreset);

	buttonX += buttonWidth;

	const int comboBoxWidth = 200;
	const int comboBoxX = TopPanelWidth * 0.5 - (comboBoxWidth * 0.5);

	mPresetDisplay = std::make_unique<juce::ComboBox>();

	mPresetDisplay->setBounds(comboBoxX, buttonY, comboBoxWidth, buttonHeight);
	mPresetDisplay->addListener(this);
	addAndMakeVisible(*mPresetDisplay);

	updatePresetComboBox();
};
KAPTopPanel::~KAPTopPanel()
{
	
};

void KAPTopPanel::paint(juce::Graphics& g)
{
	PanelBase::paint(g);
	g.drawFittedText("My Crazy Plugin", 0, 0, getWidth() - 10, getHeight(), juce::Justification::centredRight, 1);
}


void KAPTopPanel::buttonClicked(juce::Button* button) 
{
	KAPPresetManager* presetManager = mPluginProcessor->getPresetManager();

	if (button == newPreset.get())
	{
		presetManager->createNewPreset();
	}
	else if (button == savePreset.get())
	{
		presetManager->savePreset();
	}
	else if (button == saveAsPreset.get())
	{
		displaySaveAsPopUp();
	}
}


void KAPTopPanel::comboBoxChanged(juce::ComboBox* comboBoxThatHasChanged)
{

}

void KAPTopPanel::displaySaveAsPopUp()
{
	KAPPresetManager* presetManager = mPluginProcessor->getPresetManager();
	juce::String currentPresetName = presetManager->getCurrentPresetName();

	juce::AlertWindow window("Save as", "Please enter a name for your preset", juce::AlertWindow::NoIcon);
	window.centreAroundComponent(this, getWidth(), getHeight());
	window.addTextEditor("presetName", currentPresetName, "Preset Name: ");
	window.addButton("Confirm", 1);
	window.addButton("Cancel", 0);

	if (window.runModalLoop())
	{
		juce::String presetName = window.getTextEditor("presetName")->getText();
		presetManager->saveAsPreset(presetName);
	}

};

void KAPTopPanel::updatePresetComboBox()
{
	KAPPresetManager* presetManager = mPluginProcessor->getPresetManager();
	juce::String presetName = presetManager->getCurrentPresetName();

	mPresetDisplay->clear(juce::dontSendNotification);

	int numPresets = presetManager->getNumberOfPresets();

	for (int i = 0; i < numPresets; i++)
	{
		mPresetDisplay->addItem(presetManager->getPresetName(i), i + 1);

	}


};