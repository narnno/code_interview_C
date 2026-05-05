#ifndef VOLTAGESENSORMANAGER_HPP_
#define VOLTAGESENSORMANAGER_HPP_

#include <VoltageSensor.hpp>
#include <stdint.h>
#include <vector>
using namespace std;


class VoltageSensorManager{
    public:
		VoltageSensorManager();
        void addSensor(VoltageSensor sensor);
        float computeAverageVoltage();
    private:
        vector<VoltageSensor> sensors;

};

#endif
