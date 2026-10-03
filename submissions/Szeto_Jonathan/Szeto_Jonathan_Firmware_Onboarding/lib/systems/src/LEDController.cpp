#include "LEDController.h"


void LEDController::set_temperature(float temperature_c) 
{
    if (temperature_c <= BMEConstants::MIN_TEMP_C)
    {
        _blink_interval_ms = BMEConstants::SLOW_BLINK_MS;
    } 
    else if (temperature_c >= BMEConstants::MAX_TEMP_C)
    {
        _blink_interval_ms = BMEConstants::FAST_BLINK_MS;
    } 
    else 
    {
        _blink_interval_ms = BMEConstants::SLOW_BLINK_MS - (temperature_c - BMEConstants::MIN_TEMP_C) / (BMEConstants::MAX_TEMP_C - BMEConstants::MIN_TEMP_C) * (BMEConstants::SLOW_BLINK_MS - BMEConstants::FAST_BLINK_MS);
    }
}

void LEDController::update(unsigned long now_ms)
{
    if (now_ms - _last_toggle_ms >= _blink_interval_ms)
    {
        _led_on = !_led_on;
        _last_toggle_ms = now_ms;
    }
}

bool LEDController::is_led_on() const
{
    return _led_on;
}

unsigned long LEDController::get_blink_interval_ms() const
{
    return _blink_interval_ms;
}
