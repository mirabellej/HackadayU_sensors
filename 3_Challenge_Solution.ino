#include <Adafruit_CircuitPlayground.h>
#include <Wire.h>
#include <SPI.h>
#include <FastLED.h>


// define cap touch pin
// define threshold
#define CAP_PIN1 A1 // change this number to read a different pin! 
#define THRESHOLD 500 // the min. reading we're counting as a touch!

#define CLICKTHRESHHOLD 120

bool slideSwitch;

#define NUM_LEDS 10
#define DATA_PIN 8

CRGB leds[NUM_LEDS];

int brightness = 0;

// timing?

void setup() {
  Serial.begin(9600);
  CircuitPlayground.begin();
  // set up for our accelerometer (interrupt, etc.)

  FastLED.addLeds<WS2811, DATA_PIN, RGB>(leds, NUM_LEDS);
  fill_solid(leds, NUM_LEDS, CHSV(255, 10, brightness));
  FastLED.show();

  brightness++;

  CircuitPlayground.setAccelRange(LIS3DH_RANGE_2_G);   // 2, 4, 8 or 16 G!

  // 0 = turn off click detection & interrupt
  // 1 = single click only interrupt output
  // 2 = double click only interrupt output, detect single click
  // Adjust threshhold, higher numbers are less sensitive
  CircuitPlayground.setAccelTap(2, CLICKTHRESHHOLD);

  // have a procedure called when a tap is detected
  attachInterrupt(digitalPinToInterrupt(CPLAY_LIS3DH_INTERRUPT), tapTime, FALLING);

}

void tapTime(void) {
  // do something :)
  CircuitPlayground.playTone(500,1000); 
}


void breathingPattern() {
  static int8_t fadeStep = 1;

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

void capToLighting() {
  slideSwitch = CircuitPlayground.slideSwitch();

  int capData = CircuitPlayground.readCap(CAP_PIN1);

  if (capData > THRESHOLD) {
    if (slideSwitch) {
      for (int i = 0; i < 10; i++) { // use a for loop to go from one pixel to the next
        CircuitPlayground.setPixelColor(i, 255,   0,   0); // and set the color for the that pixel in RGB
      }
    } else {
      for (int i = 0; i < 10; i++) { // use a for loop to go from one pixel to the next
        CircuitPlayground.setPixelColor(i, 0,   255,   0); // and set the color for the that pixel in RGB
      }
    }
  }
  else {
    breathingPattern();
  }
}


void loop() {

  capToLighting();

}
