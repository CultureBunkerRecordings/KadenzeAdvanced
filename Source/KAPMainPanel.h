/*
  ==============================================================================

    KAPMainPanel.h
    Created: 20 Dec 2021 10:30:31pm
    Author:  William

  ==============================================================================
*/

#pragma once
#include <JuceHeader.h>
#include "PanelBase.h"
#include "KAPTopPanel.h"
#include "KAPGainPanel.h"
#include "KAPCentrePanel.h"

class KAPMainPanel : public PanelBase
{
public:
    KAPMainPanel(NewProjectAudioProcessor* processor);
    ~KAPMainPanel();

private:
    std::unique_ptr<KAPTopPanel> mTopPanel;
    std::unique_ptr<KAPGainPanel> mGainPanelIn;
    std::unique_ptr<KAPGainPanel> mGainPanelOut;
    std::unique_ptr<KAPCentrePanel> mCentrePanel;
};