void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
char ch;
char *pch;

ch = 'A';
pch = &ch;

// char 형 변수가 필요로 하는 메모리 크기
Serial.println("Size of character type : " + String(sizeof(ch)));
// char 포인터 형 변수가 필요로 하는 메모리 크기
Serial.println("Size of character pointer type : " + String(sizeof(pch)));

// char 형 변수에 저장되는 내용
Serial.println("Value of character type variable : " + String(ch));
// char 포인터 형 변수에 저장되는 내용 (메모리 주소가 저장됨)
Serial.println("Value of character pointer type : " + String((int)pch, HEX));

delay(3000);
}
