
# code_interview_B


STM32 Nucleo F767ZI project
Built using STM32CubeIDE 1.19
C++ coding interview project for programming a simple Voltage sensor class
  
A simple **AdcPeripheral** class provides a getRawValue method that returns a random unsigned int meant to represent a fake ADC raw value coming from a sensed voltage

An interface class **ISensor** provides a common set of methods fo any given inheriting sensor

An empty **VoltageSensor** class exists that needs to be modified to :

-	Add gain and offset members

-	Add a constructor that receives gain, offset and a reference to an AdcPeripheral object

-	Comply to the ISensor interface class

-	Add a getVoltage method that will return the converted raw value of the AdcPeripheral object using the gain and offset

- Add a simple test code in the main.cpp that instanciates the required objects to test the getVoltage method

Next step is to provide a way to manage multiple VoltageSensor objects through a **VoltageSensorManager** class that will :

-	Hold an array/vector of VoltageSensor objects

-	Allow a VoltageSensor sensor object to be added to the array/vector using an addSensor method

-	Provide a method named update that will iterate over all the managed VoltageSensor objects and compute the combined average voltage value

- Modify main.cpp to instantiates all necessary objects and provide a test code for computing the average of set of 10 voltage sensors objects