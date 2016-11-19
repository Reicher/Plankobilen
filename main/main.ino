/*
 Plankobilen 2.0 Arduino
 Robin Reicher

 Goals: 
 1. Speed and turn left/rigt controls from wifi connection
 2. From a phone
 3. Autonomos?  
 
 */

#include <Servo.h>


// Motor
int motorPin = 8;    // LED connected to digital pin 9
int throttle = 0;    // variable to store the motor speed 0-255

//Servo
Servo servo;  // create servo object to control a servo
int servoPin = 9;    // LED connected to digital pin 10
int pos = 0;    // variable to store the servo position

//Misc
int warningLed = 13;

void setup() {
  Serial.begin(9600);
  while (! Serial);
  Serial.println("Plankobilen 2.0 Arduino");
  
  servo.attach(servoPin);  // attaches the servo on pin 9 to the servo object
  pinMode(motorPin, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);
}


void stop(){
      servo.write(0);  
      analogWrite(motorPin, 0);
}

// Safety first! 
void blinkWarning() {
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);                       // wait for a second
}

void testServo()
{  
  if (Serial.available())
  {
    int angle = Serial.parseInt();
    servo.write(angle);  
  }
}

void testEngine()
{  
  Serial.println("TestEngine");
  if (Serial.available())
  {
    int speed = Serial.parseInt();
    if (speed >= 0 && speed <= 255)
    {
      analogWrite(motorPin, speed);
    }
  }
}

void loop() {
  blinkWarning();
  
  stop();  

  //testServo();
  //testEngine(); 
}


