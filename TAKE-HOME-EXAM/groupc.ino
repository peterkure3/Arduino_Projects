#include <Servo.h>

Servo servo1;
Servo servo2;

int TriggerPIN1 = 9;
int EchoPIN1 = 10;
int TriggerPIN2 = 5;
int EchoPIN2 = 4;

void setup(){
  servo1.attach(6);
  servo2.attach(7);
  pinMode(TriggerPIN1,OUTPUT);
  pinMode(EchoPIN2,INPUT);
  pinMode(TriggerPIN2,OUTPUT);
  pinMode(EchoPIN2,INPUT);
  Serial.begin(9600); 
  }

void loop(){  
  digitalWrite(TriggerPIN1,LOW);
  delayMicroseconds(2);
  digitalWrite(TriggerPIN1,HIGH);
  delayMicroseconds(2);
  digitalWrite(TriggerPIN1,LOW);

  long timedelay = pulseIn(EchoPIN1,HIGH);
  int distance1 = 0.0343 * (timedelay/2);

  Serial.print("Sensor 1 : ");
  Serial.println(distance1);

  delayMicroseconds(2);

  digitalWrite(TriggerPIN2,LOW);
  delayMicroseconds(2);
  digitalWrite(TriggerPIN2,HIGH);
  delayMicroseconds(2);
  digitalWrite(TriggerPIN2,LOW);

  long td = pulseIn(EchoPIN2,HIGH);
  int distance2 = 0.0343 * (td/2);

  Serial.print("Sensor 2 : ");
  Serial.println(distance2);

  if(distance2 > 4 && distance1 > 4){
   servo1.write(30);  //makes the rover turn leftwards
   servo2.write(30);
   delay(400);
    }
  else if (distance2 < 4 && distance1 > 4){
    servo1.write(0); //makes the rover move in a continuous straight line
    servo2.write(180);
    }
//  else if(distance2 < 4 && distance1 < 4){
//   servo1.write(360);  //makes the rover turn rightwards
//   servo2.write(360);
//   delay(1500);
//    }
  }









  