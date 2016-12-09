/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"


//==============================================================================
AeffectAudioProcessorEditor::AeffectAudioProcessorEditor (AeffectAudioProcessor& p)
: AudioProcessorEditor (&p), processor (p), wetSlider(), levelSlider(), igainSlider(), lpaSlider(), resoSlider(),
driveSlider(), lpbSlider(), resobSlider(), flspeedSlider(), fldepthSlider(), fldlySlider(), fldlyoffsetSlider(),
flfdbkSlider(), ogainSlider()

/*
 I decided not to include several sliders/adjustable parameters becuase they didn't effect
 the sound how I liked and were sometimes simply too much.  I commented everything out without
 deleting it so future developers can bring them back in if they want to.
 
 
*/




{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.

    
    //        addAndMakeVisible (levelSlider);
    //        levelSlider.setRange (-70.0, 40.0);
    //        levelSlider.setValue(-20.0);
    //        levelSlider.addListener (this);
    //
    //        addAndMakeVisible(levelLabel);
    //        levelLabel.setText ("Level", dontSendNotification);
    //        levelLabel.attachToComponent (&levelSlider, true);
    
    
    
    //////////////
    
    addAndMakeVisible (igainSlider);
    igainSlider.setSliderStyle (Slider::RotaryVerticalDrag);
    igainSlider.setTextBoxStyle (Slider::NoTextBox, false, 0, 0);
    igainSlider.setLookAndFeel (&otherLookAndFeelg);
    igainSlider.setRange (0.0, 1.0);
    igainSlider.setValue(1.0);
    igainSlider.addListener (this);
    
//    addAndMakeVisible(igainLabel);
//    igainLabel.setText ("Input Gain", dontSendNotification);
//    igainLabel.attachToComponent (&igainSlider, true);
    
    addAndMakeVisible (ogainSlider);
    ogainSlider.setSliderStyle (Slider::RotaryVerticalDrag);
    ogainSlider.setTextBoxStyle (Slider::NoTextBox, false, 0, 0);
    ogainSlider.setLookAndFeel (&otherLookAndFeelg);
    ogainSlider.setRange (0.0, 1.0);
    ogainSlider.setValue(0.75);
    ogainSlider.addListener (this);
    
    //    addAndMakeVisible(ogainLabel);
    //    ogainLabel.setText ("Output Gain", dontSendNotification);
    //    ogainLabel.attachToComponent (&ogainSlider, true);
    
    
    addAndMakeVisible (lpaSlider);
    lpaSlider.setSliderStyle (Slider::RotaryVerticalDrag);
    lpaSlider.setTextBoxStyle (Slider::NoTextBox, false, 0, 0);
    lpaSlider.setLookAndFeel (&otherLookAndFeelc);
    lpaSlider.setRange (40.0, 13000.0);
    lpaSlider.setValue(13000.0);
    lpaSlider.addListener (this);
    
//    addAndMakeVisible(lpaLabel);
//    lpaLabel.setText ("Low Pass One", dontSendNotification);
//    lpaLabel.attachToComponent (&lpaSlider, true);
    
    addAndMakeVisible(resoSlider);
    resoSlider.setSliderStyle (Slider::RotaryVerticalDrag);
    resoSlider.setTextBoxStyle (Slider::NoTextBox, false, 0, 0);
    resoSlider.setLookAndFeel (&otherLookAndFeelb);
    resoSlider.setRange(1.0,30.0);
    resoSlider.setValue(1.0);
    resoSlider.addListener(this);
    
//    addAndMakeVisible(resoLabel);
//    resoLabel.setText("Resonance One", dontSendNotification);
//    resoLabel.attachToComponent(&resoSlider, true);
    
    
    //////////////
    
    addAndMakeVisible (lpbSlider);
    lpbSlider.setSliderStyle (Slider::RotaryVerticalDrag);
    lpbSlider.setTextBoxStyle (Slider::NoTextBox, false, 0, 0);
    lpbSlider.setLookAndFeel (&otherLookAndFeelc);
    lpbSlider.setRange (40.0, 13000.0);
    lpbSlider.setValue(13000.0);
    lpbSlider.addListener (this);
    
//    addAndMakeVisible(lpbLabel);
//    lpbLabel.setText ("Low Pass Two", dontSendNotification);
//    lpbLabel.attachToComponent (&lpbSlider, true);
    
    addAndMakeVisible(resobSlider);
    resobSlider.setSliderStyle (Slider::RotaryVerticalDrag);
    resobSlider.setTextBoxStyle (Slider::NoTextBox, false, 0, 0);
    resobSlider.setLookAndFeel (&otherLookAndFeelb);
    resobSlider.setRange(1.0,30.0);
    resobSlider.setValue(1.0);
    resobSlider.addListener(this);
    
//    addAndMakeVisible(resobLabel);
//    resobLabel.setText("Resonance Two", dontSendNotification);
//    resobLabel.attachToComponent(&resobSlider, true);
    
    ///////////////
    
    addAndMakeVisible(flspeedSlider);
    flspeedSlider.setSliderStyle (Slider::RotaryVerticalDrag);
    flspeedSlider.setTextBoxStyle (Slider::NoTextBox, false, 0, 0);
    flspeedSlider.setLookAndFeel (&otherLookAndFeele);
    flspeedSlider.setRange(0.0, 10.0);
    flspeedSlider.setValue(0.0);
    flspeedSlider.addListener(this);
    
//    addAndMakeVisible(flspeedLabel);
//    flspeedLabel.setText("Flange Speed", dontSendNotification);
//    flspeedLabel.attachToComponent(&flspeedSlider, true);
    
    addAndMakeVisible(fldepthSlider);
    fldepthSlider.setSliderStyle (Slider::RotaryVerticalDrag);
    fldepthSlider.setTextBoxStyle (Slider::NoTextBox, false, 0, 0);
    fldepthSlider.setLookAndFeel (&otherLookAndFeeld);
    fldepthSlider.setRange(0.0, 1.0);
    fldepthSlider.setValue(0.0);
    fldepthSlider.addListener(this);
    
    
    addAndMakeVisible(driveSlider);
    driveSlider.setSliderStyle (Slider::RotaryVerticalDrag);
    driveSlider.setTextBoxStyle (Slider::NoTextBox, false, 0, 0);
    driveSlider.setLookAndFeel (&otherLookAndFeel);
    driveSlider.setRange(0.0, 1.0);
    driveSlider.setValue(0.0);
    driveSlider.addListener(this);
    
    
    addAndMakeVisible (wetSlider);
    wetSlider.setSliderStyle (Slider::RotaryVerticalDrag);
    wetSlider.setTextBoxStyle (Slider::NoTextBox, false, 0, 0);
    wetSlider.setLookAndFeel (&otherLookAndFeelf);
    wetSlider.setRange (-1.0, 1.0);
    wetSlider.setValue(-1.0);
    wetSlider.addListener (this);
    
//    addAndMakeVisible(wetLabel);
//    wetLabel.setText ("Reverb Wet/Dry", dontSendNotification);
//    wetLabel.attachToComponent (&wetSlider, true);
    
    
    
//    addAndMakeVisible(driveLabel);
//    driveLabel.setText("Drive", dontSendNotification);
//    driveLabel.attachToComponent(&driveSlider, true);
    
    
    
//    addAndMakeVisible(fldepthLabel);
//    fldepthLabel.setText("Flange Depth", dontSendNotification);
//    fldepthLabel.attachToComponent(&fldepthSlider, true);
    
//    addAndMakeVisible(fldlySlider);
//    fldlySlider.setRange(0.0, 20.0);
//    fldlySlider.setValue(0.0);
//    fldlySlider.addListener(this);
//    
//    addAndMakeVisible(fldlyLabel);
//    fldlyLabel.setText("Flange Delay", dontSendNotification);
//    fldlyLabel.attachToComponent(&fldlySlider, true);
//    
//    addAndMakeVisible(fldlyoffsetSlider);
//    fldlyoffsetSlider.setRange(0.0, 20.0);
//    fldlyoffsetSlider.setValue(0.0);
//    fldlyoffsetSlider.addListener(this);
//    
//    addAndMakeVisible(fldlyoffsetLabel);
//    fldlyoffsetLabel.setText("Flange Delay Offest", dontSendNotification);
//    fldlyoffsetLabel.attachToComponent(&fldlyoffsetSlider, true);
    
    addAndMakeVisible(flfdbkSlider);
    flfdbkSlider.setRange(-0.999, 0.999);
    flfdbkSlider.setValue(0.000);
    flfdbkSlider.addListener(this);
    
//    addAndMakeVisible(flfdbkLabel);
//    flfdbkLabel.setText("Flange Feedback", dontSendNotification);
//    flfdbkLabel.attachToComponent(&flfdbkSlider, true);
    
    
    
    ///////////////
    

    
    
    
    setSize (600, 300);
    
}

