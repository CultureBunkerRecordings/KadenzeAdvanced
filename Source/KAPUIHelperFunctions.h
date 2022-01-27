/*
  ==============================================================================

    KAPUIHelperFunctions.h
    Created: 3 Jan 2022 2:03:25pm
    Author:  William

  ==============================================================================
*/

#pragma once
#include <JuceHeader.h>
#include "KAPInterfaceDefines.h"

inline void paintComponentLabel(juce::Graphics& g, juce::Component* inComponent)
{
    const int x = inComponent->getX() - inComponent->getWidth() * 0.25f;
    const int y = inComponent->getY() + inComponent->getHeight();
    const int w = inComponent->getWidth() * 1.5f;
    const int h = 20;
    const juce::String label = inComponent->getName();

    const float cornerSize = 3.0f;

    g.setColour(Colour3);
    g.fillRoundedRectangle(x, y, w, h, cornerSize);

    g.setColour(Colour1);
    g.setFont(Font1);
    g.drawFittedText(label, x, y, w, h, juce::Justification::centred, 1);

}