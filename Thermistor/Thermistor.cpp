/*
 * Thermistor.cpp - Library for reading from a thermistor.
 * Created by Jonathan Morley, July 9, 2020
 * Released into the public domain using open-source code.
 *
 * Temperature Types:
 * 0 -- Fahrenheit (Default)
 * 1 -- Celcius
 * 2 -- Kelvin
 */

#include "Thermistor.h"

// Constructor with solely the analog pin to read (i.e. A0, A1, A2, ...)
 Thermistor::Thermistor(int analogPin)
 {
  	_analogPin = analogPin;
  	_defaultTemperatureType = 0;
 }

// Optional constructor with the analog pin to read and default type of temperature to read
 Thermistor::Thermistor(int analogPin, int defaultTemperatureType)
 {
  	_analogPin = analogPin;
  	setDefaultTemperatureType(defaultTemperatureType);
 }

// Set the default temperature reading
// 1 = Fahrenheit, 2 = Celcius, 3 = Kelvin
 void Thermistor::setDefaultTemperatureType(int defaultTemperatureType)
 {
	 // If the call is not 0, 1, or 2, set the default to Fahrenheit
	 if (defaultTemperatureType < 0 || defaultTemperatureType > 2)
	 	_defaultTemperatureType = 0;
	 else
		_defaultTemperatureType = defaultTemperatureType;
}

void Thermistor::setTemperatureToF()
{
	setDefaultTemperatureType(0);
}

void Thermistor::setTemperatureToC()
{
	setDefaultTemperatureType(1);
}

void Thermistor::setTemperatureToK()
{
	setDefaultTemperatureType(2);
}

double Thermistor::getTemperature()
{
	if (_defaultTemperatureType == 0) return getTemperatureInF();
	else if (_defaultTemperatureType == 1) return getTemperatureInC();
	return getTemperatureInK();
 }


 double Thermistor::getTemperatureInF()
 {
	   double temperature = getTemperatureInC();
	   temperature = (temperature * 9.0) / 5.0 + 32.0; // Convert Celcius to Fahrenheit
	   return temperature;
 }

 double Thermistor::getTemperatureInC()
 {
	double temperature = getTemperatureInK();
	temperature = temperature - 273.15; // Convert Kelvin to Celcius
   	return temperature;
 }

 double Thermistor::getTemperatureInK()
 {
	double analogReading = analogRead(_analogPin);
	double temperature = analogReading;
	temperature = log(10000.0/(1024.0/temperature-1)); // for pull-up configuration
	temperature = 1 / (0.001129148 + (0.000234125 + (0.0000000876741 * temperature * temperature ))* temperature );
   	return temperature;
}