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

LiquidCrystal lcd(7, 6, 5, 4, 3, 2);
void setup(void){
    Serial.begin(9600);
    // set up the LCD's number of columns and rows: 
    lcd.begin(16, 2);
    // Print a message to the LCD.
    lcd.setCursor(0,0);
    lcd.print("Ready");
    delay(2000);
    // Start up the library
    sensors.begin(); // IC Default 9 bit. If you have troubles consider upping it 12. Ups the delay giving the IC more time to process the temperature measurement
}

void loop(void){
    lcd.setCursor(0,0);
    if( millis() > interval + t){
        sensors.requestTemperatures(); // Send the command to get temperatures    
        if(state == 0){
            Serial.print("Water = ");
            lcd.setCursor(0,1);
            Serial.println(sensors.getTempCByIndex(0));
            state = 1;
        }else{
            Serial.print("Air = ");
            lcd.setCursor(0,1);
            Serial.println(sensors.getTempCByIndex(1));
            state = 0;
        }
    //    lcd.print((char)223);
    //lcd.print("C"); 
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
