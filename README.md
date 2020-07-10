# Thermistor
Simple Thermistor library for Arduino
## Instructions
First, clone the library locally and include it in your Arduino project.

#include <Thermistor.h>

Create an instance of the Thermistor to use as a global object. If your thermistor is plugged in to Analog 0, you'd do this:

`Thermistor thermistor = Thermistor(A0);`

In your method call, you can read the temperature:

`double reading = thermistor.getTemperature();`
