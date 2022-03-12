/*
  ==============================================================================

    KAPCentrePanel.cpp
    Created: 20 Dec 2021 10:29:48pm
    Author:  William

  ==============================================================================
*/

#include "KAPCentrePanel.h"

KAPCentrePanel::KAPCentrePanel(NewProjectAudioProcessor* processor)
	: PanelBase(processor)
{
	mCentreMenu = std::make_unique<KAPCentreMenuPanel>(processor);
	mCentreMenu->setTopLeftPosition(0, 0);
	setSize(CentrePanelWidth, CentrePanelHeight);
    mCentreMenu->addFxTypeComboboxListener(this);
	addAndMakeVisible(*mCentreMenu);

    mDelayPanel = std::make_unique<KAPFxPanel>(processor);
    mDelayPanel->setTopLeftPosition(0, CentreMenuPanelHeight);
    mDelayPanel->setFxPanelStyle(kFxPanelStyle_Delay);
    addChildComponent(mDelayPanel.get());

    mChorusPanel = std::make_unique<KAPFxPanel>(processor);
    mChorusPanel->setTopLeftPosition(0, CentreMenuPanelHeight);
    mChorusPanel->setFxPanelStyle(kFxPanelStyle_Chorus);
    addChildComponent(mChorusPanel.get());

    juce::AudioProcessorValueTreeState& tree = processor->parameters;

    const float panelToShow =
        *tree.getRawParameterValue(KAPParameterID[kParameter_delayType]);

    showPanel((int)panelToShow);
};
KAPCentrePanel::~KAPCentrePanel()
{
    mCentreMenu->removeFxTypeComboboxListener(this);
};

void KAPCentrePanel::showPanel(int inPanelID)
{
    switch (inPanelID) {
    case(kFxPanelStyle_Delay): {

        mDelayPanel->setVisible(true);
        mChorusPanel->setVisible(false);

    }break;

    case(kFxPanelStyle_Chorus): {

        mDelayPanel->setVisible(false);
        mChorusPanel->setVisible(true);

    }break;
    }
}

void KAPCentrePanel::comboBoxChanged(juce::ComboBox* comboBoxThatHasChanged)
{
	showPanel(comboBoxThatHasChanged->getSelectedItemIndex());
}
