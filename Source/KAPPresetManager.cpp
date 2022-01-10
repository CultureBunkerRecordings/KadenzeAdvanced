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

KAPPresetManager::KAPPresetManager(juce::AudioProcessor* processor): mProcessor(processor)
{
	const juce::String pluginName = (juce::String)mProcessor->getName();
	mPresetDirectory = juce::File::getSpecialLocation(juce::File::userDesktopDirectory).getFullPathName() + pluginName;

	if (!juce::File(mPresetDirectory).exists())
	{
		juce::File(mPresetDirectory).createDirectory();

	}

};

KAPPresetManager::~KAPPresetManager()
{
	
};
void KAPPresetManager::getXmlForPreset(juce::XmlElement* element)
{
	int numParams = mProcessor->getNumParameters();

	for (int i = 0; i< numParams;i++)
	{
		element->setAttribute(mProcessor->getParameterName(i), mProcessor->getParameter(i));
	}
};

void KAPPresetManager::loadPresetforXml(juce::XmlElement* element)
{
	mcurrentPresetXml = element;
	int numParams = mProcessor->getNumParameters();

	for (int i = 0; i < mcurrentPresetXml->getNumAttributes(); i++)
	{
		juce::String name = mcurrentPresetXml->getAttributeName(i);
		float value = mcurrentPresetXml->getDoubleAttribute(name);

		for (int j = 0; j < mProcessor->getNumParameters(); j++)
		{
			if (mProcessor->getParameterName(j) == name)
			{
				mProcessor->setParameterNotifyingHost(j, value);
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
	int numPresets = mProcessor->getNumParameters();

	for (int i = 0; i < numPresets; i++)
	{
		mProcessor->setParameterNotifyingHost(i, mProcessor->getParameterDefaultValue(i));
	}

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
	juce::File presetFile = juce::File(mPresetDirectory + seperator + presetName);

	if (presetFile.exists()) {
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
		mProcessor->setStateInformation(presetBinary.getData(), presetBinary.getSize());
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

	for (juce::DirectoryIterator di(juce::File(mPresetDirectory), false, '*' + (juce::String)Preset_File_Extention,
		juce::File::TypesOfFileToFind::findFiles); di.next();)
	{
		juce::File preset = di.getFile();
		mLocalPresets.add(preset);

	}


};
