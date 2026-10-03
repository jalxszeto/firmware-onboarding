#pragma once
#include <Adafruit_BME280.h>
#include <etl/singleton.h>
#include "BMEConstants.h"

class BMESPIInterface
{
public:

    BMESPIInterface() = default;

    bool init();
    void read_temperature();
    float get_temperature_c() const;

private:

    Adafruit_BME280 _bme{BMEConstants::SPI_CS_PIN};
    float _temperature_c = 0.0f;


};
using BMESPIInterfaceInstance = etl::singleton<BMESPIInterface>;
