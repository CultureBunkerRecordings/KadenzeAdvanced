/*
  ==============================================================================

    KAPMainPanel.cpp
    Created: 20 Dec 2021 10:30:31pm
    Author:  William

  ==============================================================================
*/

#include "KAPMainPanel.h"
#include "KAPParameters.h"

KAPMainPanel::KAPMainPanel(NewProjectAudioProcessor* processor) : PanelBase(processor)
{
	setSize(MainPanelWidth, MainPanelHeight);
    mTopPanel = std::make_unique<KAPTopPanel>(processor);
    mTopPanel->setTopLeftPosition(0, 0);
    addAndMakeVisible(mTopPanel.get());

    mGainPanelIn = std::make_unique<KAPGainPanel>(processor);
    mGainPanelIn->setTopLeftPosition(0, TopPanelHeight);
    mGainPanelIn->setParameterID(kParameter_inputGain);
    addAndMakeVisible(mGainPanelIn.get());

    mGainPanelOut = std::make_unique<KAPGainPanel>(processor);
    mGainPanelOut->setTopLeftPosition(MainPanelWidth - GainPanelWidth, TopPanelHeight);
    mGainPanelOut->setParameterID(kParameter_outputGain);
    addAndMakeVisible(mGainPanelOut.get());

    mCentrePanel = std::make_unique<KAPCentrePanel>(processor);
    mCentrePanel->setTopLeftPosition(GainPanelWidth, TopPanelHeight);
    addAndMakeVisible(mCentrePanel.get());
}

KAPMainPanel::~KAPMainPanel()
{
};