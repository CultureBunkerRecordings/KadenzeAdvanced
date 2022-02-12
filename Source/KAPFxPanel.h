/*
  ==============================================================================

    KAPFxPanel.h
    Created: 20 Dec 2021 10:31:01pm
    Author:  William

  ==============================================================================
*/

#pragma once
#include <JuceHeader.h>
#include "PanelBase.h"
#include "KAPParameterSlider.h"


enum FxPanelStyle
{
    kFxPanelStyle_Delay,
    kFxPanelStyle_Chorus,
    kFxPanelStyleTotalNumStyles
};

class KAPFxPanel : public PanelBase, public juce::ComboBox::Listener
{
public:
    KAPFxPanel(NewProjectAudioProcessor* processor);
    ~KAPFxPanel();
    void paint(juce::Graphics& g) override;
    void setFxPanelStyle(FxPanelStyle style);
    void comboBoxChanged(juce::ComboBox* comboBoxThatHasChanged) override;
private:
    FxPanelStyle mStyle;
    juce::OwnedArray<KAPParameterSlider> mSliders;
    juce::Typeface::Ptr tf;
    juce::Font myFont;
};