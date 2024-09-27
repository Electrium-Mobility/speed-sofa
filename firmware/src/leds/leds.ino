#include <FastLED.h>

#define NUM_LEDS 60   //CHANGE TO ACTUAL NUMBER OF LEDS
#define DATA_PIN 6    //CHANGE TO CORRECT PIN FOR LED STRIP
#define BRAKE_PIN 34  // Analog pin for brake sensor input CHANGE TO CORRECT PIN

CRGB leds[NUM_LEDS];

void setup() {
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
  pinMode(BRAKE_PIN, INPUT);
  Serial.begin(115200);
}

void loop() {
  int brakeValue = analogRead(BRAKE_PIN);
  Serial.println(brakeValue);  // Print brake value for debugging
 if (brakeValue > 2000) {  // ESP32 12-bit ADC, value range: 0-4095
    fill_solid(leds, NUM_LEDS, CRGB::Red);  //red if brakes are depressed
  } else {
    fill_solid(leds, NUM_LEDS, CRGB::Black); //off if brakes are not depressed
  }
  FastLED.show();
}
