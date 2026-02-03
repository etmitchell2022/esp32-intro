#include <Arduino.h>
#include "01_blink/blinkingLight.h"
#define LED 2

BlinkingLight blinker(LED, 500);
void setup()
{
  // put your setup code here, to run once:
  blinker.begin();
}

void loop()
{
  // put your main code here, to run repeatedly:
  blinker.update();
}