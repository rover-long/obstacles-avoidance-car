#include <Servo.h>
Servo myservo;
#define IN1 13
#define IN2 7
#define IN3 6
#define IN4 12
#define echo 3
#define trig 4
float distance;
float duration;
float leftdistance,rightdistance;
float tempdistance;
void setup()
{ 
  pinMode(IN1,OUTPUT);
  pinMode(IN2,OUTPUT);
  pinMode(IN3,OUTPUT);
  pinMode(IN4,OUTPUT);
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);
  myservo.attach(5);
  Serial.begin(9600);
}

void loop()
{
  myservo.write(90);
  delay(500);
  distance = measure();
  Serial.println(distance);
  if (distance>15.0)
  {
    forward();
  }
  else if (distance<=15.0)
  {
    stopnow();
    delay(100);
    myservo.write(0);
    delay(500);
    rightdistance = measure();
    myservo.write(180);
    delay(500);
    leftdistance = measure();
    
    backward();
    delay(200);
    stopnow();
    delay(100);
    if(leftdistance>rightdistance)
    {
      turnleft();
      delay(500);
    }
    else
    {
      turnright();
      delay(500);
    }
  }
  delay(50); 
}

float measure()
{
  tempdistance=0;
  digitalWrite(trig,LOW);
  delayMicroseconds(2);
  digitalWrite(trig,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig,LOW);
  duration=pulseIn(echo,HIGH);
  tempdistance = duration*0.034/2;
  return tempdistance;
}

void forward() 
{
  digitalWrite(IN1, LOW);
  analogWrite(IN2, 150);  
  analogWrite(IN3, 150);
  digitalWrite(IN4, LOW);
}

void turnleft() {
  digitalWrite(IN1, LOW);
  analogWrite(IN2, 150);  
  analogWrite(IN3, 0);
  digitalWrite(IN4, LOW); 
}

void turnright() {
  digitalWrite(IN1, LOW);
  analogWrite(IN2, 0);
  analogWrite(IN3, 150);  
  digitalWrite(IN4, LOW);  
}
;
void stopnow() {
  digitalWrite(IN1, LOW);
  analogWrite(IN2, 0);
  analogWrite(IN3, 0);
  digitalWrite(IN4, LOW);
}
void backward(){
  digitalWrite(IN1, HIGH);
  analogWrite(IN2, 0);
  analogWrite(IN3, 0);
  digitalWrite(IN4, HIGH); 
}
