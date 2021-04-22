/*
This Arduino program can be paired with the Webmidi.js/p5js sketch found here:
https://editor.p5js.org/dbarrett/sketches/1Z7wl-Qxj

Or any program that is listening to MIDI CC messages from CC1 and CC2

Analog values at pins A0 and A1
See the Arduino Nano 33 IoT's labeled pins here:
https://content.arduino.cc/assets/Pinout-NANO33IoT_latest.png

Using the "smoothing noisy sensor data" approach found here:
https://maker.pro/arduino/tutorial/how-to-clean-up-noisy-sensor-data-with-a-moving-average-filter

Instead of one smoothed analog read, in this program we double up to have two
This allows us to use a two directional joystick to send two CC messages
*/

#include "MIDIUSB.h"

#define IN_PIN1 A0
#define IN_PIN2 A1
#define WINDOW_SIZE 15

//First Smoothed variables
int INDEX1 = 0;
int VALUE1 = 0;
int SUM1 = 0;
int READINGS1[WINDOW_SIZE];
int AVERAGED1 = 0;

//Second smoothed input
int INDEX2 = 0;
int VALUE2 = 0;
int SUM2 = 0;
int READINGS2[WINDOW_SIZE];
int AVERAGED2 = 0;

void setup() {
  pinMode(IN_PIN1, INPUT);
  pinMode(IN_PIN2, INPUT);
  Serial.begin(9600);
}

void loop() {
  
  SUM1 = SUM1 - READINGS1[INDEX1];       // Remove the oldest entry from the sum
  VALUE1 = analogRead(IN_PIN1);        // Read the next sensor value
  READINGS1[INDEX1] = VALUE1;           // Add the newest reading to the window
  SUM1 = SUM1 + VALUE1;                 // Add the newest reading to the sum
  INDEX1 = (INDEX1+1) % WINDOW_SIZE;   // Increment the index, and wrap to 0 if it exceeds the window size

  AVERAGED1 = SUM1 / WINDOW_SIZE;      // Divide the sum of the window by the window size for the result

  //Serial.print(VALUE1);
  // Serial.print(",");
  Serial.print(AVERAGED1);


  //Do it all of the smoothing logic again,
  //On a second input and second set of variables dedicated for that input

  SUM2 = SUM2 - READINGS2[INDEX2];       // Remove the oldest entry from the sum
  VALUE2 = analogRead(IN_PIN2);        // Read the next sensor value
  READINGS2[INDEX2] = VALUE2;           // Add the newest reading to the window
  SUM2 = SUM2 + VALUE2;                 // Add the newest reading to the sum
  INDEX2 = (INDEX2+1) % WINDOW_SIZE;   // Increment the index, and wrap to 0 if it exceeds the window size

  AVERAGED2 = SUM2 / WINDOW_SIZE;      // Divide the sum of the window by the window size for the result

  //Serial.print(VALUE2);
  Serial.print(",");
  Serial.println(AVERAGED2);


  //Using the MIDI library
  //Sending Control Change messages with these analog value

  //Needs values from 0 to 127, so we make new variables scaling those readings
  int mappedCC1 = map(AVERAGED1, 0, 1023, 0, 127);
  int mappedCC2 = map(AVERAGED2, 0, 1023, 0, 127);
  controlChange(1,1,mappedCC1);
  controlChange(1,2,mappedCC2);
  
  delay(25); 
}



// First parameter is the event type (0x0B = control change).
// Second parameter is the event type, combined with the channel.
// Third parameter is the control number number (0-119).
// Fourth parameter is the control value (0-127).

void controlChange(byte channel, byte control, byte value) {

  midiEventPacket_t event = {0x0B, 0xB0 | channel, control, value};

  MidiUSB.sendMIDI(event);
}
