#include <stdio.h>
#include <time.h> 

#define COMPAT true
#ifdef COMPAT
    #include "compats.h"
#else
    #include <OneWire.h>
    #include <DallasTemperature.h>
    #include <LiquidCrystal.h>
#endif

// Data wire is plugged into pin 2 on the Arduino
#define ONE_WIRE_BUS 10

// Setup a oneWire instance to communicate with any OneWire devices (not just Maxim/Dallas temperature ICs)
OneWire oneWire(ONE_WIRE_BUS);

// Pass our oneWire reference to Dallas Temperature. 
DallasTemperature sensors(&oneWire);

int state = 0;
int interval = 5000;
int t = 0;

void setup(void){
    Serial.begin(9600);
}

void loop(void){
sensors.requestTemperatures(); // Send the command to get temperatures
    if( millis() > interval + t){
        if(state == 0){
            Serial.print("Water Temperature = ");
            //printf("%d",sensors.getTempCByIndex(0));
            Serial.println(sensors.getTempCByIndex(0));
            state = 1;
        }else{
            Serial.print("Air Temperature = ");
            Serial.println(sensors.getTempCByIndex(1));
            state = 0;
        }
        t = millis();
    }
}


int main() {
    setup();
        while (1){
            loop();
        }
    return 0;
}
