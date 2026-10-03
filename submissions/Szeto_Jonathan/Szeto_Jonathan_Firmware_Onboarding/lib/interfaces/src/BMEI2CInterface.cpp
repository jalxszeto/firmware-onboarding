#include "BMEI2CInterface.h"

bool BMEI2CInterface::init()
{
    return _bme.begin(BMEConstants::I2C_ADDRESS);
}

void BMEI2CInterface::read_temperature()
{
    _temperature_c = _bme.readTemperature();
}

float BMEI2CInterface::get_temperature_c() const
{
    return _temperature_c;
}
