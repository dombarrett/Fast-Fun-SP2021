# Fast-Fun
Working Github repo for the Spring 2021 ITP Class "Fast Fun: Physical Controllers for Unity"

This is where code examples will be hosted, with new files added as the class continues.

## Analog Read and MIDI CC

I'm adding a new Arduino program to the repo: "SmoothedAnalog_CC-MIDI". In this sketch there is a link to a corresponding p5js/Webmidi.js sketch that can be used with it. It can also be used with any program that can receive MIDI CC messages from CC1 and CC2.

To wire one analog sensor, like a potentiometer to your Nano 33 IoT, you would wire it like this:

<img src="AN33IoT_pot-wire.jpg" alt="potentiometer wiring" width="400"/>

With some of the common joystick components, you get two potentiometers. The wiring is similar, with each output going to a different analog input on the Nano. NOTE: your joystick may say "5v". DON'T attach your Nano's 5v to this- instead use the Nano's 3.3v pin, like so:

<img src="AN33IoT_joystick-wire.jpg" alt="joystick wiring" width="400"/>

This is because the Nano operates on 3.3v for it's inputs. The labeling on the joystick was chosen because 5v has traditionally been more common- but that pin is simply for the positive voltage. The 3.3v will work fine and has been tested to work.

Hopefully this helps, along with the email I sent out about smoothing analog reading data. That blog post can be found here:
https://maker.pro/arduino/tutorial/how-to-clean-up-noisy-sensor-data-with-a-moving-average-filter

I'll be updating this repo with another example for a more 'tame' keyboard soon.
