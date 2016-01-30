void setup() {
  // put your setup code here, to run once:
 Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
int A = 1;
int B[5] = {11, 12, 13, 14, 15};

//일반 변수가 저장된 메모리 번지
Serial.println("Address of A : " + String(int(&A), HEX));

//배열 변수가 저장된 메모리 번지
for(int i = 0; i<5; i++){
  Serial.println("Address of B[" + String(i) + "] : " + String(int(&B[i]), HEX));
}
delay(1000);
}
