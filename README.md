# Thermistor
This is a simple thermistor library for Arduino. I used a NTC-MF52 pull-up thermistor from Velleman (5V on an Arduino Uno).
## Instructions
First, clone the library and include it in your \libraries\ folder within your Arduino project. 
If this is your first library, you may need to create the \libraries\ subfolder.

For example:
```
\arduino_project\
|...............\your_sketch.ino
\libraries\
|.........\Thermistor\
|....................\Thermistor.h
|....................\Thermistor.cpp
```
Add the include to the top of your Sketch file.

`#include <Thermistor.h>`

Create an instance of the Thermistor to use as a global object. If your thermistor is plugged in to Analog 0, you'd do this:

`Thermistor myThermistor = Thermistor(A0);`

By default, the class will compute Fahrenheit temperatures. If you'd like to use something else, you can either call `setDefaultTemperatureType` and pass the new temperature type (0 = Fahrenheit, 1 = Celcius, 2 = Kelvin), or you can call a specific method to get the temperature you need: `getTemperatureInF()`, `getTemperatureInC()`, or `getTemperatureInK()`

In your method call, you can read the temperature using the `getTemperature()` method:

`double temperatureReading = myThermistor.getTemperature();`

For a complete example, check out the \examples\ folder.
