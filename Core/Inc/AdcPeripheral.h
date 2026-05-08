#ifndef ADCPERIPHERAL_H_
#define ADCPERIPHERAL_H_

#include <stdint.h>

typedef struct
{
  uint8_t initialized;
} AdcPeripheral;

void AdcPeripheral_init(AdcPeripheral *self);
uint16_t AdcPeripheral_getRawValue(AdcPeripheral *self);

#endif
