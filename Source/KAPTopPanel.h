/*
  ==============================================================================

    KAPTopPanel.h
    Created: 20 Dec 2021 10:32:02pm
    Author:  William

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PanelBase.h"

class KAPTopPanel : public PanelBase, public juce::Button::Listener, public juce::ComboBox::Listener 
{
public:
    KAPTopPanel(NewProjectAudioProcessor* processor);
    ~KAPTopPanel();
    void buttonClicked(juce::Button*) override;
    void comboBoxChanged(juce::ComboBox* comboBoxThatHasChanged) override;

    void paint(juce::Graphics& g) override;
private:
    void displaySaveAsPopUp();
    void updatePresetComboBox();

    std::unique_ptr<juce::ComboBox> mPresetDisplay;
    std::unique_ptr<juce::TextButton> newPreset, savePreset, saveAsPreset;
};
