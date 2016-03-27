int soil = A0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int value = analogRead(soil);
   Serial.print("read sensor value: ");
   Serial.println(value);

   delay(1000);
}
