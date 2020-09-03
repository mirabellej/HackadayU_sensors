#include <Adafruit_CircuitPlayground.h> // include circuit playground library

float sound_value; // this variable will store our sound data
float THRESHOLD = 65.0; // at what SPL are we detecting a sound?

void setup() {
  Serial.begin(9600); // initialize serial
  CircuitPlayground.begin(); // initialize Circuit Playground
}

void loop() {

  sound_value = CircuitPlayground.mic.soundPressureLevel(10);
  
  //Serial.print("Sound Sensor SPL: "); 
  //Serial.println(sound_value); 
  
  if (sound_value > THRESHOLD){
    Serial.println("SOUND DETECTED");
  }
  else{
    Serial.println("Silence is golden..."); 
  }

  delay(200); // short delay 
}
