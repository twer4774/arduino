#include <Servo.h>

int angle = 90;
Servo myservo;

void setup(){
  Serial.begin(9600);
  myservo.attach(9);
}

void loop(){
  byte recvAngle;

  if(Serial.available()){
    recvAngle = Serial.read();
    if(recvAngle == 5) { //받은 각도값이 5일때
      angle = angle + recvAngle;
      myservo.write(angle); //현재 각도값에서 +5도로 이동
    }
    else if(recvAngle == 10){ //받은 각도값이 10일때
      angle = angle +o recvAngle;
      myservo.write(angle); //현재 각도값에서 -10도로 이동
   
    }
  }
}

