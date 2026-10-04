#pragma once
#include <Adafruit_BME280.h>
#include <etl/singleton.h>
#include "BMEConstants.h"


class BMEI2CInterface
{
public:

    BMEI2CInterface() = default;

    // Starts the sensor. Returns false if it can't be found (wiring / address problem).
    bool init();

    // Reads the sensor and stores the latest temperature.
    void read_temperature();

    // Returns the last stored temperature in Celsius.
    float get_temperature_c() const;

private:

    Adafruit_BME280 _bme;   // No-arg constructor = I2C mode
    float _temperature_c = 0.0f;

};
using BMEI2CInterfaceInstance = etl::singleton<BMEI2CInterface>;
