int ledOut = 8;
int buttonIn = 6;

void setup() {
  // put your setup code here, to run once:
  pinMode(ledOut, OUTPUT);
  pinMode(buttonIn, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
 int buttonState = digitalRead(buttonIn);
 if(buttonState == LOW){
  digitalWrite(ledOut, HIGH);}
 else{
  digitalWrite(ledOut, LOW);}
}
