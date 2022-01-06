 
#include <Servo.h>
#define trigPin 3  //Servo trig pin to D10
#define echoPin 2 // Servo echo pin to D11
#define in1 7 // Motor driver pin
#define in2 8 
#define in3 9
#define in4 10
#define enA 5
#define enB 6
#define motorArpm 100 // Default speed for "enA". you can change this speed from 0 to 300
#define motorBrpm 100 // Default speed for "enB". you can change this speed from 0 to 300

Servo servo_motor; //Servo
int pos =0;

void setup(){
  Serial.begin(9600);
servo_motor.attach(11); //Servo signal pin to D8

for(pos = 90; pos <= 160; pos += 1){
servo_motor.write(pos);
delay(15);
}
 
for(pos = 160; pos >= 0; pos-= 1) {
servo_motor.write(pos);
delay(15);
}

for(pos = 0; pos<=90; pos += 1) {
servo_motor.write(pos);
delay(15);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode (in1, OUTPUT);
  pinMode (in2, OUTPUT);
  pinMode (in3, OUTPUT);
  pinMode (in4, OUTPUT);
  pinMode (enA, OUTPUT);
  pinMode (enB, OUTPUT);
}
}
long duration;
int distance;

void loop(){
  digitalWrite(trigPin , HIGH);
  delayMicroseconds(1000);
  digitalWrite(trigPin , LOW);

  duration = pulseIn(echoPin , HIGH);
  distance = (duration/2) / 28.5;

  if(distance < 5) // It will go Backward if distance is less than 5.
  {
    digitalWrite(in1,  LOW);
    digitalWrite(in2, HIGH);
    analogWrite(enA, motorArpm);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
    analogWrite(enB, motorBrpm);
  }
  if(distance >40) // It will Stop if distance is More than 40.
  {
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, LOW);
    analogWrite(enA, 0);
    analogWrite(enB, 0);
  }

  if(distance > 10 && distance < 20){ // to turn Forward
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    analogWrite(enA, motorArpm);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
    analogWrite(enB, motorBrpm);
  }
  
  if(distance > 20 && distance < 30)//// to turn left
  {
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    analogWrite(enA, 80);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
    analogWrite(enB, 80);
  }

  if(distance > 30 && distance <40 ) //// to turn Right
  {
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    analogWrite(enA, 80);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
    analogWrite(enB, 80);
  }
  }
