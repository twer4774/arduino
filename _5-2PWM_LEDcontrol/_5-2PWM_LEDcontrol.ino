//PWM을 통한 LED밝기제어
int LED_pin=3; //LED연결핀
void setup() {
  // put your setup code here, to run once:
 pinMode(LED_pin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
 int i;

 for(i=0; i<256; i++){
  analogWrite(LED_pin, i); //0~255로 서서히 변화
  delay(10);
 }
}
