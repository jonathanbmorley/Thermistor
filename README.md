# Thermistor
Simple Thermistor library for Arduino
## Instructions
First, clone the library locally and include it in your Arduino project.

`#include <Thermistor.h>`

Create an instance of the Thermistor to use as a global object. If your thermistor is plugged in to Analog 0, you'd do this:

`Thermistor thermistor = Thermistor(A0);`

By default, the class will compute Fahrenheit temperatures. If you'd like to use something else, you can either call `setDefaultTemperatureType` and pass the new temperature type (0 = Fahrenheit, 1 = Celcius, 2 = Kelvin), or you can call a specific method to get the temperature you need: `getTemperatureInF()`, `getTemperatureInC()`, or `getTemperatureInK()`

In your method call, you can read the temperature using the `getTemperature()` method, too:

`double reading = thermistor.getTemperature();`

As an example:

`double temperatureReading = thermistor.getTemperature();`
