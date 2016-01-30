void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
Serial.println("boolean : " + String(sizeof(boolean)));
Serial.println("char    : " + String(sizeof(char)));
Serial.println("byte    : " + String(sizeof(byte)));
Serial.println("int     : " + String(sizeof(int)));
Serial.println("float   : " + String(sizeof(float)));
Serial.println("double  : " + String(sizeof(double)));

delay(1000);
}
