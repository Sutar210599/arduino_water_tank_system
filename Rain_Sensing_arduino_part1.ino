/* Flame Sensor analog example.
Code by Reichenstein7 (thejamerson.com)

For use with a Rain Sensor with an analog out!

To test view the output, point a serial monitor such as Putty at your Arduino. 

  - If the Sensor Board is completely soaked; "case 0" will be activated and " Flood " will be sent to the serial monitor.
  - If the Sensor Board has water droplets on it; "case 1" will be activated and " Rain Warning " will be sent to the serial monitor.
  - If the Sensor Board is dry; "case 2" will be activated and " Not Raining " will be sent to the serial monitor. 

*/
#include "Servo.h"

// lowest and highest sensor readings:
Servo servo_test;
const int sensorMin = 0;     // sensor minimum
const int sensorMax = 1024;// sensor maximum
int servoPin=3;
int angle ;

void setup() {
  // initialize serial communication @ 9600 baud:
  Serial.begin(9600);
  servo_test.attach(servoPin);  
}
void loop() {
  // read the sensor on analog A1:
	int sensorReading = analogRead(A1);
  // map the sensor range (four options):
  // ex: 'long int map(long int, long int, long int, long int, long int)'
	int range = map(sensorReading, sensorMin, sensorMax, 0, 3);
  
  // range value:
  switch (range) {
 case 0:    // Sensor getting wet
    Serial.println("Flood");
    servo_test.write(90);
    break;
 case 1:    // Sensor getting wet
    Serial.println("Rain Warning");
    //servo_test.write(0);
    break;
 case 2:    // Sensor dry - To shut this up delete the " Serial.println("Not Raining"); " below.
    Serial.println("Not Raining");
    servo_test.write(0);
    
    break;
  }
  delay(1);  // delay between reads
}
