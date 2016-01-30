int ledOut = 8;
int buttonIn = 6;

void setup() {
  // put your setup code here, to run once:
  pinMode(ledOut, OUTPUT); //LED핀 출력으로 설정
  pinMode(buttonIn, INPUT); //버튼 핀 입력으로 설정
}
 
void loop() {
  // put your main code here, to run repeatedly:
  
  int buttonState= digitalRead(buttonIn); //버튼 상태 읽기
  digitalWrite(ledOut, buttonState); //버튼 상태에 따라 LED on/off
}
