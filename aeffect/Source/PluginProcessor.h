/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#ifndef PLUGINPROCESSOR_H_INCLUDED
#define PLUGINPROCESSOR_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"
#include "FaustReverb.h" // the Faust module
#include "Zzzefx.h"

//==============================================================================
/**
 This is my basic audio effect plug-in.  The incoming audio is processed by audio effects that 
 were all generated in Faust.  I borrowed the sample code from Romain Michon's Faust Stereo Reverb example
 from 256A in Fall 2016 and CCRMA Stanford.  There audio is processed by effects in this order:
 
 -input gain/level
 -reverb
 -lowpass filter with adjustable resonance
 -distortion
 -lowpass filter with adjustable resonance
 -flanger with adjustable depth and speed speed
 -output gain/level
 
 When designing the GUI, I had some trouble getting circles to behave. After making a half-circle happen, 
 I decided to make a rainbow and play off that theme.
 
 I am pretty certain that classes for me color/shape schemes for the circles should be defined else where, and
 much more efficiently,but there are right below.
 
*/

class OtherLookAndFeel : //bottom ring-distortion
public LookAndFeel_V3
{
public:
    OtherLookAndFeel()
    {
        setColour (Slider::rotarySliderFillColourId, Colours::red);
    }
    
    //this class makes the rotary sliders more interesting
    //i like these colors becuase they are pretty childish, sort of like a phat mono synth
    
    void drawRotarySlider (Graphics& g, int x, int y, int width, int height, float sliderPos,
                           const float rotaryStartAngle, const float rotaryEndAngle, Slider& slider) override
    {
        
        
        const float radius = jmin (width , height ) - 10.0f;
        const float centreX = x + width * 0.5f;
        const float centreY = y + width * 0.5f;
        const float rx = centreX - radius;
        const float ry = centreY - radius;
        const float rw = radius * 2.0f;
        const float angle = rotaryStartAngle + sliderPos * (rotaryEndAngle - rotaryStartAngle);
        
        // fill
        g.setColour (Colours::black);
        g.fillEllipse (rx, ry, rw, rw);
        // outline
        g.setColour (Colours::red);
        g.drawEllipse (rx, ry, rw, rw, 20.0f);
        
        Path p;
        const float pointerLength = 10.0f;
        const float pointerThickness = 5.0f;
        p.addRectangle (-pointerThickness * 0.5f, -radius, pointerThickness, pointerLength);
        p.applyTransform (AffineTransform::rotation (angle).translated (centreX, centreY));
        
        // pointer
        g.setColour (Colours::black);
        g.fillPath (p);
        
    }
};

class OtherLookAndFeelb : //resonance sliders
public LookAndFeel_V3
{
public:
    OtherLookAndFeelb()
    {
        setColour (Slider::rotarySliderFillColourId, Colours::red);
    }
    
    //this class makes the rotary sliders more interesting
    //i like these colors becuase they are pretty childish, sort of like a phat mono synth
    
    void drawRotarySlider (Graphics& g, int x, int y, int width, int height, float sliderPos,
                           const float rotaryStartAngle, const float rotaryEndAngle, Slider& slider) override
    {
        
        
        const float radius = jmin (width / 2 , height /2) - 10.0f;
        const float centreX = x + width * 0.5f;
        const float centreY = y + height * 0.5f;
        const float rx = centreX - radius;
        const float ry = centreY - radius;
        const float rw = radius * 2.0f;
        const float angle = rotaryStartAngle + sliderPos * (rotaryEndAngle - rotaryStartAngle);
        
        // fill
        g.setColour (Colours::crimson);
        g.fillEllipse (rx, ry, rw, rw);
        // outline
        g.setColour (Colours::maroon);
        g.drawEllipse (rx, ry, rw, rw, 10.0f);
        
        Path p;
        const float pointerLength = radius * 0.2f;
        const float pointerThickness = 5.0f;
        p.addRectangle (-pointerThickness * 0.5f, -radius, pointerThickness, pointerLength);
        p.applyTransform (AffineTransform::rotation (angle).translated (centreX, centreY));
        
        // pointer
        g.setColour (Colours::black);
        g.fillPath (p);
        
    }
};


