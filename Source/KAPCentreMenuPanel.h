/*
  ==============================================================================

    KAPCentreMenuPanel.h
    Created: 20 Dec 2021 10:30:15pm
    Author:  William

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PanelBase.h"
#include "KAPParameterComboBoxh.h"

class KAPCentreMenuPanel : public PanelBase
{
public:
    KAPCentreMenuPanel(NewProjectAudioProcessor* processor);
    ~KAPCentreMenuPanel();
    void addFxTypeComboboxListener(juce::ComboBox::Listener* inListener);
    void removeFxTypeComboboxListener(juce::ComboBox::Listener* inListener);

private:
    std::unique_ptr<KAPParameterComboBox> mFxTypeComboBox;

};