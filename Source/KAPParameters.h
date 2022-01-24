/*
  ==============================================================================

    KAPParameters.h
    Created: 29 Dec 2021 9:48:11pm
    Author:  William

  ==============================================================================
*/

#pragma once

enum KAPParameter
{
	kParameter_inputGain = 0,
    kParameter_delayTime,
    kParameter_delayFeedback,
    kParameter_delayWetDry,
    kParameter_delayType, //chorus or delay?
    kParameter_modRate,
    kParameter_modDepth,
    kParameter_outputGain,
    kParameter_totalNumParams

};

static juce::String KAPParameterID [kParameter_totalNumParams] =
{
	"InputGain",
    "DelayTime",
    "Feedback",
	"WetDry",
    "Type",
    "Rate",
    "Depth",
    "OutputGain"
};
