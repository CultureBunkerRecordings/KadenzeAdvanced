/*
  ==============================================================================

    KAPInterfaceDefines.h
    Created: 20 Dec 2021 10:59:16pm
    Author:  William

  ==============================================================================
*/
#include <JuceHeader.h>

#pragma once

#define MainPanelWidth 750
#define MainPanelHeight 300

#define TopPanelWidth MainPanelWidth
#define TopPanelHeight 45

#define GainPanelWidth 100
#define GainPanelHeight MainPanelHeight - TopPanelHeight

#define CentrePanelWidth MainPanelWidth - (GainPanelWidth*2)
#define CentrePanelHeight GainPanelHeight

#define CentreMenuPanelWidth CentrePanelWidth
#define CentreMenuPanelHeight 35

#define FXPanelWidth CentrePanelWidth
#define FXPanelHeight CentrePanelHeight - CentreMenuPanelHeight


const juce::Colour Colour1 = juce::Colour(105, 105, 105);
const juce::Colour Colour2 = juce::Colour(0, 0, 0).withAlpha(0.0f);
const juce::Colour Colour3 = juce::Colour(0, 0, 0).withAlpha(0.3f);
const juce::Colour Colour4 = juce::Colour(0, 0, 0).withAlpha(0.6f);
const juce::Colour Colour5 = juce::Colour(105, 105, 105).withAlpha(0.3f);
const juce::Colour Colour6 = juce::Colour(0, 0, 0).withAlpha(0.8f);
const juce::Colour Colour7 = juce::Colour(125, 125, 125);

const juce::Font Font1("Helvetica Neue", 12.0f, juce::Font::bold);
const juce::Font Font2("Helvetica Neue", 22.0f, juce::Font::bold);
const juce::Font Font3("Helvetica Neue", 48.0f, juce::Font::bold);

