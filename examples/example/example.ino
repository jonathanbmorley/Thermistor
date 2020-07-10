#include <Thermistor.h>

// In this example, my thermistor is attached to analog pin A0.
Thermistor thermistor = Thermistor(A0);

void setup() {
  // Open a serial port connection for the thermistor output.
 Serial.begin(9600);

}

void loop() {
  double temperatureReading = thermistor.getTemperature();
  Serial.print("The (Default) temperature reading is ");
  Serial.print(temperatureReading);
  Serial.println(" degrees");
  
  delay(1000);
  
  Serial.println("Now, I'll ask for a Fahrenheit reading using the getTemperatureInF() method...");
  temperatureReading = thermistor.getTemperatureInF();
  Serial.print("The (Fahrenheit) temperature is ");
  Serial.print(temperatureReading);
  Serial.println(" F");

  delay(1000);

  Serial.println("Now, I'll ask for a Celcius reading using the getTemperatureInC() method...");
  temperatureReading = thermistor.getTemperatureInC();
  Serial.print("The (Celcius) temperature is ");
  Serial.print(temperatureReading);
  Serial.println(" C");

  delay(1000);
  
  Serial.println("Now, I'll ask for a Kevlin reading using the getTemperatureInK() method...");
  temperatureReading = thermistor.getTemperatureInK();
  Serial.print("The (Kelvin) temperature is ");
  Serial.print(temperatureReading);
  Serial.println(" K");  
  
  delay(1000);

  Serial.println("Now, I'll change the default temperature to Celcius (which is #1)...");
  thermistor.setDefaultTemperatureType(1);

  Serial.println("And ask for a new temperature reading using the getTemperature() method...");
  temperatureReading = thermistor.getTemperature();
  Serial.print("The (Celcius, new default) temperature is ");
  Serial.println(temperatureReading);

  Serial.println("Now I'll wait 10 seconds and do it all over again!");
  Serial.println("--------------------------------------------------");
  delay(10000);
}
