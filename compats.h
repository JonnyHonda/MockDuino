/*
 A mock header file containing functions and objects to mock in the arduino
*/

#include <stdlib.h>
/**
    Function to imitate millis
	@ return int
**/
int millis(){
	return (clock()/1000);
}

/**
 Mock object for OneWire
**/
class OneWire{
    public:
        OneWire( int pin);
};

OneWire::OneWire(int pin){
}

/**
 Mock object for Dallas
**/
#define SENSOR_COUNT 2
class DallasTemperature
{
    public:
        DallasTemperature(OneWire* _oneWire);
        void begin(void);
        void requestTemperatures(void);
        float getTempCByIndex(int);
    
        int sensor [SENSOR_COUNT]; 
};
 

DallasTemperature::DallasTemperature(OneWire* _oneWire){
}

void DallasTemperature::begin(void){
}

void DallasTemperature::requestTemperatures(void){
    for(int i; i < SENSOR_COUNT; i++){
        this->sensor[i] = rand() % 100 + 1;
        }

}

float DallasTemperature::getTempCByIndex(int index){
    return this->sensor[index] * 0.0625;
}



/*
    Mock object for Serial
*/
class Comms{
    public:
    void begin(int);
    void print(float);
    void print(const char*);
    void print(int);
    void println(float);
    void println(const char*);
    void println(int);        
};

// support functions for Comms object

void Comms::begin(int rate){
}

void Comms::print(int v){
    printf("%d",v);
}

void Comms::print(float v){
    printf("%f",v);
}

void Comms::print(const char* str){
    printf("%s",str);
}

void Comms::println(int v){
    printf("%d\n",v);
}

void Comms::println(float v){
    printf("%f\n",v);
}

void Comms::println(const char* str){
    printf("%s\n", str);
}

Comms Serial;


/*
    Mock object to simulate a CLD Display
*/
class LiquidCrystal{
    public:
        LiquidCrystal(int e, int r, int d1, int d2,  int d3, int d4);
        void begin(int, int);
        void setCursor(int, int);
        void print(float);
        void print(const char*);
        void print(int);
};

LiquidCrystal::LiquidCrystal(int e, int r, int d1, int d2, int d3, int d4){

}

void LiquidCrystal::begin(int c, int r){

}

void LiquidCrystal::setCursor(int c, int r){ 

}

void LiquidCrystal::print(float v){
    printf("%f", v);
}
void LiquidCrystal::print(const char* str){
    printf("%s", str);
}
void LiquidCrystal::print(int v){
    printf("%d", v);
}