class OtherLookAndFeelc :  //lowpass sliders
public LookAndFeel_V3
{
public:
    OtherLookAndFeelc()
    {
        setColour (Slider::rotarySliderFillColourId, Colours::red);
    }
    
    //this class makes the rotary sliders more interesting
    //i like these colors becuase they are pretty childish, sort of like a phat mono synth
    
    void drawRotarySlider (Graphics& g, int x, int y, int width, int height, float sliderPos,
                           const float rotaryStartAngle, const float rotaryEndAngle, Slider& slider) override
    {
        
        
        const float radius = jmin (width /2 , height /2) - 10.0f;
        const float centreX = x + width * 0.5f;
        const float centreY = y + height * 0.5f;
        const float rx = centreX - radius;
        const float ry = centreY - radius;
        const float rw = radius * 2.0f;
        const float angle = rotaryStartAngle + sliderPos * (rotaryEndAngle - rotaryStartAngle);
        
        // fill
        g.setColour (Colours::purple);
        g.fillEllipse (rx, ry, rw, rw);
        // outline
        g.setColour (Colours::mediumvioletred);
        g.drawEllipse (rx, ry, rw, rw, 10.0f);
        
        Path p;
        const float pointerLength = radius * 0.2f;
        const float pointerThickness = 5.0f;
        p.addRectangle (-pointerThickness * 0.5f, -radius, pointerThickness, pointerLength);
        p.applyTransform (AffineTransform::rotation (angle).translated (centreX, centreY));
        
        // pointer
        g.setColour (Colours::black);
        g.fillPath (p);
        
    }
};

class OtherLookAndFeeld : //second ring - flange depth
public LookAndFeel_V3
{
public:
    OtherLookAndFeeld()
    {
        setColour (Slider::rotarySliderFillColourId, Colours::red);
    }
    
    //this class makes the rotary sliders more interesting
    //i like these colors becuase they are pretty childish, sort of like a phat mono synth
    
    void drawRotarySlider (Graphics& g, int x, int y, int width, int height, float sliderPos,
                           const float rotaryStartAngle, const float rotaryEndAngle, Slider& slider) override
    {
        
        
        const float radius = jmin (width , height ) - 10.0f;
        const float centreX = x + width * 0.5f;
        const float centreY = y + width * 0.5f;
        const float rx = centreX - radius;
        const float ry = centreY - radius;
        const float rw = radius * 2.0f;
        const float angle = rotaryStartAngle + sliderPos * (rotaryEndAngle - rotaryStartAngle);
        
        // fill
        g.setColour (Colours::orange);
        g.fillEllipse (rx, ry, rw, rw);
        // outline
        g.setColour (Colours::yellow);
        g.drawEllipse (rx, ry, rw, rw, 20.0f);
        
        Path p;
        const float pointerLength = 10.0f;
        const float pointerThickness = 5.0f;
        p.addRectangle (-pointerThickness * 0.5f, -radius, pointerThickness, pointerLength);
        p.applyTransform (AffineTransform::rotation (angle).translated (centreX, centreY));
        
        // pointer
        g.setColour (Colours::black);
        g.fillPath (p);
        
    }
};


class OtherLookAndFeele: //third ring - flange depth
public LookAndFeel_V3
{
public:
    OtherLookAndFeele()
    {
        setColour (Slider::rotarySliderFillColourId, Colours::red);
    }
    
    //this class makes the rotary sliders more interesting
    //i like these colors becuase they are pretty childish, sort of like a phat mono synth
    
    void drawRotarySlider (Graphics& g, int x, int y, int width, int height, float sliderPos,
                           const float rotaryStartAngle, const float rotaryEndAngle, Slider& slider) override
    {
        
        
        const float radius = jmin (width , height ) - 10.0f;
        const float centreX = x + width * 0.5f;
        const float centreY = y + width * 0.5f;
        const float rx = centreX - radius;
        const float ry = centreY - radius;
        const float rw = radius * 2.0f;
        const float angle = rotaryStartAngle + sliderPos * (rotaryEndAngle - rotaryStartAngle);
        
        // fill
        g.setColour (Colours::seagreen);
        g.fillEllipse (rx, ry, rw, rw);
        // outline
        g.setColour (Colours::blue);
        g.drawEllipse (rx, ry, rw, rw, 20.0f);
        
        Path p;
        const float pointerLength = 10.0f;
        const float pointerThickness = 5.0f;
        p.addRectangle (-pointerThickness * 0.5f, -radius, pointerThickness, pointerLength);
        p.applyTransform (AffineTransform::rotation (angle).translated (centreX, centreY));
        
        // pointer
        g.setColour (Colours::black);
        g.fillPath (p);
        
    }
};


