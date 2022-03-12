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
	: PanelBase(processor), tf(nullptr)
{
	setSize(FXPanelWidth, FXPanelHeight);
	/*/tf = juce::Typeface::createSystemTypefaceFor(BinaryData::Higher_Jump_ttf, BinaryData::Higher_Jump_ttfSize);
	myFont = juce::Font(tf);
	myFont.setHeight(80.0f);*/

	FxPanelStyle currentStyle = (FxPanelStyle)mPluginProcessor->getParameter(kParameter_delayType);
	setFxPanelStyle(currentStyle);

};
KAPFxPanel::~KAPFxPanel()
{
	
};

void KAPFxPanel::paint(juce::Graphics& g)
{
	PanelBase::paint(g);
	
	g.setColour(Colour5);
	g.setFont(Font1);
	g.drawText(mlabel, 0, 0, getWidth(), 80, juce::Justification::centred, false);

	for(int i = 0; i<mSliders.size(); i++)
	{
		paintComponentLabel(g, mSliders[i]);
	}

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

			mlabel = "Delay";

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

			mlabel = "Chorus";

			break;

			
		}



		case kFxPanelStyleTotalNumStyles:
		{
			jassertfalse;
			break;
		}

	}
}

/*void KAPFxPanel::comboBoxChanged(juce::ComboBox* comboBoxThatHasChanged)
{
	FxPanelStyle style = static_cast<FxPanelStyle>(comboBoxThatHasChanged->getSelectedItemIndex());
	setFxPanelStyle(style);
};*/

