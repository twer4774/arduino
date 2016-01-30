void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
int A = 0;
static int B = 0;

A = A + 1;
B = B + 1;

Serial.println("A = " + String(A));
Serial.println("B = " + String(B));

delay(1000);
}
