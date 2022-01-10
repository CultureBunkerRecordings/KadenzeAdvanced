/*
  ==============================================================================

    PanelBase.cpp
    Created: 20 Dec 2021 10:27:55pm
    Author:  William

  ==============================================================================
*/

#include "PanelBase.h"


PanelBase::PanelBase(NewProjectAudioProcessor* processor) : mPluginProcessor(processor)
{

};

PanelBase::~PanelBase()
{
	
};

void PanelBase::paint(juce::Graphics& g)
{
    g.setColour(juce::Colours::whitesmoke);
    g.fillAll();
    g.setColour(juce::Colours::black);
    g.drawRect(0, 0, getWidth(), getHeight(), 2);
};