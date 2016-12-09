/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"


//==============================================================================
AeffectAudioProcessor::AeffectAudioProcessor()
#ifndef JucePlugin_PreferredChannelConfigurations
     : AudioProcessor (BusesProperties()
                     #if ! JucePlugin_IsMidiEffect
                      #if ! JucePlugin_IsSynth
                       .withInput  ("Input",  AudioChannelSet::stereo(), true)
                      #endif
                       .withOutput ("Output", AudioChannelSet::stereo(), true)
                     #endif
                       )
#endif
{
}

AeffectAudioProcessor::~AeffectAudioProcessor()
{
    
    delete [] audioBuffer;
}

//==============================================================================
const String AeffectAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool AeffectAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool AeffectAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

double AeffectAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int AeffectAudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int AeffectAudioProcessor::getCurrentProgram()
{
    return 0;
}

void AeffectAudioProcessor::setCurrentProgram (int index)
{
}

const String AeffectAudioProcessor::getProgramName (int index)
{
    return String();
}

void AeffectAudioProcessor::changeProgramName (int index, const String& newName)
{
}

//==============================================================================
void AeffectAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    // Use this method as the place to do any pre-playback
    // initialisation that you need..
    
    audioBuffer = new float*[2];

    
    reverb.init(sampleRate); // initializing the Faust module
    reverb.buildUserInterface(&reverbControl); // linking the Faust module to the controler
    
    mefx.init(sampleRate);
    mefx.buildUserInterface(&mefxControl);
    
    // Print the list of parameters address of "reverb"
    // To get the current (default) value of these parameters, reverbControl.getParamValue("paramPath") can be used
    for(int i=0; i<reverbControl.getParamsCount(); i++){
        std::cout << reverbControl.getParamAdress(i) << "\n";
    }
    
    for(int i=0; i<mefxControl.getParamsCount(); i++){
        std::cout << mefxControl.getParamAdress(i) << "\n";
    }
    
    
    
    
    // setting default values for the Faust module parameters
    reverbControl.setParamValue("/Zita_Rev1/Output/Level",1.0);
    reverbControl.setParamValue("/Zita_Rev1/Output/Dry/Wet_Mix",-1.0);
    
    mefxControl.setParamValue("/0x00/gain",0.0);
    mefxControl.setParamValue("/0x00/cutoff", 13000.0);
    mefxControl.setParamValue("/0x00/reso", 1.0);
    mefxControl.setParamValue("/0x00/drive", 0.0);
    mefxControl.setParamValue("/0x00/cutoffb", 13000.0);
    mefxControl.setParamValue("/0x00/resob", 1.0);
    
    mefxControl.setParamValue("/0x00/FLANGER/0x00/Speed", 0.0);
    mefxControl.setParamValue("/0x00/FLANGER/0x00/Depth", 0.0);
    mefxControl.setParamValue("/0x00/FLANGER/Delay_Controls/Flange_Delay", 10.0);
    mefxControl.setParamValue("/0x00/FLANGER/Delay_Controls/Delay_Offset", 10.0);
    mefxControl.setParamValue("/0x00/FLANGER/0x00/Feedback", 0.000);
    
    
    mefxControl.setParamValue("/0x00/gainb",0.75);
    
    
}

void AeffectAudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool AeffectAudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
{
  #if JucePlugin_IsMidiEffect
    ignoreUnused (layouts);
    return true;
  #else
    // This is the place where you check if the layout is supported.
    // In this template code we only support mono or stereo.
    if (layouts.getMainOutputChannelSet() != AudioChannelSet::mono()
     && layouts.getMainOutputChannelSet() != AudioChannelSet::stereo())
        return false;

    // This checks if the input layout matches the output layout
   #if ! JucePlugin_IsSynth
    if (layouts.getMainOutputChannelSet() != layouts.getMainInputChannelSet())
        return false;
   #endif

    return true;
  #endif
}
#endif

void AeffectAudioProcessor::processBlock (AudioSampleBuffer& buffer, MidiBuffer& midiMessages)
{
    const int totalNumInputChannels  = getTotalNumInputChannels();
    const int totalNumOutputChannels = getTotalNumOutputChannels();

    // In case we have more outputs than inputs, this code clears any output
    // channels that didn't contain input data, (because these aren't
    // guaranteed to be empty - they may contain garbage).
    // This is here to avoid people getting screaming feedback
    // when they first compile a plugin, but obviously you don't need to keep
    // this code if your algorithm always overwrites all the output channels.
    for (int i = totalNumInputChannels; i < totalNumOutputChannels; ++i)
        buffer.clear (i, 0, buffer.getNumSamples());

    // This is the place where you'd normally do the guts of your plugin's
    // audio processing...
    for (int channel = 0; channel < totalNumInputChannels; ++channel)
    {
        audioBuffer[channel] = buffer.getWritePointer (channel);
        
        
        // ..do something to the data...
    }
    
    // any processing before going to "reverb" could be done here in a dedicated buffer loop
    
    reverb.compute(buffer.getNumSamples(), audioBuffer, audioBuffer); // computing one block with Faust
    
    mefx.compute(buffer.getNumSamples(), audioBuffer, audioBuffer);
    
    
}

//==============================================================================
bool AeffectAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

AudioProcessorEditor* AeffectAudioProcessor::createEditor()
{
    return new AeffectAudioProcessorEditor (*this);
}

//==============================================================================
void AeffectAudioProcessor::getStateInformation (MemoryBlock& destData)
{
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.
}

void AeffectAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.
}

//==============================================================================
// This creates new instances of the plugin..
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new AeffectAudioProcessor();
}
