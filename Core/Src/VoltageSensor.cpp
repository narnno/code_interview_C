#include <VoltageSensor.hpp>


VoltageSensor::VoltageSensor(uint16_t offset, float gain, AdcPeripheral& adc) : offset(offset), gain(gain), adc(adc)
{

}

uint16_t VoltageSensor::getRawValue()
{
    return adc.getRawValue();
}

float VoltageSensor::getGain()
{
    return gain;
}

int16_t VoltageSensor::getOffset()
{
    return offset;
}

float VoltageSensor::getVoltage()
{
    return (getRawValue() + getOffset()) * getGain();
}
