void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void function1(int a[10])
{//매개변수가 배열 형태인 경우
  a[5] = 0;
}

void function2(int *a)
{//매개변수가 포인터 형태인 경우
  a[6] = 0;
}
void print_value(int *a)
{
  int i;
  for(i=0; i<10; i++)
  Serial.print(String(a[i])+"");
  Serial.println();
}
void loop() {
  // put your main code here, to run repeatedly:
  int a[10];
  int i;

  for(i=0;i<10;i++){
    a[i]=i;
  }
  print_value(a);
  function1(a); //배열 이름과 포인터는 동일하므로 function2와 차이는 없다.
  print_value(a); //함수 내에서 변경한 값이 반영된다.
  function2(a);
  print_value(a); //함수 내에서 변경한 값이 반영된다.

  delay(1000);
}
