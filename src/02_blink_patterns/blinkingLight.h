
enum class BlinkMode
{
    OFF,
    SLOW,
    FAST,
    DOUBLE
};

class BlinkingLight
{
public:
    BlinkingLight(int pin);
    void begin();
    void update();
    void setMode(BlinkMode mode);

private:
    void handleOff();
    void handleSlow();
    void handleFast();
    void handleDouble();

    int _pin;
    BlinkMode _mode;
    unsigned long _lastToggle;
    bool _state;

    int _doubleStep;
};