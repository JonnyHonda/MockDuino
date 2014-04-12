/*
 A mock header file containing functions and objects to mock in the arduino
*/

#include <stdlib.h>
 #include <unistd.h>
 #include <string.h>
/**
    Function to imitate millis
	@ return int
    the divisor will need altering depending ont the speed of your machine
**/

#define DS18B20_MAX = 2000;
#define DS18B20_MIN = -400;
int millis(){
	return (clock()/1000);
}

void delay(int t){
    usleep(t);
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
        void rampingUp(int, int);
    
        int sensor [SENSOR_COUNT]; 
};
 

DallasTemperature::DallasTemperature(OneWire* _oneWire){
    sensor[0] = 100;
    sensor[1] = 100;
}

void DallasTemperature::begin(void){
}

void DallasTemperature::requestTemperatures(void){
   this->sensor[0] += 10;
   // this->rampingUp(0, 10);
   // this->sensor[1] = 100;

    /*for(int i; i < SENSOR_COUNT; i++){
        this->sensor[i] = rand() % 100 + 1;
        }
        */
}

float DallasTemperature::getTempCByIndex(int index){
    return this->sensor[index] * 0.0625;
}

void DallasTemperature::rampingUp(int i, int rate){
    this->sensor[i] += rate;
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
    fflush(stdout);
}

void Comms::print(float v){
    printf("%f",v);
    fflush(stdout);
}

void Comms::print(const char* str){
    printf("%s",str);
    fflush(stdout);
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
    Mock object to simulate a LCD Display
*/
class LiquidCrystal{
    public:
        LiquidCrystal(int e, int r, int d1, int d2,  int d3, int d4);
        void begin(int, int);
        void setCursor(int, int);
        void print(float);
        void print(const char*);
        void print(int);
        void printDisplay(void);
        int rows;
        int columns;
        int cursorPosX;
        int cursorPosY;
        // 
        char leftColumn[8];
        char rightColumn[8];
        char display[17];
};

LiquidCrystal::LiquidCrystal(int e, int r, int d1, int d2, int d3, int d4){
    this->cursorPosX = 0;
    this->cursorPosY = 0;
}

void LiquidCrystal::begin(int c, int r){
    this->rows = r;
    this->columns = c;
}

void LiquidCrystal::setCursor(int c, int r){ 
    this->cursorPosX = c;
    this->cursorPosY = r;
}

void LiquidCrystal::print(float v){
    char tempStr[17];
    sprintf(tempStr,"%f", v);
    if (this->cursorPosY == 0){
        this->leftColumn[this->cursorPosY] = '\0';
        strcat(this->leftColumn, tempStr);
    }else{
        this->rightColumn[this->cursorPosY] = '\0';
        strcat(this->rightColumn, tempStr);
    }
    //this->printDisplay();

 //   fflush(stdout);
}

void LiquidCrystal::print(const char* str){
    // MMmm
    // Display is only 16 chars, need to truncate at cursor and con cat new string
    if (this->cursorPosY == 0){
        this->leftColumn[this->cursorPosY] = '\0';
        strcat(this->leftColumn, str);

    }else{
        this->rightColumn[this->cursorPosY] = '\0';
        strcat(this->rightColumn, str);
    }   
    this->printDisplay();
}

void LiquidCrystal::printDisplay(void){
    strcpy(this->display, this->leftColumn);
    strcat(this->display, this->rightColumn);
    if(strlen(this->display) > 16){
        this->display[17] = '\0';
        this->cursorPosX = 16;    
    }else{
        this->cursorPosX = strlen(this->display);
    }
    
    printf("%s\n", this->display);
}

void LiquidCrystal::print(int v){
   // printf("%d", v);
    //fflush(stdout);
}