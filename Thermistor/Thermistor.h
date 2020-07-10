#ifndef Thermistor_h
#define Thermistor_h

#include <math.h>
#include "Arduino.h"

class Thermistor
{
  public:
    Thermistor(int analogPin);
    Thermistor(int analogPin, int defaultTemperatureType);
    void setDefaultTemperatureType(int defaultTemperatureType);
    double getTemperature();
    double getTemperatureInF();
    double getTemperatureInC();
    double getTemperatureInK();
    void setTemperatureToF();
    void setTemperatureToC();
    void setTemperatureToK();
  private:
    int _analogPin;
    int _defaultTemperatureType;
};

#endif
