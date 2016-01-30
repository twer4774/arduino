void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
float result;

result = sin(30.0*3.14/180.0);
print_result(result);
delay(1000);
}

//함수 호출 이전에 선언이나 정의가 없지만 
//스케치에서는 오류가 발생하지 않는다.
void print_result(float r)
{
  Serial.print("Value of Sine 30 : ");
  Serial.println(r);
}