class OtherLookAndFeelf: // area below rings - secret reverb
public LookAndFeel_V3
{
public:
    OtherLookAndFeelf()
    {
        setColour (Slider::rotarySliderFillColourId, Colours::red);
    }
    
    //this class makes the rotary sliders more interesting
    //i like these colors becuase they are pretty childish, sort of like a phat mono synth
    
    void drawRotarySlider (Graphics& g, int x, int y, int width, int height, float sliderPos,
                           const float rotaryStartAngle, const float rotaryEndAngle, Slider& slider) override
    {
        
        
        const float radius = jmin (width , height ) - 10.0f;
        const float centreX = x + width * 0.5f;
        const float centreY = y + width * 0.5f;
        const float rx = centreX - radius;
        const float ry = centreY - radius;
        const float rw = radius * 2.0f;
        const float angle = rotaryStartAngle + sliderPos * (rotaryEndAngle - rotaryStartAngle);
        
        // fill
        g.setColour (Colours::black);
        g.fillEllipse (rx, ry, rw, rw);
        // outline
        g.setColour (Colours::black);
        g.drawEllipse (rx, ry, rw, rw, 20.0f);
        
        Path p;
        const float pointerLength = 10.0f;
        const float pointerThickness = 5.0f;
        p.addRectangle (-pointerThickness * 0.5f, -radius, pointerThickness, pointerLength);
        p.applyTransform (AffineTransform::rotation (angle).translated (centreX, centreY));
        
        // pointer
        g.setColour (Colours::goldenrod);
        g.fillPath (p);
        
    }
};


class OtherLookAndFeelg :  //input and output rotaries
public LookAndFeel_V3 
{
public:
    OtherLookAndFeelg()
    {
        setColour (Slider::rotarySliderFillColourId, Colours::red);
    }
    
    //this class makes the rotary sliders more interesting
    //i like these colors becuase they are pretty childish, sort of like a phat mono synth
    
    void drawRotarySlider (Graphics& g, int x, int y, int width, int height, float sliderPos,
                           const float rotaryStartAngle, const float rotaryEndAngle, Slider& slider) override
    {
        
        
        const float radius = jmin (width /2 , height /2) - 10.0f;
        const float centreX = x + width * 0.5f;
        const float centreY = y + height * 0.5f;
        const float rx = centreX - radius;
        const float ry = centreY - radius;
        const float rw = radius * 2.0f;
        const float angle = rotaryStartAngle + sliderPos * (rotaryEndAngle - rotaryStartAngle);
        
        // fill
        g.setColour (Colours::mediumblue);
        g.fillEllipse (rx, ry, rw, rw);
        // outline
        g.setColour (Colours::indigo);
        g.drawEllipse (rx, ry, rw, rw, 5.0f);
        
        Path p;
        const float pointerLength = radius * 0.2f;
        const float pointerThickness = 5.0f;
        p.addRectangle (-pointerThickness * 0.5f, -radius, pointerThickness, pointerLength);
        p.applyTransform (AffineTransform::rotation (angle).translated (centreX, centreY));
        
        // pointer
        g.setColour (Colours::black);
        g.fillPath (p);
        
    }
};



class AeffectAudioProcessor  : public AudioProcessor
{
public:
    //==============================================================================
    AeffectAudioProcessor();
    ~AeffectAudioProcessor();

    //==============================================================================
    void prepareToPlay (double sampleRate, int samplesPerBlock) override;
    void releaseResources() override;

   #ifndef JucePlugin_PreferredChannelConfigurations
    bool isBusesLayoutSupported (const BusesLayout& layouts) const override;
   #endif

    void processBlock (AudioSampleBuffer&, MidiBuffer&) override;

    //==============================================================================
    AudioProcessorEditor* createEditor() override;
    bool hasEditor() const override;

    //==============================================================================
    const String getName() const override;

    bool acceptsMidi() const override;
    bool producesMidi() const override;
    double getTailLengthSeconds() const override;

    //==============================================================================
    int getNumPrograms() override;
    int getCurrentProgram() override;
    void setCurrentProgram (int index) override;
    const String getProgramName (int index) override;
    void changeProgramName (int index, const String& newName) override;

    //==============================================================================
    void getStateInformation (MemoryBlock& destData) override;
    void setStateInformation (const void* data, int sizeInBytes) override;

    
    FaustReverb reverb; // the Faust module (Reverb.h)
    MapUI reverbControl; // used to easily control the Faust module (Reverb.h)
    
    Zzzefx mefx;
    MapUI mefxControl;
    
    float** audioBuffer;
    
    
private:
    //==============================================================================
    
    
    
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (AeffectAudioProcessor)
};


#endif  // PLUGINPROCESSOR_H_INCLUDED
