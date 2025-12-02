#include <SparkFun_TB6612.h>

// Pin definitions
#define AIN1 2
#define BIN1 7
#define AIN2 4
#define BIN2 8
#define PWMA 5
#define PWMB 6
#define STBY 9

// Motor offsets
const int offsetA = 1;
const int offsetB = 1;

// Motor speeds
const int SPIN_SPEED = 150;
const int FORWARD_SPEED = 100;
const int BACKWARD_SPEED = 100;

// Timing constants (milliseconds)
unsigned long spinReading = 3000;
unsigned long forwardReading = 2000;
const unsigned long BACKWARD_DURATION = 800;
const unsigned long BRAKE_DELAY = 1000;
const unsigned long STARTUP_DELAY = 2000;

// Motor initialization
Motor motor1 = Motor(AIN1, AIN2, PWMA, offsetA, STBY);
Motor motor2 = Motor(BIN1, BIN2, PWMB, offsetB, STBY);

void setup() {
  // Nothing needed yet, but here for sensor initialization later
}

void loop() {
  delay(STARTUP_DELAY);  
  
   unsigned long startTime = millis();
   
   
   
   while (millis() - startTime < spinReading) {
    spin();    
    }
    brake(motor1, motor2);
    delay(BRAKE_DELAY);

   ;

   unsigned long forwardTime = millis();
   while (millis() - forwardTime < forwardReading) {
    moveForward();    
    }
    brake(motor1, motor2);
    delay(BRAKE_DELAY);

     unsigned long backwardTime = millis();
   while (millis() - backwardTime < BACKWARD_DURATION) {
    moveBack();      
    }
    brake(motor1, motor2);
    delay(BRAKE_DELAY); 
 
}

// Motor control functions
void spin() {
  forward(motor1, motor2, SPIN_SPEED);
}

void moveForward() {
  left(motor1, motor2, FORWARD_SPEED);
}

void moveBack() {
  right(motor1, motor2, BACKWARD_SPEED);
}
