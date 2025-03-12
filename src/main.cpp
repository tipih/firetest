#include <Arduino.h>
#include <FastLED.h>

// Only one led is connected
#define NUM_LEDS 1

// The led is connected on IO5
#define DATA_PIN 5

// Define an array of one leds
CRGB leds[NUM_LEDS];

void setup() { 
  // Add array leds without SPI
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
  Serial.begin(9600);
  delay(1000);  //Take some time to open up the Serial Monitor
}

void loop() {   
  // Loop through rainbow colors
  Serial.println("In Loop");
  for (int i=0; i<=255;i++) {
    leds[0] = CHSV( i, 255, 100);
    FastLED.show();
    delay(16);
  }
}