#include <Arduino.h>
#include <Servo.h>
Servo myservo;

// khai báo biến
int trigpin=10;
int echopin=11;
int time,distance,pos=0;
// vận tóc của xung phát ra là 340m/s hay là 29.412 microSeconds/cm (106 / (340*100))
int speed=29.412;

void setup() {
  Serial.begin(9600);
  pinMode(trigpin,OUTPUT);
  pinMode(echopin,INPUT);
  myservo.attach(9);
}

// hàm để thùng rác mở ra
void open()
{
  for(pos = 0; pos < 90; pos += 1)  
  {                                   
    myservo.write(pos);              
    delay(15);                       
  } 
}
// hàm để đóng thùng rác lại 
void closer()
{
  for(pos = 90; pos>=1; pos-=1)     
  {                                
    myservo.write(pos);              
    delay(15);                       
  } 
}
void loop() {
  // phát xung
  digitalWrite(trigpin,0);
  delayMicroseconds(2);
  digitalWrite(trigpin,1);
  delayMicroseconds(10);
  digitalWrite(trigpin,0);
  //nhận xung
  time=pulseIn(echopin,1);
  // tính toán đưa về khoảng cách
  distance=int(time/2/speed);
  Serial.println(distance);
// điều kiện để hoạt động
  if (distance<=40)
  {
    open();
    delay(1000);
    closer();
  }
    /// xinh chào các bạns
    ///xin chào các bạn
} 