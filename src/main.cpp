#include <Arduino.h>
#include "02_blink_patterns/blinkingLight.h"
#define LED 2

BlinkingLight led(LED);
void setup()
{
  // put your setup code here, to run once:
  led.begin();
  led.setMode(BlinkMode::FAST);
}

void loop()
{
  // put your main code here, to run repeatedly:
  led.update();
}