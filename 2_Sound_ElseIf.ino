#include <Adafruit_CircuitPlayground.h> // include circuit playground library

float sound_value; // this variable will store our sound data
float MEDIUM = 65.0; // value for a medium sound
float LOUD = 70.0 // value for a loud sound

void setup() {
  Serial.begin(9600); // initialize serial
  CircuitPlayground.begin(); // initialize Circuit Playground
}

void loop() {

  sound_value = CircuitPlayground.mic.soundPressureLevel(10);
  
  //Serial.print("Sound Sensor SPL: "); 
  //Serial.println(sound_value); 
  
  if (sound_value >= LOUD){
    Serial.println("LOUD");
  }
  else if(sound_value < LOUD && sound_value >= MEDIUM){
    Serial.println("MEDIUM");
  }
  else{
    Serial.println("QUIET"); 
  }

  delay(200); // short delay 
}
