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

	tf = juce::Typeface::createSystemTypefaceFor(BinaryData::Higher_Jump_ttf, BinaryData::Higher_Jump_ttfSize);
	myFont = juce::Font(tf);
	myFont.setHeight(30.0f);

	int buttonX = 15;
	const int buttonY = 10;
	const int buttonWidth = 55;
	const int buttonHeight = 25;

	newPreset = std::make_unique<juce::TextButton>();
	newPreset->setButtonText("New");
	newPreset->setBounds(buttonX, buttonY, buttonWidth, buttonHeight);
	newPreset->onClick = [this] {
		mPluginProcessor->getPresetManager()->createNewPreset();
		updatePresetComboBox();
	};	
	addAndMakeVisible(*newPreset);

	buttonX += buttonWidth;

	savePreset = std::make_unique<juce::TextButton>();
	savePreset->setButtonText("Save");
	savePreset->setBounds(buttonX, buttonY, buttonWidth, buttonHeight);
	savePreset->onClick = [this] {
		if (mPluginProcessor->getPresetManager()->getIsCurrentPresetSaved()) {
			mPluginProcessor->getPresetManager()->savePreset();
		}
		else {
			displaySaveAsPopUp();
		}
		updatePresetComboBox();
	};	
	addAndMakeVisible(*savePreset);

	buttonX += buttonWidth;

	saveAsPreset = std::make_unique<juce::TextButton>();
	saveAsPreset->setButtonText("Save as");
	saveAsPreset->setBounds(buttonX, buttonY, buttonWidth, buttonHeight);
	saveAsPreset->onClick = [this] {
		displaySaveAsPopUp();
		updatePresetComboBox();
	};
	addAndMakeVisible(*saveAsPreset);

	buttonX += buttonWidth;

	const int comboBoxWidth = 200;
	const int comboBoxX = TopPanelWidth * 0.5 - (comboBoxWidth * 0.5);

	mPresetDisplay = std::make_unique<juce::ComboBox>();

	mPresetDisplay->setBounds(comboBoxX, buttonY, comboBoxWidth, buttonHeight);
	mPresetDisplay->onChange = [this] {
		mPluginProcessor->getPresetManager()->loadPreset(mPresetDisplay->getSelectedItemIndex());
	};	
	addAndMakeVisible(mPresetDisplay.get());

	updatePresetComboBox();
};
KAPTopPanel::~KAPTopPanel()
{
	
};

void KAPTopPanel::paint(juce::Graphics& g)
{
	PanelBase::paint(g);

	g.setColour(Colour1);
	g.setFont(Font1);

	const int w = 220;
	g.drawFittedText("RAWKUS RAWRAY", TopPanelWidth - w - 20, 0, w, getHeight(), juce::Justification::centredRight, 1);
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

	if (window.runModalLoop() != 0) {
		juce::String presetName = window.getTextEditor("presetName")->getText();
		presetManager->saveAsPreset(presetName);
	}
};

void KAPTopPanel::updatePresetComboBox()
{
	KAPPresetManager* presetManager = mPluginProcessor->getPresetManager();
	juce::String presetName = presetManager->getCurrentPresetName();

	mPresetDisplay->clear(juce::dontSendNotification);
	const int numPresets = presetManager->getNumberOfPresets();
	for (int i = 0; i < numPresets; i++) {
		mPresetDisplay->addItem(presetManager->getPresetName(i), (i + 1));
	}

	mPresetDisplay->setText(presetName, juce::dontSendNotification);


};