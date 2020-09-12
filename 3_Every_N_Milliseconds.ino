// Using DELAY stops our microcontroller's processes completely!
// This can be a problem if we want two things to happen simultaneously.
// To solve this problem, we can use the EVERY_N_Milleseconds function.

// The following sketch does a breathing pattern for LEDs AND reads a cap touch sensor. 

#include <Adafruit_CircuitPlayground.h>

#define CAP_PIN1 A1 // change this number to read a different pin!
#define THRESHOLD 500 // the min. reading we're counting as a touch!
#include <FastLED.h>

// How many leds in your strip?
#define NUM_LEDS 10

// For led chips like Neopixels, which have a data line, ground, and power, you just
// need to define DATA_PIN.  For led chipsets that are SPI based (four wires - data, clock,
// ground, and power), like the LPD8806, define both DATA_PIN and CLOCK_PIN
#define DATA_PIN 8

// Define the array of leds
CRGB leds[NUM_LEDS];

int brightness = 0;

void setup()
{
  FastLED.addLeds<WS2811, DATA_PIN, RGB>(leds, NUM_LEDS);
  CircuitPlayground.begin();

  // apply and show initial brightness
  fill_solid(leds, NUM_LEDS, CHSV(255, 10, brightness));
  FastLED.show();

  brightness++;
}

void loop()
{
  static int8_t fadeStep = 1;

  EVERY_N_MILLISECONDS(250)
  {
    // saves the cap touch data to a variable "capData"
    int capData = CircuitPlayground.readCap(CAP_PIN1);
    // print the data
    Serial.print("Capacitive Touch Reading: ");
    Serial.println(capData);

    // do something IF the touch pad is being touched!
    if (capData > THRESHOLD) {
      Serial.println("TOUCHED!");
      CircuitPlayground.playTone(500, 1000); 
    }
    else {
      // do nothing - you can replace this to have a "default" mode
    }
  }

  EVERY_N_MILLISECONDS(10)
  {
    // if the last time brightness was 255 or 0, change the direction from increase to descrease or vice versa
    if (brightness == 255 or brightness == 0)
    {
      fadeStep *= -1;
    }
    brightness += fadeStep;

    fill_solid(leds, NUM_LEDS, CHSV(255, 10, brightness));
    FastLED.show();
  }


}
