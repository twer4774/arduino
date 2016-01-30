#include <Servo.h> 

int servoPin = 9;
int trigPin = 13;
int echoPin = 12;

Servo servo;

int angle = 0;
void setup() {
  // put your setup code here, to run once:
   Serial.begin(9600); //시리얼 초기화
  servo.attach(servoPin); //서보모터 핀 설정
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  float duration, distance;
  digitalWrite(trigPin, HIGH);
  delay(1000);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = ((float)(340 * duration) / 10000) / 2;

  Serial.print("Distance:");
  Serial.println(distance);
  delay(1000);

  if( distance < 3){
    for(angle=0; angle<180; angle++)
    {
      servo.write(angle);
      delay(15);
    }
    for(angle=180; angle>0; angle--)
    {
    servo.write(angle);
    delay(15);
    }
  }
}
