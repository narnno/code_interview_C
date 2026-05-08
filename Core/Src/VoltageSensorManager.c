#include "VoltageSensorManager.h"


void VoltageSensorManager_init(VoltageSensorManager *self)
{
    if (self == NULL)
    {
        return;
    }

    self->sensorCount = 0U;
}

int VoltageSensorManager_addSensor(VoltageSensorManager *self, const VoltageSensor *sensor)
{
    if ((self == NULL) || (sensor == NULL))
    {
        return 0;
    }

    if (self->sensorCount >= VOLTAGE_SENSOR_MANAGER_MAX_SENSORS)
    {
        return 0;
    }

    self->sensors[self->sensorCount] = *sensor;
    self->sensorCount++;

    return 1;
}

float VoltageSensorManager_computeAverageVoltage(VoltageSensorManager *self)
{
    if ((self == NULL) || (self->sensorCount == 0U))
    {
        return 0.0f;
    }

    float sum = 0.0f;
    size_t idx;
    for (idx = 0U; idx < self->sensorCount; idx++)
    {
        sum += VoltageSensor_getVoltage(&self->sensors[idx]);
    }

    return sum / (float)self->sensorCount;
}
