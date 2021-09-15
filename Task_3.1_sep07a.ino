#include "arduino_secrets.h"
/* 
  Sketch generated by the Arduino IoT Cloud Thing "Task 3.1"
  https://create.arduino.cc/cloud/things/3c53bce8-ebc8-476a-89e8-a1024046e343 

  Arduino IoT Cloud Variables description

  The following variables are automatically generated and updated when changes are made to the Thing

  float temperature;
  float humidity;

  Variables which are marked as READ/WRITE in the Cloud Thing will also have functions
  which are called when their values are changed from the Dashboard.
  These functions are generated with the Thing and added at the end of this sketch.
*/

#include "thingProperties.h"
#include "DHT.h"

#define DHTPIN 4
#define DHTTYPE DHT22

 DHT dht(DHTPIN, DHTTYPE);

void setup() {
  // Initialize serial and wait for port to open:
  Serial.begin(9600);
  // This delay gives the chance to wait for a Serial Monitor without blocking if none is found
  delay(1500); 
  
 dht.begin();  

  // Defined in thingProperties.h
  initProperties();

  // Connect to Arduino IoT Cloud
  ArduinoCloud.begin(ArduinoIoTPreferredConnection);
  
  /*
     The following function allows you to obtain more information
     related to the state of network and IoT Cloud connection and errors
     the higher number the more granular information you’ll get.
     The default is 0 (only errors).
     Maximum is 4
 */
  setDebugMessageLevel(2);
  ArduinoCloud.printDebugInfo();
}

void loop() {
  ArduinoCloud.update();
  
  temperature = dht.readTemperature();
  humidity = dht.readHumidity();
  
  Serial.print("Temperature: ");
  Serial.print(temperature);
  
  Serial.print(" Humidity : ");
  Serial.print(humidity);
  
  delay (30000);
}










