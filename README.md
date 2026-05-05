
# code_interview_C


STM32 Nucleo F767ZI project
Built using STM32CubeIDE 1.19
C coding interview project for programming a simple Voltage sensor 
  
A simple **AdcPeripheral** source file provides a getRawValue method that returns a random unsigned int meant to represent a fake ADC raw value coming from a sensed voltage

The **ISensor** source file defines a common set of methods fo any given sensor that would be implemented 

An empty **VoltageSensor** source exists that needs to be modified to :

-	Add gain and offset members in its context

-	Add a init method that receives gain, offset and a reference to an AdcPeripheral instance

-	Comply to the ISensor 'interface'

-	Add a getVoltage method that will return the converted raw value of the AdcPeripheral member using the gain and offset

- Add a simple test code in the main.c that instanciates the required objects to test the getVoltage method

Next step is to provide a way to manage multiple VoltageSensor structs through a **VoltageSensorManager** implementation that will :

-	Hold an array of VoltageSensor objects

-	Allow a VoltageSensor sensor object to be added to the array using an addSensor method

-	Provide a method named update() that will iterate over all the managed VoltageSensor in the array and compute the combined average voltage value

- Modify main.c to instantiates all necessary objects and provide a test code for computing the average of set of 10 voltage sensors instances