#include <Arduino.h>
#include "BMEI2CInterface.h"
#include "LEDController.h"
#include "BMEConstants.h"


void setup()
{
    Serial.begin(115200);
    pinMode(BMEConstants::LED_PIN, OUTPUT);

    BMEI2CInterfaceInstance::create();
    LEDControllerInstance::create();

    if (!BMEI2CInterfaceInstance::instance().init())
    {
        Serial.println("BME280 not found over I2C.");
        while (true) {}
    }
    Serial.println("BME280 found over I2C.");
}

void loop()
{
    static unsigned long last_read_ms = 0;
    unsigned long now_ms = millis();

    if (now_ms - last_read_ms >= BMEConstants::READ_INTERVAL_MS)
    {
        last_read_ms = now_ms;
        BMEI2CInterfaceInstance::instance().read_temperature();

        float temp_c = BMEI2CInterfaceInstance::instance().get_temperature_c();
        LEDControllerInstance::instance().set_temperature(temp_c);

        Serial.print("Temperature: ");
        Serial.print(temp_c);
        Serial.print(" C, Blink Interval: ");
        Serial.print(LEDControllerInstance::instance().get_blink_interval_ms());
        Serial.println(" ms");
    }

    LEDControllerInstance::instance().update(now_ms);
    digitalWrite(BMEConstants::LED_PIN, LEDControllerInstance::instance().is_led_on() ? HIGH : LOW);

}
