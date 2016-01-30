int readPrevious = 0;
int readCurrent = 0;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
String echoStr;
readCurrent = analogRead(A0);

if(readCurrent != readPrevious){
  readPrevious = readCurrent;

  echoStr = " Current analog input : " + String(readCurrent);

  Serial.println(echoStr);

  delay(1000);
}
}
