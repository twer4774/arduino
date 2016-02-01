int ledPin = 8; //LED연결 핀
String inputString; //시리얼 통신을 통한 입력 문자열
boolean ledOnOff = false; //LED 초기값은 꺼진 상태

void setup() {
  Serial.begin(9600); //시리얼 포트 초기화
  pinMode(ledPin, OUTPUT); // LED 연결 포트 출력으로 설정
 
}

void loop(){
  if(ledOnOff){
    digitalWrite(ledPin, HIGH);
  }
  else{
    digitalWrite(ledPin, LOW);
  }
}

void serialEvent(){
  while( Serial.available()){
    char inChar = (char)Serial.read();
    if (inChar == '\n' || inChar =='\r'){
      if(inputString.equals("on")){
        ledOnOff = true;
        Serial.println("LED On!");
        inputString = "";
      }
      else if(inputString.equals("off")){
        ledOnOff = false;
        Serial.println("LED Off!");
        inputString = "";
      }
    }
    else
      inputString += inChar;
  }
}

