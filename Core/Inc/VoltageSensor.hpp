#ifndef VOLTAGESENSOR_HPP_
#define VOLTAGESENSOR_HPP_

#include <ISensor.hpp>
#include <AdcPeripheral.hpp>
#include <stdint.h>

class VoltageSensor : public ISensor{
    public:
        VoltageSensor(uint16_t offset, float gain, AdcPeripheral& adc);
        virtual float getVoltage();
        virtual uint16_t getRawValue();
        virtual float getGain();
        virtual int16_t getOffset();

    private:
        uint16_t offset;
        float gain;
        AdcPeripheral& adc;
};

#endif
