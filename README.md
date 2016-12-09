# 256A-Final-Project-RainbOverdrive
## Walker Davis<br>
### Basic Audio Effect Plug-in using Faust DSP<br>
#### with help from Romain Michon, Tim O'brien, Mark Hertensteiner, and Mark Rau<br>
<br>
[Link!](https://www.youtube.com/watch?v=TSeU4loi3wE)<br>
<br>
 This is my basic audio effect plug-in.  The incoming audio is processed by audio effects that 
 were all generated in Faust.  I borrowed the sample code from Romain Michon's Faust Stereo Reverb example
 from 256A in Fall 2016 and CCRMA Stanford.  There audio is processed by effects in this order:<br>
 <br>
 -input gain/level<br>
 -reverb<br>
 -lowpass filter with adjustable resonance<br>
 -distortion<br>
 -lowpass filter with adjustable resonance<br>
 -flanger with adjustable depth and speed speed<br>
 -output gain/level<br>
 <br>
 When designing the GUI, I had some trouble getting circles to behave. After making a half-circle happen, 
 I decided to make a rainbow and play off that theme.<br>
 <br>
 I am pretty certain that classes for me color/shape schemes for the circles should be defined else where, and
 much more efficiently, but I am not sure where.<br>
 <br>
 Here are some features that this version of RainbOverdrive currently lacks:<br>
 <br>
 -parameter/slider host recognition<br>
 -parameter/slider automation<br>
 -parameter/slider saving<br>
 <br>
 -VST and VST3 capabilities(currently it only runs as an AU)<br>
 
