/*
   Simple state machine for control of outputs based on sensor input
   This example shows how to set interactivity for three lighting levels using the Adafruit Circuit Playground Express's light sensor
   Sketch by Mirabelle Jones for HackadayU 2020
*/

#include <Adafruit_CircuitPlayground.h>

// What states can we have? For LEDs this might be levels, patterns, etc. For sound this might be frequency. For motion this might be rotation or speed.
enum state {NIGHT, OVERCAST, SUNNY}; // define three states for our output

// We want to keep track of our current output state and previous state
int state = 6; // I've updated these from the video to be impossible values just to demonstrate they need to be different
int lastState = 7; // I've updated these from the video to be impossible values just to demonstrate they need to be different

// How often should we check our sensor in milliseconds?
#define EVENT_UPDATE_TIME 1000 // in milliseconds 
unsigned long timingMillis = 0; //

// Values for our sensor comparison
int LOW_LIGHT = 100; // you can adjust this to whatever the light sensor reading for night time is for you!
int BRIGHT_LIGHT = 300; // you can adjust this to whatever the light sensor reading for a sunny day is for you!

void setup() {
  Serial.begin(9600); // initialize circuit playground
  CircuitPlayground.begin(); // initialize circuit playground
  delay(3000); // three second warm up delay

}    

void loop() {

  // check our timer to see if it's time to run our loop!
  if (millis() > timingMillis) {
    int sensorVal = CircuitPlayground.lightSensor(); // store the value from our light sensor

    if (sensorVal <= LOW_LIGHT) {
      state = NIGHT;
    }
    else if (sensorVal > LOW_LIGHT && sensorVal < BRIGHT_LIGHT) {
      state = OVERCAST;
    }
    else if (sensorVal >= BRIGHT_LIGHT) {
      state = SUNNY;
    }
    else {
      Serial.println("sensor out of range");
    }

    // only change our output if it needs to be changed
    if (state != lastState) {

      switch (state) { 
        case NIGHT:// what should we do when our sensor tells us it's night?
          Serial.println("NIGHT");
          break;
        case OVERCAST: // what should we do when our sensor tells us it's overcast?
          Serial.println("OVERCAST");
          break;
        case SUNNY: // what should we do when our sensor tells us it's sunny?
          Serial.println("SUNNY");
          break;
        default: // this should never happen but is always good practice to have in!
          Serial.println("do nothing");
          break;

      }
    }

    // keep track of our state by updating the last state variables!
    lastState = state;
    
    // update our timer
    timingMillis = millis() + EVENT_UPDATE_TIME;
  }

}
