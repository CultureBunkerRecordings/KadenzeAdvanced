/*
  ==============================================================================

    KAPPresetManager.h
    Created: 4 Jan 2022 3:39:40pm
    Author:  William

  ==============================================================================
*/

#pragma once
#include<JuceHeader.h>
static const juce::String Preset_File_Extention = ".pf";

class KAPPresetManager
{
public:
    KAPPresetManager(juce::AudioProcessor* processor);
    ~KAPPresetManager();
    void getXmlForPreset(juce::XmlElement* element);
    void loadPresetforXml(juce::XmlElement* element);

    int getNumberOfPresets();
    juce::String getPresetName(int presetIndex);
    void createNewPreset();
    void savePreset();
    void saveAsPreset(juce::String presetName);
    void loadPreset(int presetIndex);
    bool getIsCurrentPresetSaved();
    juce::String getCurrentPresetName();



private:
    void storeLocalPresets();

	bool misCurrentPresetSaved;
    juce::File mCurrentLoadedPreset;
    juce::Array<juce::File> mLocalPresets;
    juce::String mCurrentPresetName;
    juce::String mPresetDirectory;


    juce::XmlElement* mcurrentPresetXml;
    juce::AudioProcessor* mProcessor;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(KAPPresetManager)

};