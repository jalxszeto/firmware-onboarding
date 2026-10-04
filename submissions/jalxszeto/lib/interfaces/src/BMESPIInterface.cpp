#include "BMESPIInterface.h"

bool BMESPIInterface::init()
{
    return _bme.begin();
}

void BMESPIInterface::read_temperature()
{
    _temperature_c = _bme.readTemperature();
}

float BMESPIInterface::get_temperature_c() const
{
    return _temperature_c;
}