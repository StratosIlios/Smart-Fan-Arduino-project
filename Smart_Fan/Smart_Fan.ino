/*The Motor works if and only if the Ultrasonic Sensor is not blocked form any obstacle in distance less than 20cm.
When the Sensor is blocked, it scans the area in 156 degrees (Not in 180 degrees because the Servo motor is burdened) 
and tries to find the proper place, the space which is free from obstacles 
and then the Motor starts again. When the Motor works the GREEN light is ΟΝ. 
When the Motor stops the RED ligth is ΟΝ*/

#include "SR04.h"
#include <Servo.h>
#define TRIG_PIN 12 // Sensor variable
#define ECHO_PIN 11 // Sensor variable
#define ENABLE 5  // Motor variable
#define INPUT_1 4 // Motor variable
#define INPUT_2 3 // Motor variable
#define RED 6 // Red light
#define GREEN 7 //Green light

SR04 sr04 = SR04(ECHO_PIN,TRIG_PIN); // object that counts the Obstacle Distance from Sensor
long DistanceObstacle; // Distance variable
int i=15;// Minimum angle of Servo Motor
int j=0; 
Servo myservo; // Object of Servo Motor

/*Function that activates and deactivates the motor according to the Obstacle distance*/
int StopMotor(int DistanceObst){
   if(DistanceObst>=20){
     digitalWrite(INPUT_2,HIGH);
     analogWrite(INPUT_2,150);
     digitalWrite(GREEN,HIGH);  
     digitalWrite(RED,LOW); 
    }
   else{
    digitalWrite(INPUT_2,LOW); 
    digitalWrite(GREEN,LOW);  
    digitalWrite(RED,HIGH); 
    }
   Serial.print(DistanceObst);
   Serial.println("cm");
}

/*Function that moves the Servo position COUNTERCLOCKWISE when the Obstacle Distance is too small*/
void ServoPosition(){
  while(i<=170){ 
    myservo.write(i);// Servo Motor moves COUNTERCLOCKWISE from Min angle(15) to Max angle(171) according to the obstacles distances.   
    i++;    
    DistanceObstacle=sr04.Distance();
    if(DistanceObstacle>20){break;}    
    //Serial.println(i);  
  }  
  
/*Try to reverse the Servo*/  
  if(i=171){
    while(i>=15){
     myservo.write(i);// Servo Motor moves CLOCKWISE from Max angle(171) to Min angle(15) according to the obstacles distances.     
     i--;    
     DistanceObstacle=sr04.Distance();
     if(DistanceObstacle>20){break;} 
     //Serial.println(i);
    }
   }
//  Serial.println(i);
}
 
void setup() {
  myservo.write(i);// Gives a value to Servo
  myservo.attach(9);// Attaches the Servo to Pin 9
  pinMode(RED,OUTPUT);
  pinMode(GREEN,OUTPUT);
  pinMode(ENABLE,OUTPUT);
  pinMode(INPUT_1,OUTPUT);
  pinMode(INPUT_2,OUTPUT);
  digitalWrite(ENABLE,HIGH);
  digitalWrite(INPUT_2,HIGH);// If the INPUT_2 is HIGH and the INPUT_1 is LOW the motor moves CLOCKWISE 
  digitalWrite(INPUT_1,LOW);// If the INPUT_1 is HIGH and the INPUT_2 is LOW the motor moves ANTICLOCKWISE
  Serial.begin(9600); 
}

void loop() {    
  DistanceObstacle=sr04.Distance();
  delay(800);
  StopMotor(DistanceObstacle); // Calls the Function StopMotor 
  if(DistanceObstacle<=20){
    ServoPosition(); // Calls the Function ServoPosition
  }
}
   
