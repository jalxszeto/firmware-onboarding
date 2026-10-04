#pragma once
#include <Arduino.h>

namespace BMEConstants
{
    // Sensor
    constexpr uint8_t I2C_ADDRESS = 0x77;   // Adafruit default; some boards use 0x76
    constexpr uint8_t SPI_CS_PIN = 10;      // Hardware SPI: MOSI 11, MISO 12, SCK 13

    // LED
    constexpr uint8_t LED_PIN = 9;          // Not 13, since SCK uses it in SPI mode

    // Temperature -> blink mapping
    constexpr float MIN_TEMP_C = 20.0f;
    constexpr float MAX_TEMP_C = 35.0f;
    constexpr unsigned long SLOW_BLINK_MS = 1000;   // at or below MIN_TEMP_C
    constexpr unsigned long FAST_BLINK_MS = 100;    // at or above MAX_TEMP_C

    // How often to read the sensor
    constexpr unsigned long READ_INTERVAL_MS = 500;
}
