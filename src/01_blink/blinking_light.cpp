#include "blinkingLight.h"
#include <Arduino.h>

BlinkingLight::BlinkingLight(int pin, unsigned long interval)
    : _pin(pin), _interval(interval), _lastToggle(0), _state(false) {}

void BlinkingLight::begin() {
    pinMode(_pin, OUTPUT);
    digitalWrite(_pin, LOW);
}

void BlinkingLight::update() {
    unsigned long now = millis();
    if (now - _lastToggle >= _interval) {
        _state = !_state;
        digitalWrite(_pin, _state ? HIGH : LOW);
        _lastToggle = now;
    }
}