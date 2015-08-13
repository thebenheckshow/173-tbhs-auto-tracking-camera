/* 
This is a test sketch for the Adafruit assembled Motor Shield for Arduino v2
It won't work with v1.x motor shields! Only for the v2's with built in PWM
control

For use with the Adafruit Motor Shield v2 
---->	http://www.adafruit.com/products/1438
*/


#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "utility/Adafruit_PWMServoDriver.h"

// Create the motor shield object with the default I2C address
Adafruit_MotorShield AFMS = Adafruit_MotorShield(); 
// Or, create it with a different I2C address (say for stacking)
// Adafruit_MotorShield AFMS = Adafruit_MotorShield(0x61); 

// Connect a stepper motor with 200 steps per revolution (1.8 degree)
// to motor port #2 (M3 and M4)https://github.com/ladyada/Adafruit_Motor_Shield_V2_Library/archive/master.zip
Adafruit_StepperMotor *motor_01 = AFMS.getStepper(200, 1);
Adafruit_StepperMotor *motor_02 = AFMS.getStepper(200, 2);


void setup() {
  
  Serial.begin(9600);           // set up Serial library at 9600 bps
  Serial.println("Stepper test!/n");

  AFMS.begin(12000);  // create with the default frequency 1.6KHz
  //AFMS.begin(12000);  // create with the default frequency 1.6KHz
  //AFMS.begin(1000);  // OR with a different frequency, say 1KHz
  
  //motor_01->setSpeed(12000);  //  rpm   
  //motor_02->setSpeed(12000);  //  rpm
}

void loop() {
  //Adafruit_StepperMotor *getStepper(uint16_t steps, uint8_t n);
  
  motor_01->step(100, FORWARD, SINGLE);
  motor_01->release(); // removes all power from the motor. 

  motor_02->step(100, FORWARD, SINGLE);
  motor_02->release(); // removes all power from the motor. 

  while(1) {
    delay(1);  
  }


  //motor_02->step(200, FORWARD, SINGLE);
  //motor_02->step(200, FORWARD, DOUBLE);
  //motor_02->step(400, FORWARD, INTERLEAVE);
  //motor_02->step(200, FORWARD, MICROSTEP);

  //motor_02->step(200, BACKWARD, SINGLE);
  //motor_02->step(200, FORWARD, DOUBLE);
  //motor_02->step(400, BACKWARD, INTERLEAVE);
  //motor_02->step(200, BACKWARD, DOUBLE);
  //motor_02->step(200, BACKWARD, MICROSTEP);
  //motor_02->release(); // removes all power from the motor. 
  
}
