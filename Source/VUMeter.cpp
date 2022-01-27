/*
  ==============================================================================

    VUMeter.cpp
    Created: 25 Jan 2022 2:16:49pm
    Author:  William

  ==============================================================================
*/

#include "VUMeter.h"
#include "KAPInterfaceDefines.h"
#include "KAPParameters.h"


VUMeter::VUMeter(NewProjectAudioProcessor* processor): mProcessor(processor), mParameterID(-1), channel0Level(0), channel1Level(0)
{
}

VUMeter::~VUMeter()
{
}

void VUMeter::paint(juce::Graphics& g)
{
    const int meterW = getWidth() / 3;
    g.setColour(Colour6);
    //left
    g.fillRect(0, 0, meterW, getHeight());
    //right
    g.fillRect(meterW * 2, 0, meterW, getHeight());

    int ch0Fill = getHeight() - (getHeight() * channel0Level);
    int ch1Fill = getHeight() - (getHeight() * channel1Level);

    if (ch0Fill < 0) {
        ch0Fill = 0;
    }

    if (ch1Fill < 0) {
        ch1Fill = 0;
    }

    g.setColour(Colour7);
    g.fillRect(0, ch0Fill, meterW, getHeight());
    g.fillRect(meterW * 2, ch1Fill, meterW, getHeight());

}

void VUMeter::setParameterID(int parameterID) 
{
    mParameterID = parameterID;
    startTimerHz(15);
}

void VUMeter::timerCallback()
{
    float updatedChannel0Level = 0.0f;
    float updatedChannel1Level = 0.0f;

    switch (mParameterID) 
    {
        case kParameter_inputGain: {
            updatedChannel0Level = mProcessor->getMeterInputLevel(0);
            updatedChannel1Level = mProcessor->getMeterInputLevel(1);
            break;
        }
        
        case kParameter_outputGain: {
            updatedChannel0Level = mProcessor->getMeterOutputLevel(0);
            updatedChannel1Level = mProcessor->getMeterOutputLevel(1);
            break;
        }
    }

    if (updatedChannel0Level > channel0Level) {
        channel0Level = updatedChannel0Level;
    }
    else {
        channel0Level = updatedChannel0Level;
        channel0Level = MeterSmoothing * (channel0Level - updatedChannel0Level) + updatedChannel0Level;
    }

    if (updatedChannel1Level > channel1Level) {
        channel1Level = updatedChannel1Level;
    }
    else {
        channel1Level = updatedChannel1Level;
        channel1Level = MeterSmoothing * (channel1Level - updatedChannel1Level) + updatedChannel1Level;
    }

    channel0Level = KAPDenormalise(channel0Level);
    channel1Level = KAPDenormalise(channel1Level);

    if (channel0Level && channel1Level) {
        repaint();
    }

}