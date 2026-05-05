#include <VoltageSensorManager.hpp>


VoltageSensorManager::VoltageSensorManager()
{

}

void VoltageSensorManager::addSensor(VoltageSensor sensor)
{
    sensors.push_back(sensor);
}

float VoltageSensorManager::computeAverageVoltage()
{
    if(sensors.empty())
    {
        return 0.0f;
    }

    float sum = 0.0f;
    for(auto& sensor : sensors)
    {
        sum += sensor.getVoltage();
    }
    return sum / sensors.size();
}
