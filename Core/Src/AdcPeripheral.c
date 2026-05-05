#include "AdcPeripheral.h"

#include <stdlib.h>


#undef RAND_MAX
#define RAND_MAX 65534

void AdcPeripheral_init(AdcPeripheral *self)
{
    if (self == NULL)
    {
        return;
    }

    srand(0);
    self->initialized = 1U;
}

uint16_t AdcPeripheral_getRawValue(AdcPeripheral *self)
{
    if (self == NULL)
    {
        return 0U;
    }

    if (self->initialized == 0U)
    {
        AdcPeripheral_init(self);
    }

    return (uint16_t)(rand() % RAND_MAX);
}
