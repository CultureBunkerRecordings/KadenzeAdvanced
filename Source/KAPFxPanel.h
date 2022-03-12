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

class KAPFxPanel : public PanelBase//, public juce::ComboBox::Listener
{
public:
    KAPFxPanel(NewProjectAudioProcessor* processor);
    ~KAPFxPanel();
    void paint(juce::Graphics& g) override;
    void setFxPanelStyle(FxPanelStyle style);
    //void comboBoxChanged(juce::ComboBox* comboBoxThatHasChanged) override;
private:
    FxPanelStyle mStyle;
    juce::OwnedArray<KAPParameterSlider> mSliders;
    juce::Typeface::Ptr tf;
    juce::Font myFont;
    juce::String mlabel;

    const juce::Font Font1 = juce::Font("Helvetica Neue", 12.0f, juce::Font::bold);
    const juce::Colour Colour5 = juce::Colour(105, 105, 105).withAlpha(0.3f);
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(KAPFxPanel)

};