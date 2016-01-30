void setup() {
  // put your setup code here, to run once:
 Serial.begin(9600);
}
void function1(int a)
{//a는 지역변수로 함수가 끝나면 사라진다.
  a = 0;
}

void function2(int *pa)
{//pa라는 지역변수지만 
  //메모리에 직접 값을 기록하므로 함수가 끝나도 사라지지 않는다.
  *pa = 0;
}
void loop() {
  // put your main code here, to run repeatedly:
  int a = 3;
  Serial.println(a);

  function1(a);
  Serial.println(a);
  function2(&a);
  Serial.println(a);

  delay(1000);
}
