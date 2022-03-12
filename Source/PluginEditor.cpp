/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
NewProjectAudioProcessorEditor::NewProjectAudioProcessorEditor (NewProjectAudioProcessor& p)
    : AudioProcessorEditor (&p), mBackground(juce::ImageCache::getFromMemory(BinaryData::kadenze_bg_png, BinaryData::kadenze_bg_pngSize)), audioProcessor(p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (MainPanelWidth, MainPanelHeight);
    mMainPanel = std::make_unique<KAPMainPanel>(&audioProcessor);
    mMainPanel->setTopLeftPosition(0, 0);
    mLookAndFeel = std::make_unique<KAPLookAndFeel>();
    setLookAndFeel(mLookAndFeel.get());
    juce::LookAndFeel::setDefaultLookAndFeel(mLookAndFeel.get());
    addAndMakeVisible(mMainPanel.get());
    
}

NewProjectAudioProcessorEditor::~NewProjectAudioProcessorEditor()
{
    setLookAndFeel(nullptr);
}

//==============================================================================
void NewProjectAudioProcessorEditor::paint (juce::Graphics& g)
{
    g.drawImage(mBackground, getBounds().toFloat());
}

void NewProjectAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
}
