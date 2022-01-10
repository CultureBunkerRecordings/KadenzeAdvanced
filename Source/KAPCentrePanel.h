/*
  ==============================================================================

    KAPCentrePanel.h
    Created: 20 Dec 2021 10:29:48pm
    Author:  William

  ==============================================================================
*/

#pragma once
#include <JuceHeader.h>
#include "PanelBase.h"
#include "KAPCentreMenuPanel.h"
#include "KAPFxPanel.h";

class KAPCentrePanel : public PanelBase
{
public:
    KAPCentrePanel(NewProjectAudioProcessor* processor);
    ~KAPCentrePanel();
private:
    std::unique_ptr<KAPCentreMenuPanel> mCentreMenu;
    std::unique_ptr<KAPFxPanel> mFxPanel;
};