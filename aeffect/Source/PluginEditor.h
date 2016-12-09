/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#ifndef PLUGINEDITOR_H_INCLUDED
#define PLUGINEDITOR_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"


//==============================================================================
/**
*/
class AeffectAudioProcessorEditor  : public AudioProcessorEditor,
                                    private Slider::Listener
{
public:
    AeffectAudioProcessorEditor (AeffectAudioProcessor&);
    ~AeffectAudioProcessorEditor();

    //==============================================================================
    void paint (Graphics&) override;
    void resized() override;
    void sliderValueChanged(Slider* slider) override;

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    
    AeffectAudioProcessor& processor;
    
    OtherLookAndFeel otherLookAndFeel;
    OtherLookAndFeelb otherLookAndFeelb;
    OtherLookAndFeelc otherLookAndFeelc;
    OtherLookAndFeeld otherLookAndFeeld;
    OtherLookAndFeele otherLookAndFeele;
    OtherLookAndFeelf otherLookAndFeelf;
    OtherLookAndFeelg otherLookAndFeelg;
    
    Slider wetSlider;
    Slider levelSlider;
    Slider igainSlider;
    Slider lpaSlider;
    Slider resoSlider;
    Slider driveSlider;
    Slider lpbSlider;
    Slider resobSlider;
    
    Slider flspeedSlider;
    Slider fldepthSlider;
    Slider fldlySlider;
    Slider fldlyoffsetSlider;
    Slider flfdbkSlider;
    
    Slider ogainSlider;
    
    
    
    Label wetLabel;
    Label levelLabel;
    Label igainLabel;
    Label lpaLabel;
    Label resoLabel;
    Label driveLabel;
    Label lpbLabel;
    Label resobLabel;
    
    Label flspeedLabel;
    Label fldepthLabel;
    Label fldlyLabel;
    Label fldlyoffsetLabel;
    Label flfdbkLabel;
    
    Label ogainLabel;
    
    
    

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (AeffectAudioProcessorEditor)
};


#endif  // PLUGINEDITOR_H_INCLUDED
