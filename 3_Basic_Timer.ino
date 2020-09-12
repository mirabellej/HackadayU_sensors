#include <Adafruit_CircuitPlayground.h>
#define EVENT_UPDATE_TIME 1000 // in milliseconds 
unsigned long timingMillis = 0; // MUST be an unsigned long otherwise you can accidentally overflow the variable!

void setup() {
  Serial.begin(9600); 
}

void loop()
{
  if (millis() > timingMillis)  //test whether the period has elapsed
  {
    // DO SOMETHING
    Serial.println("boop");
    //CircuitPlayground.playTone(500,1000); 
    timingMillis = millis() + EVENT_UPDATE_TIME; // the last thing inside your timer control block is always saving the target time for the next loop around!
  }
}