AeffectAudioProcessorEditor::~AeffectAudioProcessorEditor()
{
}

//==============================================================================
void AeffectAudioProcessorEditor::paint (Graphics& g)
{
    g.fillAll (Colours::black);

    g.setColour (Colours::cyan);
    g.setFont (32.0f);
    g.drawFittedText ("RainbOverdrive", 0, 0, getWidth(), 60, Justification::centred, 1);
}


//Here is my rainbow design!


void AeffectAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
    
      ////effects parameters that resemble reading rainbow
      flspeedSlider.setBounds (-50,135,700,350);
      fldepthSlider.setBounds (0, 175, 600, 300);
      driveSlider.setBounds (50,215,500,250);
      wetSlider.setBounds (100,255,400,200);
    
      //filter parameters that resemple globes/orbs
      lpaSlider.setBounds (-35,100,150,130);
      resoSlider.setBounds (70,59,150,110);
      lpbSlider.setBounds (380,59,150,110);
      resobSlider.setBounds (485,100,150,130);
    
      igainSlider.setBounds (-7,24,150,90);
      ogainSlider.setBounds (458,24,150,90);
    
    
    


////parameters that sound like shit when you move them
//    const int sliderLeft = 130;
//    fldlySlider.setBounds (sliderLeft, 310, getWidth() - sliderLeft - 20, 20);
//    fldlyoffsetSlider.setBounds (sliderLeft, 340, getWidth() - sliderLeft - 20, 20);
//    flfdbkSlider.setBounds (sliderLeft, 280, getWidth() - sliderLeft - 20,20);
    
