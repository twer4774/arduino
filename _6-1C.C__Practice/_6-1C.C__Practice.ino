void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
Serial.print("Without 'New Line' character...");
Serial.println("With 'New Line' character");
Serial.println("See the difference...");

delay(1000);
}
