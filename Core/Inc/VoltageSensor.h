#ifndef VOLTAGESENSOR_H_
#define VOLTAGESENSOR_H_

#include <stdint.h>

#include "AdcPeripheral.h"
#include "ISensor.h"

typedef struct
{
    int16_t offset;
    float gain;
    AdcPeripheral *adc;
} VoltageSensor;

void VoltageSensor_init(VoltageSensor *self, int16_t offset, float gain, AdcPeripheral *adc);
uint16_t VoltageSensor_getRawValue(VoltageSensor *self);
float VoltageSensor_getGain(const VoltageSensor *self);
int16_t VoltageSensor_getOffset(const VoltageSensor *self);
float VoltageSensor_getVoltage(VoltageSensor *self);
ISensor VoltageSensor_asISensor(VoltageSensor *self);

#endif
