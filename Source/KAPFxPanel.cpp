/*
  ==============================================================================

    KAPFxPanel.cpp
    Created: 20 Dec 2021 10:31:01pm
    Author:  William

  ==============================================================================
*/

#include "KAPFxPanel.h"
#include "KAPUIHelperFunctions.h"

KAPFxPanel::KAPFxPanel(NewProjectAudioProcessor* processor)
	: PanelBase(processor)
{
	setSize(FXPanelWidth, FXPanelHeight);
	FxPanelStyle currentStyle = (FxPanelStyle)mPluginProcessor->getParameter(kParameter_delayType);
	setFxPanelStyle(currentStyle);

};
KAPFxPanel::~KAPFxPanel()
{
	
};

void KAPFxPanel::paint(juce::Graphics& g)
{
	PanelBase::paint(g);

	switch(mStyle)
	{
		case kFxPanelStyle_Delay:
		{
			g.drawFittedText("DELAY", 0, 0, getWidth(), getHeight() * 0.75f, juce::Justification::centred, 1);
			break;
		}
		case kFxPanelStyle_Chorus:
		{
			g.drawFittedText("CHORUS", 0, 0, getWidth(), getHeight() * 0.75f, juce::Justification::centred, 1);
			break;
		}
		default:
		case kFxPanelStyleTotalNumStyles:
		{
			jassertfalse;
			break;
		}
	}

	for(int i = 0; i<mSliders.size(); i++)
	{
		paintComponentLabel(g, mSliders[i]);
	}

	repaint();
}


void KAPFxPanel::setFxPanelStyle(FxPanelStyle style)
{
	mStyle = style;
	mSliders.clear();
	int slider_Size = 56;
	int x = 130;
	int y = (getHeight() * 0.5) - (slider_Size * 0.5);


	switch (mStyle)
	{
	case kFxPanelStyle_Delay:
	{
		KAPParameterSlider* time = new KAPParameterSlider(mPluginProcessor->parameters, KAPParameterID[kParameter_delayTime]);
		time->setBounds(x, y, slider_Size, slider_Size);
		addAndMakeVisible(time);
		mSliders.add(time);

		x = x + slider_Size * 2;

		KAPParameterSlider* feedback = new KAPParameterSlider(mPluginProcessor->parameters, KAPParameterID[kParameter_delayFeedback]);
		feedback->setBounds(x, y, slider_Size, slider_Size);
		addAndMakeVisible(feedback);
		mSliders.add(feedback);

		x = x + slider_Size * 2;

		KAPParameterSlider* wetDry = new KAPParameterSlider(mPluginProcessor->parameters, KAPParameterID[kParameter_delayWetDry]);
		wetDry->setBounds(x, y, slider_Size, slider_Size);
		addAndMakeVisible(wetDry);
		mSliders.add(wetDry);
		break;
	}


	case kFxPanelStyle_Chorus:
	{
		KAPParameterSlider* rate = new KAPParameterSlider(mPluginProcessor->parameters, KAPParameterID[kParameter_modRate]);
		rate->setBounds(x, y, slider_Size, slider_Size);
		addAndMakeVisible(rate);
		mSliders.add(rate);

		x = x + slider_Size * 2;

		KAPParameterSlider* depth = new KAPParameterSlider(mPluginProcessor->parameters, KAPParameterID[kParameter_modDepth]);
		depth->setBounds(x, y, slider_Size, slider_Size);
		addAndMakeVisible(depth);
		mSliders.add(depth);

		x = x + slider_Size * 2;

		KAPParameterSlider* wetDry = new KAPParameterSlider(mPluginProcessor->parameters, KAPParameterID[kParameter_delayWetDry]);
		wetDry->setBounds(x, y, slider_Size, slider_Size);
		addAndMakeVisible(wetDry);
		mSliders.add(wetDry);

		break;
	}



	case kFxPanelStyleTotalNumStyles:
	{
		jassertfalse;
		break;
	}

	}
}

void KAPFxPanel::comboBoxChanged(juce::ComboBox* comboBoxThatHasChanged)
{
	FxPanelStyle style = static_cast<FxPanelStyle>(comboBoxThatHasChanged->getSelectedItemIndex());
	setFxPanelStyle(style);
};

