#include "VoltageSensor.h"

#include <stddef.h>


static uint16_t VoltageSensor_getRawValueFromContext(void *context)
{
    return VoltageSensor_getRawValue((VoltageSensor *)context);
}

static float VoltageSensor_getGainFromContext(void *context)
{
    return VoltageSensor_getGain((const VoltageSensor *)context);
}

static int16_t VoltageSensor_getOffsetFromContext(void *context)
{
    return VoltageSensor_getOffset((const VoltageSensor *)context);
}

void VoltageSensor_init(VoltageSensor *self, int16_t offset, float gain, AdcPeripheral *adc)
{
    if (self == NULL)
    {
        return;
    }

    self->offset = offset;
    self->gain = gain;
    self->adc = adc;
}

uint16_t VoltageSensor_getRawValue(VoltageSensor *self)
{
    if ((self == NULL) || (self->adc == NULL))
    {
        return 0U;
    }

    return AdcPeripheral_getRawValue(self->adc);
}

float VoltageSensor_getGain(const VoltageSensor *self)
{
    if (self == NULL)
    {
        return 0.0f;
    }

    return self->gain;
}

int16_t VoltageSensor_getOffset(const VoltageSensor *self)
{
    if (self == NULL)
    {
        return 0;
    }

    return self->offset;
}

float VoltageSensor_getVoltage(VoltageSensor *self)
{
    return (VoltageSensor_getRawValue(self) + VoltageSensor_getOffset(self)) * VoltageSensor_getGain(self);
}

ISensor VoltageSensor_asISensor(VoltageSensor *self)
{
    ISensor sensor;

    sensor.context = self;
    sensor.getRawValue = VoltageSensor_getRawValueFromContext;
    sensor.getGain = VoltageSensor_getGainFromContext;
    sensor.getOffset = VoltageSensor_getOffsetFromContext;

    return sensor;
}
