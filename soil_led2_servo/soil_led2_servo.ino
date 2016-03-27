#include <Servo.h>
int angle = 90;
int soil = A1;
Servo myservo;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(8, OUTPUT);
  pinMode(12, OUTPUT);
  myservo.attach(2);
}

void loop() {
  // put your main code here, to run repeatedly:
  int value = analogRead(A0);
  int sValue = analogRead(A1);
  Serial.println(value);
  Serial.println(sValue);
  if(value > 500){
    digitalWrite(8, 1);
  } //else{
    //digitalWrite(8, 0);
  //}

  if(value > 700){
    digitalWrite(12, 1);
  }// else{
//    digitalWrite(12, 0);
//  }
  if(Serial.available()){
    int swt = (int)Serial.read();
    if(swt == 49){
    digitalWrite(8, 1);
    }else if(swt == 48){
    digitalWrite(8, 0);
    }else if(swt == 50){
      digitalWrite(12, 1);
    }
    else if(swt == 51){
      digitalWrite(12, 0);
    }
    else if(swt == 60){
      myservo.write(90);
    }
    else if(swt == 61){
      myservo.write(0);
    }
   }

  delay(1000);
}
