void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
int a = 10, b = 3; //정수형 변수
float fa = 10.0, fb = 3.0; //실수형 변수

Serial.println("a%b=" + String(a%b)); //나머지

//문자열 "a//b = "와 정숫값이 문자열로 변환된 String(a/b)로
//새로운 문자열을 생성하여 한 번에 출력한다.
Serial.println("a/b=" + String(a/b)); //정수 나눗셈

//String 클래세는 실숫값을 문자열로 변환하는 기능이 없으므로
//문자열 "fa/fb="을 먼저 출력하고
//실수는 별도로 Serial 클래스의 println 함수로 출력한다.
Serial.print("fa/bf=");
Serial.println(fa/fb); //실수나눗셈

delay(1000);
}
