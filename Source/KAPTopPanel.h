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

class KAPTopPanel : public PanelBase 
{
public:
    KAPTopPanel(NewProjectAudioProcessor* processor);
    ~KAPTopPanel();

    void paint(juce::Graphics& g) override;
private:
    void displaySaveAsPopUp();
    void updatePresetComboBox();

    std::unique_ptr<juce::ComboBox> mPresetDisplay;
    std::unique_ptr<juce::TextButton> newPreset, savePreset, saveAsPreset;
    juce::Typeface::Ptr tf;
    juce::Font myFont;

    const juce::Colour Colour1 = juce::Colour(105, 105, 105);
    const juce::Colour Colour2 = juce::Colour(0, 0, 0).withAlpha(0.0f);
    const juce::Colour Colour3 = juce::Colour(0, 0, 0).withAlpha(0.3f);
    const juce::Colour Colour4 = juce::Colour(0, 0, 0).withAlpha(0.6f);
    const juce::Colour Colour5 = juce::Colour(105, 105, 105).withAlpha(0.3f);
    const juce::Colour Colour6 = juce::Colour(0, 0, 0).withAlpha(0.8f);
    const juce::Colour Colour7 = juce::Colour(125, 125, 125);

    const juce::Font Font1 = juce::Font("Helvetica Neue", 12.0f, juce::Font::bold);

};
