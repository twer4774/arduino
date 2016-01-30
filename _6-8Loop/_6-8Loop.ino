void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
int count, sum;

//do-while문 사용
sum = 0; count = 0;
do{
  count++;
  sum += count;
}while(count < 10);
Serial.println("do-while : " + String(sum));

//while문 사용
 sum = 0; count = 0;
 while(count < 10){
  count++;
  sum += count;
 }
 Serial.println("while :" + String(sum));

 //for문 사용
for(count = 1, sum = 0; count <= 10; count++){
  sum += count;
}
Serial.println("for   : " + String(sum));

delay(1000);
}

