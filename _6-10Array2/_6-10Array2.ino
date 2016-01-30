void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int no[2][4];

  //배열 변수가 저장된 메모리 번지
  for(int i = 0; i<2; i++){
    for(int j = 0; j<4; j++){
      no[i][j] = 1*4+j;
    }
  }
  //2차원 배열의 요소를 읽어오는 여러 가지 방법
  for(int i = 0; i<2; i++){
    for(int j = 0; j<4; j++){
      Serial.println("Address of B[" + String(i) + "][" + String(j) + "] : "
        + String(int(&no[i][j])));
      Serial.println("Value of B[" + String(i) + "][" + String(j) + "] :"
        + String(no[i][j]));
      Serial.println("Value of B[" + String(i) + "][" + String(j) + "] :"
        + String(*((int*)no + i *4+j)));
      
    }
  }
  delay(1000);
}

