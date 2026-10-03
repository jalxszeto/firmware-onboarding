#pragma once
#include <etl/singleton.h>
#include "BMEConstants.h"

class LEDController
{
public:

    LEDController() = default;

    void set_temperature(float temperature_c);
    void update(unsigned long now_ms);
    bool is_led_on() const;
    unsigned long get_blink_interval_ms() const;

    

private:

    unsigned long _blink_interval_ms = BMEConstants::SLOW_BLINK_MS;
    unsigned long _last_toggle_ms = 0;
    bool _led_on = false;

};
using LEDControllerInstance = etl::singleton<LEDController>;
