/*
  ==============================================================================

    KAPGainPanel.h
    Created: 20 Dec 2021 10:28:19pm
    Author:  William

  ==============================================================================
*/

#pragma once
#include <JuceHeader.h>
#include "PanelBase.h"
#include "KAPParameterSlider.h"
#include "KAPUIHelperFunctions.h"
#include "VUMeter.h"

class KAPGainPanel : public PanelBase 
{
public:
    KAPGainPanel(NewProjectAudioProcessor* processor);
    ~KAPGainPanel();
    void setParameterID(int parameterID);
    void paint(juce::Graphics& g) override;
private:
    KAPParameterSlider* mParameterSlider;
    std::unique_ptr<VUMeter> mVUmeter;
};
