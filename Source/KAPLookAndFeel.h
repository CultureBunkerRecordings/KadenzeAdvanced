/*
  ==============================================================================

    KAPLookAndFeel.h
    Created: 7 Jan 2022 5:15:31pm
    Author:  William

  ==============================================================================
*/

#pragma once

#include <juceheader.h>
#include "KAPInterfaceDefines.h"

class KAPLookAndFeel : public juce::LookAndFeel_V4
{
public:
    KAPLookAndFeel()
    {
        //Slider
        mSliderImage = juce::ImageCache::getFromMemory(BinaryData::kadenze_knob_png, BinaryData::kadenze_knob_pngSize);


        //Comboboxs
        setColour(juce::ComboBox::backgroundColourId, Colour3);
        setColour(juce::ComboBox::outlineColourId, Colour2);
        setColour(juce::ComboBox::arrowColourId, Colour1);
        setColour(juce::ComboBox::textColourId, Colour1);

        //buttons
        setColour(juce::TextButton::buttonColourId, Colour1);
        setColour(juce::TextButton::textColourOnId, Colour1);
        setColour(juce::TextButton::textColourOffId, Colour1);
    };

    virtual ~KAPLookAndFeel() {};
    //-------------------------------------------------------------------------------button------------------------------------------------------------------------
    juce::Font getTextButtonFont(juce::TextButton&, int buttonHeight) override
    {
        return Font1;
    }
    void drawButtonBackground(juce::Graphics& g,
        juce::Button& button,
        const juce::Colour& backgroundColour,
        bool shouldDrawButtonAsHighlighted,
        bool shouldDrawButtonAsDown) override
    {
        juce::Colour fillColour;
        if (shouldDrawButtonAsDown) {
            fillColour = Colour5;
        } else if (shouldDrawButtonAsHighlighted) {
            fillColour = Colour3;
        }
        else {
            fillColour = Colour5;
        }

        const float cornerSize = 6.0f;
        juce::Rectangle<float> bounds = button.getLocalBounds().toFloat().reduced(0.5, 0.5);

        g.setColour(fillColour);
        g.fillRoundedRectangle(bounds.reduced(1), cornerSize);
    }
    //------------------------------------------------------------------------------ComboBox----------------------------------------------------------------------------

    juce::Font getLabelFont(juce::Label&) override
    {
        return Font1;
    }

    void drawPopupMenuItem(juce::Graphics& g, const juce::Rectangle<int>& area,
        bool isSeparator, bool isActive, bool isHighlighted, bool isTicked, bool hasSubMenu,
        const juce::String& text, const juce::String& shortcutKeyText,
        const juce::Drawable* icon, const juce::Colour* textColour) override
    {
        juce::Rectangle<int> r(area);
        juce::Colour fillColour = isHighlighted ? Colour5 : Colour4;
        g.setColour(fillColour);
        g.fillRect(r.getX(), r.getY(), r.getWidth(), r.getHeight() - 1);

        juce::Colour txtColour = isTicked ? Colour7 : Colour1;
        g.setColour(txtColour);
        g.setFont(Font1);

        r.setLeft(10);
        r.setY(1);
        g.drawFittedText(text, r, juce::Justification::left, 1);
    }

    void drawComboBox(juce::Graphics& g, int width, int height, bool isButtonDown,
        int buttonX, int buttonY, int buttonW, int buttonH,
        juce::ComboBox& box) override
    {
        const float cornerSize = 3.0f;
        const juce::Rectangle<int> boxBounds(0, 0, width, height);
        
        g.setColour(Colour3);
        g.fillRoundedRectangle(boxBounds.toFloat(), cornerSize);
        
        juce::Rectangle<int> arrow(width - 30, 0, 20, height);

        juce::Path path;

        path.startNewSubPath(arrow.getX() + 3.0f, arrow.getCentreY() - 2.0f);
        path.lineTo(arrow.toFloat().getCentreX(), arrow.toFloat().getCentreY() + 3.0f);
        path.lineTo(arrow.toFloat().getRight() - 3.0f, arrow.toFloat().getCentreY() - 2.0f);

        juce::Colour arrowColour = box.findColour(juce::ComboBox::arrowColourId).withAlpha(box.isEnabled() ? 0.9f : 0.2f);
        g.setColour(arrowColour);
        g.strokePath(path, juce::PathStrokeType(2.0f));
    }

    //-----------------------------------------------------------------------------------------Sliders----------------------------------------------------------------------

    void drawRotarySlider(juce::Graphics& g, int x, int y, int width, int height,
        float sliderPosProportional, float rotaryStartAngle,
        float rotaryEndAngle, juce::Slider& slider) override
    {
        const int numFrames = mSliderImage.getHeight() / mSliderImage.getWidth();
        const int frameIndex = (int)std::ceil(sliderPosProportional * (numFrames - 1));

        float radius = juce::jmin(width * 0.5f, height * 0.5f);
        float centreX = x + width * 0.5f;
        float centreY = y + height * 0.5f;

        float rX = centreX - radius;
        float rY = centreY - radius;

        g.drawImage(mSliderImage, rX, rY, 2 * radius, 2 * radius, 0, frameIndex * mSliderImage.getWidth(), mSliderImage.getWidth(), mSliderImage.getWidth());
    }

private:
    juce::Image mSliderImage;


    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(KAPLookAndFeel)
};
