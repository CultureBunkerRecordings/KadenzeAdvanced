/*
  ==============================================================================

    PanelBase.h
    Created: 20 Dec 2021 10:27:55pm
    Author:  William

  ==============================================================================
*/

#pragma once
#include <JuceHeader.h>
#include "PluginProcessor.h"
#include "KAPInterfaceDefines.h"

class PanelBase : public juce::Component
{
public:
    PanelBase(NewProjectAudioProcessor* processor);
    ~PanelBase();
    void paint(juce::Graphics& g) override;

protected:

    NewProjectAudioProcessor* mPluginProcessor;
};