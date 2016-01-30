int ledOut=8;
int buttonIn=9;

void setup() {
  // put your setup code here, to run once:
  pinMode(ledOut, OUTPUT);
  pinMode(buttonIn,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int buttonState=digitalRead(buttonIn);
  digitalWrite(ledOut, buttonState);
  Serial.println(buttonState);
  delay(1000);
}
