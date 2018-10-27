# 256A-Final-Project-RainbOverdrive
## Walker Davis
### Basic Audio Effect Plug-in using Faust DSP
#### with help from Romain Michon, Tim O'brien, Mark Hertensteiner, and Mark Rau

[Product Demo with surprise ending!!!](https://www.youtube.com/watch?v=TSeU4loi3wE)

### *Disclaimer:* Although I this was the final project of Fall 2016's 256A course, my programming skills were still pretty terrible.  I had a great time putting together the remix/beat at the end of the product demo, I think it was a fresh compositional idea, please check it out.  -Walker 10/27/18

This is my basic audio effect plug-in.  The incoming audio is processed by audio effects that were all generated in Faust.  I borrowed the sample code from Romain Michon's Faust Stereo Reverb example from 256A in Fall 2016 and CCRMA Stanford.  There audio is processed by effects in this order:

* input gain/level
* reverb
* lowpass filter with adjustable resonance
* distortion
* lowpass filter with adjustable resonance
* flanger with adjustable depth and speed speed
* output gain/leve

When designing the GUI, I had some trouble getting circles to behave. After making a half-circle happen, I decided to make a rainbow and play off that theme.

I am pretty certain that classes for me color/shape schemes for the circles should be defined else where, and much more efficiently, but I am not sure where.

Here are some features that this version of RainbOverdrive currently lacks:
* parameter/slider host recognition
* parameter/slider automation
* parameter/slider saving
* VST and VST3 capabilities(currently it only runs as an AU)
