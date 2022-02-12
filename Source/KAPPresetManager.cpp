/*
  ==============================================================================

    KAPPresetManager.cpp
    Created: 4 Jan 2022 3:39:40pm
    Author:  William

  ==============================================================================
*/

#include "KAPPresetManager.h"

#if JUCE_WINDOWS
static const juce::String seperator = "\\";

#elif JUCE_MAC
static const juce::String seporator = "/";
#endif

KAPPresetManager::KAPPresetManager(juce::AudioProcessor* processor): misCurrentPresetSaved(false), mCurrentPresetName("Untitled"), mProcessor(processor)
{
	const juce::String pluginName = (juce::String)mProcessor->getName();
	mPresetDirectory = juce::File::getSpecialLocation(juce::File::userDocumentsDirectory).getFullPathName() + seperator + pluginName;

	if (!juce::File(mPresetDirectory).exists())
	{
		juce::File(mPresetDirectory).createDirectory();

	}
	storeLocalPresets();
};

KAPPresetManager::~KAPPresetManager()
{
	mcurrentPresetXml = nullptr;
	delete(mcurrentPresetXml);
};
void KAPPresetManager::getXmlForPreset(juce::XmlElement* element)
{
	juce::XmlElement* presetName =
		new juce::XmlElement("preset_name");

	presetName->setAttribute("name", mCurrentPresetName);

	element->addChildElement(presetName);

	auto& parameters = mProcessor->getParameters();

	for (int i = 0; i < parameters.size(); i++) {

		juce::AudioProcessorParameterWithID* parameter =
			(juce::AudioProcessorParameterWithID*)parameters.getUnchecked(i);

		element->setAttribute(parameter->paramID,
			parameter->getValue());
	}
};

void KAPPresetManager::loadPresetforXml(juce::XmlElement* element)
{
	mcurrentPresetXml = element;

	juce::XmlElement* presetName = element->getChildByName("preset_name");

	// early return if presetName element is nullptr
	if (presetName == nullptr) { return; }

	mCurrentPresetName = presetName->getStringAttribute("name", "error");

	/** iterate our XML for attribute name and value */
	auto& parameters = mProcessor->getParameters();

	for (int i = 0; i < mcurrentPresetXml->getNumAttributes(); i++) {

		const juce::String paramId = mcurrentPresetXml->getAttributeName(i);
		const float value = mcurrentPresetXml->getDoubleAttribute(paramId);

		for (int j = 0; j < parameters.size(); j++) {

			juce::AudioProcessorParameterWithID* parameter =
				(juce::AudioProcessorParameterWithID*)parameters.getUnchecked(i);

			if (paramId == parameter->paramID) {
				parameter->setValueNotifyingHost(value);
			}
		}
	}
}

int KAPPresetManager::getNumberOfPresets()
{
	return mLocalPresets.size();
};

juce::String KAPPresetManager::getPresetName(int presetIndex)
{

	return mLocalPresets[presetIndex].getFileNameWithoutExtension();
};

void KAPPresetManager::createNewPreset()
{
	auto& parameters = mProcessor->getParameters();

	for (int i = 0; i < parameters.size(); i++) {

		juce::AudioProcessorParameterWithID* parameter =
			(juce::AudioProcessorParameterWithID*)parameters.getUnchecked(i);

		const float defaultValue =
			parameter->getDefaultValue();

		parameter->setValueNotifyingHost(defaultValue);
	}

	/** update our bool */
	misCurrentPresetSaved = false;
	mCurrentPresetName = "Untitled";

};

void KAPPresetManager::savePreset()
{
	juce::MemoryBlock destinationData;
	mProcessor->getStateInformation(destinationData);

	mCurrentLoadedPreset.deleteFile();

	mCurrentLoadedPreset.appendData(destinationData.getData(), destinationData.getSize());

	misCurrentPresetSaved = true;
};

void KAPPresetManager::saveAsPreset(juce::String presetName)
{
	juce::File presetFile = juce::File(mPresetDirectory + seperator + presetName + Preset_File_Extention);

	if (!presetFile.exists()) {
		presetFile.create();
	}
	else {
		presetFile.deleteFile();
	}

	juce::MemoryBlock destinationData;
	mProcessor->getStateInformation(destinationData);

	presetFile.appendData(destinationData.getData(), destinationData.getSize());

	misCurrentPresetSaved = true;
	mCurrentPresetName = presetName;

	storeLocalPresets();
};

void KAPPresetManager::loadPreset(int presetIndex)
{
	mCurrentLoadedPreset = mLocalPresets[presetIndex];

	juce::MemoryBlock presetBinary;

	if (mCurrentLoadedPreset.loadFileAsData(presetBinary)) {
		misCurrentPresetSaved = true;
		mCurrentPresetName = getPresetName(presetIndex);
		mProcessor->setStateInformation(presetBinary.getData(), (int)presetBinary.getSize());
	}

};

bool KAPPresetManager::getIsCurrentPresetSaved()
{
	return misCurrentPresetSaved;
};

juce::String KAPPresetManager::getCurrentPresetName()
{
	return mCurrentPresetName;
};

void KAPPresetManager::storeLocalPresets()
{
	mLocalPresets.clear();

	for (juce::DirectoryEntry entry : juce::RangedDirectoryIterator(juce::File(mPresetDirectory),
		false, "*"+Preset_File_Extention,
		juce::File::findFiles)){

		const juce::File presetFile = entry.getFile();
		mLocalPresets.add(presetFile);
	}


};
