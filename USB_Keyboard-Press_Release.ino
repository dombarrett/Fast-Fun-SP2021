/*
 Fast Fun example for different approaches to sending keyboard events

  The built in example for sending keyboard events uses keyboard.write()
  But
  You can also specify a press() event and release() event
  This lets you create "press and hold" events

  Look at the keyboard libarary documentation example here:
  https://www.arduino.cc/reference/en/language/functions/usb/keyboard/keyboardpress/
  https://www.arduino.cc/reference/en/language/functions/usb/keyboard/keyboardrelease/

  https://www.arduino.cc/reference/en/language/functions/usb/keyboard/

*/

#include <Keyboard.h>

void setup() {
  // Internal pullup resistors for input pins 2 and 3
  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
  // initialize control over the keyboard:
  Keyboard.begin();

}

void loop() {
  //Two different ways of thinking about pressing a keyboard
  //1) Are we sending the keyboard key in one action?
  //2) Or are we breaking out the action into two parts:
  //  pressing the key and then releasing the key

  //1) Sending the key in one action
  if (digitalRead(2) == LOW) {
    Keyboard.write('w');
  }

  //or
  
  //2) Separate press and release actions
  if (digitalRead(3) == LOW) {
    //If internal pullup detects button press, we keyboard press
    Keyboard.press('s');
  } else {
    //When that pin turns inactive, we release
    Keyboard.release('s');
  }

  //Maybe we prefer one approach over the other,
  //There is no "right" way
  //
  //If you prefer method #1 but it is too fast,
  //try adding a delay to slow down the speed of your sketch

  delay(100); //<-experiment with different amounts of delay
  //Using delay in this manner
  //may interfere with the performance of method #2
  
}



/*
 * Making some space at the bottom here to test out your board presses 
 * Put your keyboard cursor down here to test the presses without messing other things up!
 * 
 * 
 * 
 * 
 */
