
#include "SparkFunCCS811.h"
#include "I2CMux.h"

#include <Wire.h>

#define I2CMux_ADDR 0x70 
#define CCS811_ADDR 0x5A 

I2CMux mux(I2CMux_ADDR);

CCS811 sensor(CCS811_ADDR), sensor1(CCS811_ADDR);
CCS811 sensors[2]={sensor, sensor1};


void setup(){

    Serial.begin(9600);
    Wire.begin();
    
      mux.switchToBus(1);
     sensors[1].begin();

      mux.switchToBus(0);
      sensors[0].begin();


    delay(1000);
}



void loop(){

    mux.switchToBus(1);
  if (sensors[1].dataAvailable())
  {
    //If so, have the sensor read and calculate the results.
    //Get them later
    sensors[1].readAlgorithmResults();
    Serial.print("Sensor1");
    Serial.print("CO2[");
    //Returns calculated CO2 reading
    Serial.print(sensors[1].getCO2());
    Serial.print("] tVOC[");
    //Returns calculated TVOC reading
    Serial.print(sensors[1].getTVOC());
    Serial.print("] millis[");
    //Simply the time since program start
    Serial.print(millis());
    Serial.print("]");
    Serial.println();
    delay(500);
  }



     mux.switchToBus(0);
  if (sensors[0].dataAvailable())
  {
    //If so, have the sensor read and calculate the results.
    //Get them later
    sensors[0].readAlgorithmResults();
    Serial.print("Sensor2");
    Serial.print("CO2[");
    //Returns calculated CO2 reading
    Serial.print(sensors[0].getCO2());
    Serial.print("] tVOC[");
    //Returns calculated TVOC reading
    Serial.print(sensors[0].getTVOC());
    Serial.print("] millis[");
    //Simply the time since program start
    Serial.print(millis());
    Serial.print("]");
    Serial.println();
    Serial.println();
    delay(500);
  }


  
  delay(5000);
    
  
}
