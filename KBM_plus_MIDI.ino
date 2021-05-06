/*
  
  Combining the KB+M control sketch
  based off of example sketch (info below)
  with the MIDI CC approach given earlier,
  based off of the MIDIUSB example sketch (info below)

  1)
  KeyboardAndMouseControl
  
  created 15 Mar 2012
  modified 27 Mar 2012
  by Tom Igoe

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/KeyboardAndMouseControl

      ---Comined with info from: ---

  2)
   * MIDIUSB_test.ino
   *
   * Created: 4/6/2015 10:47:08 AM
   * Author: gurbrinder grewal
   * Modified by Arduino LLC (2015)


I've tested this on my Mac, but haven't seen how it works on Windows yet.
This may appear as two devices, and you may need to do the driver reset approach for each part
(KBM and MIDI each)

Instructions for fixing that can be found here:
https://github.com/arduino/ArduinoCore-samd/releases/tag/1.8.2

This describes how to select a generic USB Keyboard driver,
but the approach should be the same for MIDI
  -except you select a generic USB Sound device driver instead.
  
*/


//KB+M
#include "Keyboard.h"
#include "Mouse.h"

//And MIDI!
#include "MIDIUSB.h"

void setup() { // initialize the buttons' inputs:
  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
  pinMode(4, INPUT_PULLUP);
  pinMode(5, INPUT_PULLUP);
  pinMode(6, INPUT_PULLUP);

  Serial.begin(9600);
  // initialize mouse control:
  Mouse.begin();
  Keyboard.begin();
}

void loop() {

  //Using digital input 2,3,4,5,6
  //Controls keyboard, sends midi messages, and moves the mouse
  
  if (digitalRead(2) == LOW) {
    Keyboard.write('w');
  }
  if (digitalRead(3) == LOW) {
    controlChange(1,1,10);
    //A note here. As discussed in class,
    //we can also think of CC messages in a 'digital' way
    //Here two different reads set the value either 10 or 99
  }
  if (digitalRead(4) == LOW) {
    controlChange(1,1,99);
  }
  if (digitalRead(5) == LOW) {
    Mouse.move(-40, 0);
  }
  if (digitalRead(6) == LOW) {
    Mouse.move(40, 0);
  }

}


// First parameter is the event type (0x0B = control change).
// Second parameter is the event type, combined with the channel.
// Third parameter is the control number number (0-119).
// Fourth parameter is the control value (0-127).

void controlChange(byte channel, byte control, byte value) {

  midiEventPacket_t event = {0x0B, 0xB0 | channel, control, value};

  MidiUSB.sendMIDI(event);
}


/*
 * Use this space for testing your keypresses
 * 
 * 
 * 
 * /
 */
