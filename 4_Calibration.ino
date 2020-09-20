/*
   Sketch for auto-calibrating your Adafruit Circuit Plauground sensors!
   Demonstrates one technique for calibrating sensor input. The sensor readings
   during the first five seconds of the sketch execution define the minimum and
   maximum of expected values attached to the sensor pin.

   Adapted by Mirabelle Jones from the arduino calibration tutorial by David A Mellis modified by Tom Igoe.
*/

#include <Adafruit_CircuitPlayground.h>

const int SENSOR_PIN = A1;    // pin for your sensor - change as appropriate! Not needed for onboard sensors that aren't cap touch.

int sensorValue = 0;       // the sensor value
int sensorMin = 0;        // minimum sensor value
int sensorMax = 1023;     // maximum sensor value

int THRESHOLD = 200; // a value betweeen 0 and 255 - change depending on how sensitive you want your sensor to be!

int DEBOUNCE = 100; // debounce delay amount - you can replace this with a timer if desired

void setup() {
  Serial.begin(9600); // initialize serial
  delay(3000); // warm up delay

  CircuitPlayground.begin(); // initialize circuit playground

  // calibrate during the first five seconds
  while (millis() < 5000) {
    sensorValue = CircuitPlayground.readCap(SENSOR_PIN); // set this to whatever is the function for reading for your sensor - see below

    // record the maximum sensor value
    if (sensorValue > sensorMax) {
      sensorMax = sensorValue;
    }

    // record the minimum sensor value
    if (sensorValue < sensorMin) {
      sensorMin = sensorValue;
    }
  }
}

void loop() {
  // read the sensor and store as sensorValue
  // comment / uncomment different lines to set sensorValue to store the value of a different sensor!

  sensorValue = CircuitPlayground.readCap(SENSOR_PIN);
  // sensorValue = CircuitPlayground.lightSensor();
  // sensorValue = CircuitPlayground.mic.soundPressureLevel(10);
  // sensorValue = CircuitPlayground.temperature();
  // sensorValue = CircuitPlayground.temperatureF();
  Serial.println("Raw Value:");
  Serial.println(sensorValue);


  // apply the calibration to the sensor reading
  sensorValue = map(sensorValue, sensorMin, sensorMax, 0, 255);

  Serial.println("Mapped Value:");
  Serial.println(sensorValue);

  // in case the sensor value is outside the range seen during calibration
  sensorValue = constrain(sensorValue, 0, 255);

  Serial.println("Constrained Value:");
  Serial.println(sensorValue);

  if (sensorValue > THRESHOLD) {
    // output - your interactivity goes here!
    CircuitPlayground.playTone(100, 500); // play a tone of 100 hz for 500 milliseconds
    Serial.println("triggered");
  }
  else {
    // do something whenever the sensor isn't being triggered
  }

  delay(DEBOUNCE);

}
