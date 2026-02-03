
#pragma once

class BlinkingLight
{
public:
    BlinkingLight(int pin, unsigned long interval);
    void begin();
    void update();

private:
    int _pin;
    unsigned long _interval;
    unsigned long _lastToggle;
    bool _state;
};