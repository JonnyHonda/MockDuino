MockDuino is a unit test model for the Adruino
Theoretically you should be able to write a Arduino C++ file
add the changes for included MockDuino and it should compile

Mockduino will become a collection of mock objects the simulate
the inputs and outputs for the arduino.

For example Serial.print will print to the console (as will lcd.print)
Mocking things like the DS18B20 will consist of creating a mock class
and writing dummy function in the class to ramp temperature for example

lots todo. 

Compile the example using:
gcc -oBikeTemp BikeTemp.cpp
