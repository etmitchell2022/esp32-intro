#include "blinkingLight.h"
#include <Arduino.h>

BlinkingLight::BlinkingLight(int pin)
    : _pin(pin), _mode(BlinkMode::OFF), _lastToggle(0), _state(false), _doubleStep(0) {}

void BlinkingLight::begin()
{
    pinMode(_pin, OUTPUT);
    digitalWrite(_pin, LOW);
}

void BlinkingLight::setMode(BlinkMode mode)
{
    _mode = mode;
    _lastToggle = millis();
    _state = true;
    digitalWrite(_pin, LOW);
}

void BlinkingLight::update()
{
    switch (_mode)
    {
    case BlinkMode::OFF:
        handleOff();
        break;
    case BlinkMode::SLOW:
        handleSlow();
        break;
    case BlinkMode::FAST:
        handleFast();
        break;
    case BlinkMode::DOUBLE:
        handleDouble();
        break;
    }
}

void BlinkingLight::handleOff()
{
    digitalWrite(_pin, LOW);
}

void BlinkingLight::handleSlow()
{
    unsigned long now = millis();
    if (now - _lastToggle >= 500)
    {
        _state = !_state;
        digitalWrite(_pin, _state ? HIGH : LOW);
        _lastToggle = now;
    }
}

void BlinkingLight::handleFast()
{
    unsigned long now = millis();
    if (now - _lastToggle >= 250)
    {
        _state = !_state;
        digitalWrite(_pin, _state ? HIGH : LOW);
        _lastToggle = now;
    }
}

void BlinkingLight::handleDouble()
{
    unsigned long now = millis();

    switch (_doubleStep)
    {
    case 0: // ON
        digitalWrite(_pin, HIGH);
        _lastToggle = now;
        _doubleStep = 1;
        break;

    case 1: // OFF (100ms)
        if (now - _lastToggle >= 100)
        {
            digitalWrite(_pin, LOW);
            _lastToggle = now;
            _doubleStep = 2;
        }
        break;

    case 2: // ON (100ms)
        if (now - _lastToggle >= 100)
        {
            digitalWrite(_pin, HIGH);
            _lastToggle = now;
            _doubleStep = 3;
        }
        break;

    case 3: // OFF (700ms pause)
        if (now - _lastToggle >= 700)
        {
            digitalWrite(_pin, LOW);
            _doubleStep = 0;
        }
        break;
    }
}
