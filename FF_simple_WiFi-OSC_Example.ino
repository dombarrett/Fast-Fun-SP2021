
//Example code for the Fast Fun ITP class about OSC communication
//Based off of the example code for the ArduinoOSC library

//Need to install ArduinoOSC library, and also WiFiNINA library from the library manager
//SAMD Board definitions required for the Arduino Nano IoT 33


#include <ArduinoOSC.h>

// WiFi stuff
const char* ssid = "myWifiName"; //YOUR WifiSSD name
const char* pwd = "myWifiPassword"; //YOUR PASSWORD - WATCH OUT - DON'T SHARE!
const IPAddress ip(192, 168, 1, 201); //The IP of the Arduino
const IPAddress gateway(192, 168, 1, 1);
const IPAddress subnet(255, 255, 255, 0);


// for ArduinoOSC

//What *local* ip are you sending the messages to? Your computer?
//Right now, mine is 192.168.1.129. Yours may be different.

//Find your local IP address
//https://www.avg.com/en/signal/find-ip-address

const char* host = "192.168.1.129";

const int publish_port = 54445;  //<-- this is what we're using to receive on the computer
// send / receive varibales


//The variables we will send
int button1State, button2State, button3State, button4State, button5State;

// We can send float and string variables with this library, as well


void setup()
{
    Serial.begin(115200);
    delay(2000);

    //Setting up our buttons
    //More direct than the previous MIDI example sketch- we have 5 inputs, so activate all 5 as INPUT_PULLUP
    pinMode(2, INPUT_PULLUP);
    pinMode(3, INPUT_PULLUP);
    pinMode(4, INPUT_PULLUP);
    pinMode(5, INPUT_PULLUP);
    pinMode(6, INPUT_PULLUP);
    

    // WiFi stuff (no timeout setting for WiFi)
    #ifdef ESP_PLATFORM
        WiFi.disconnect(true, true); // disable wifi, erase ap info
        delay(1000);
        WiFi.mode(WIFI_STA);
    #endif
        WiFi.begin(ssid, pwd);
        WiFi.config(ip, gateway, subnet);
        while (WiFi.status() != WL_CONNECTED) { Serial.print("."); delay(500); }
        Serial.print("WiFi connected, IP = "); Serial.println(WiFi.localIP());


    //We will continuously publish our values over the network.
    //You can send multiple values if you want: &millis and &micros are measurements of time since your arduino started up
    //You can schedule intervals in milliseconds for how frequently you want to send values over the network
    
    //OscWiFi.publish(host, publish_port, "/publish/func", &millis, &micros)
    //    ->setIntervalMsec(500.f);


    //Once we know we are sending values successfully, we can move on to detecting a button press
    //The sending of this value can be tied to "frameRate", ie 60 times a second

    //OscWiFi.publish(host, publish_port, "/publish/func", button2State)
    //    ->setFrameRate(60.f);

    //Then we can move onto receiving multiple values at once:
    
    OscWiFi.publish(host, publish_port, "/publish/func", button1State, button2State, button3State, button4State, button5State)
        ->setFrameRate(60.f);

}

void loop()
{
    //For all five of our input pins (2-6), read the high/low
    //With internal pullup resistors, we pull to ground for a button press
    //which means low=pressed, and all pins are default set to high
    //Hence: if low, button state is 1, if high button state is 0

    //Circuit is simple: connect ground to pin 2,3,4,5, or 6 and it will count as a 'button press'
    
      if (digitalRead(2) == LOW)
      {
        button1State = 1;
      }
      else
      {
        button1State = 0;
      }


      if (digitalRead(3) == LOW)
      {
        button2State = 1;
      }
      else
      {
        button2State = 0;
      }
      

      if (digitalRead(4) == LOW)
      {
        button3State = 1;
      }
      else
      {
        button3State = 0;
      }
      

      if (digitalRead(5) == LOW)
      {
        button4State = 1;
      }
      else
      {
        button4State = 0;
      }

      if (digitalRead(6) == LOW)
      {
        button5State = 1;
      }
      else
      {
        button5State = 0;
      }




    //Send/Receive OSC messages:
    OscWiFi.update();

    // or do that separately, if you are using the library in a different way
    // OscWiFi.parse(); // to receive osc
    // OscWiFi.post(); // to publish osc
}
