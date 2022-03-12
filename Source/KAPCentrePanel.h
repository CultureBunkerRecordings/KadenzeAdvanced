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

class KAPCentrePanel : public PanelBase, public juce::ComboBox::Listener
{
public:
    KAPCentrePanel(NewProjectAudioProcessor* processor);
    ~KAPCentrePanel();
    void showPanel(int inPanelID);
    
private:
    void comboBoxChanged(juce::ComboBox* comboBoxThatHasChanged) override;
    std::unique_ptr<KAPCentreMenuPanel> mCentreMenu;
    std::unique_ptr<KAPFxPanel> mDelayPanel;
    std::unique_ptr<KAPFxPanel> mChorusPanel;
};