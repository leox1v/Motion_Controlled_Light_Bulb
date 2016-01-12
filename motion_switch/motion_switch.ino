//
// motion_switch
//
// Description of the project
// Developed with [embedXcode](http://embedXcode.weebly.com)
//
// Author 		Marco Heyden
// 				Marco Heyden
//
// Date			09.12.15 00:59
// Version		<#version#>
//
// Copyright	© Marco Heyden, 2015
// Licence		<#licence#>
//
// See         ReadMe.txt for references
//


// Core library for code-sense - IDE-based
#if defined(WIRING) // Wiring specific
#   include "Wiring.h"
#elif defined(MAPLE_IDE) // Maple specific
#   include "WProgram.h"
#elif defined(MPIDE) // chipKIT specific
#   include "WProgram.h"
#elif defined(DIGISPARK) // Digispark specific
#   include "Arduino.h"
#elif defined(ENERGIA) // LaunchPad specific
#   include "Energia.h"
#elif defined(LITTLEROBOTFRIENDS) // LittleRobotFriends specific
#   include "LRF.h"
#elif defined(MICRODUINO) // Microduino specific
#   include "Arduino.h"
#elif defined(SPARK) || defined(PARTICLE) // Particle / Spark specific
#   include "Arduino.h"
#elif defined(TEENSYDUINO) // Teensy specific
#   include "Arduino.h"
#elif defined(REDBEARLAB) // RedBearLab specific
#   include "Arduino.h"
#elif defined(ESP8266) // ESP8266 specific
#   include "Arduino.h"
#elif defined(ARDUINO) // Arduino 1.0 and 1.5 specific
#   include "Arduino.h"
#else // error
#   error Platform not defined
#endif // end IDE


// Include application, user and local libraries

// Prototypes

uint32_t seconds(uint32_t seconds);
void turnLightOnAndWait();


// Define variables and constants

const int pinOn = 10;
int sense = 0;


// Setup Code
void setup() {
  pinMode(pinOn, OUTPUT); // pin that triggers the relay
  pinMode(sense, A0);  // analog input motion sensor
}


// Loop Code
void loop() {
  turnLightOnAndWait();
  digitalWrite(pinOn, LOW); // Turn light off
}


uint32_t seconds(uint32_t seconds) {
  uint32_t mSeconds = seconds * 1000;
  return mSeconds;
}


void turnLightOnAndWait() {
  uint16_t sensorInput = analogRead(sense);
  if (sensorInput > 500) {
    digitalWrite(pinOn, HIGH);
    unsigned long startMillis = millis();
    while (millis() - startMillis < seconds(90)); // waits for 90 seconds
  }
}






