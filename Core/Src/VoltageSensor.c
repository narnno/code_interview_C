#include "VoltageSensor.h"

#include <stddef.h>


ISensor VoltageSensor_asISensor(VoltageSensor *self)
{
    ISensor sensor;

    sensor.context = self;

    return sensor;
}
