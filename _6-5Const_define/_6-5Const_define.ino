#define CONST1 5 //상수 정의(단순히 CONST1을 5로 대체)
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
const int CONST2 = 10; //상수 변수. 이후 값을 변경할 수 없는 변수

Serial.println("Constant 1 by #define : " + String(CONST1));
Serial.println("Constanat 2 by const keyword : " + String(CONST2));

//아래 주석 제거시 에러발생 둘다 상수로 정의되었으므로!
//CONST1=CONST1+1;
//CONST2=CONST2+1;

delay(1000);
}