//    const int border = 4;
    
    
//    Rectangle<int> area = getLocalBounds();
//    
//    {
//        Rectangle<int> dialArea = area.removeFromTop (area.getHeight() );
//        igainSlider.setBounds (dialArea.removeFromLeft (dialArea.getWidth() / 12).reduced (border));
//        ogainSlider.setBounds (dialArea.removeFromRight (dialArea.getWidth() / 12).reduced (border));
//    }
}



void AeffectAudioProcessorEditor :: sliderValueChanged (Slider* slider)
{
    if (processor.getSampleRate() > 0.0){
        if (slider == &wetSlider)
        {
            processor.reverbControl.setParamValue("/Zita_Rev1/Output/Dry/Wet_Mix", wetSlider.getValue());
        }
        else if (slider == &levelSlider)
        {
            processor.reverbControl.setParamValue("/Zita_Rev1/Output/Level", levelSlider.getValue());
        }
        
        ////////////////////////////////
        else if (slider == &igainSlider)
        {
            processor.mefxControl.setParamValue("/0x00/gain", igainSlider.getValue());
        }
        else if (slider == &lpaSlider)
        {
            processor.mefxControl.setParamValue("/0x00/cutoff", lpaSlider.getValue());
        }
        else if (slider == &resoSlider)
        {
            processor.mefxControl.setParamValue("/0x00/reso", resoSlider.getValue());
        }
        
        
        else if (slider == &driveSlider)
        {
            processor.mefxControl.setParamValue("/0x00/drive", driveSlider.getValue());
        }
        else if (slider == &lpbSlider)
        {
            processor.mefxControl.setParamValue("/0x00/cutoffb", lpbSlider.getValue());
        }
        else if (slider == &resobSlider)
        {
            processor.mefxControl.setParamValue("/0x00/resob", resobSlider.getValue());
        }
        
        /////////////////////////
        else if (slider == &flspeedSlider)
        {
            processor.mefxControl.setParamValue("/0x00/FLANGER/0x00/Speed", flspeedSlider.getValue());
        }
        else if (slider == &fldepthSlider)
        {
            processor.mefxControl.setParamValue("/0x00/FLANGER/0x00/Depth", fldepthSlider.getValue());
        }
//        else if (slider == &fldlySlider)
//        {
//            processor.mefxControl.setParamValue("/0x00/FLANGER/Delay_Controls/Flange_Delay", fldlySlider.getValue());
//        }
//        else if (slider == &fldlyoffsetSlider)
//        {
//            processor.mefxControl.setParamValue("/0x00/FLANGER/Delay_Controls/Delay_Offset", fldlyoffsetSlider.getValue());
//        }
        else if (slider == &flfdbkSlider)
        {
            processor.mefxControl.setParamValue("/0x00/FLANGER/0x00/Feedback", flfdbkSlider.getValue());
        }
        
        else if (slider == &ogainSlider)
        {
            processor.mefxControl.setParamValue("/0x00/gainb", ogainSlider.getValue());
        }
    }
}

