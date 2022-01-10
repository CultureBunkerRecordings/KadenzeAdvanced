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
	addAndMakeVisible(*mCentreMenu);

	mFxPanel = std::make_unique<KAPFxPanel>(processor);
	mFxPanel->setTopLeftPosition(0, CentreMenuPanelHeight);
	addAndMakeVisible(*mFxPanel);

	mCentreMenu->addFxTypeComboboxListener(*mFxPanel);
};
KAPCentrePanel::~KAPCentrePanel()
{
	mCentreMenu->removeFxTypeComboboxListener(*mFxPanel);
};

