#ifndef VOLTAGESENSORMANAGER_H_
#define VOLTAGESENSORMANAGER_H_

#include <stddef.h>
#include <stdint.h>

#include "VoltageSensor.h"

#define VOLTAGE_SENSOR_MANAGER_MAX_SENSORS 16U

typedef struct
{
    VoltageSensor sensors[VOLTAGE_SENSOR_MANAGER_MAX_SENSORS];
    size_t sensorCount;
} VoltageSensorManager;

void VoltageSensorManager_init(VoltageSensorManager *self);
int VoltageSensorManager_addSensor(VoltageSensorManager *self, const VoltageSensor *sensor);
float VoltageSensorManager_computeAverageVoltage(VoltageSensorManager *self);

#endif
