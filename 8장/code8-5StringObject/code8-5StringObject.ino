
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  Serial.println("\n\nString Constructors:");
  Serial.println();
}

void loop() {
  // put your main code here, to run repeatedly:
  String stringOne = "Hello String";
  Serial.println(stringOne);

  stringOne = String('a');
  Serial.println(stringOne);

  String stringTwo = String("This is a string");
  Serial.println(stringTwo);

  stringOne = String(stringTwo + "with more");
  Serial.println(stringOne);

  stringOne = String(13);
  Serial.println(stringOne);

  stringOne = String(45, DEC);
  Serial.println(stringOne);

  stringOne = String(45, HEX);
  Serial.println(stringOne);

  stringOne = String(255, BIN);
  Serial.println(stringOne);

  stringOne = String(millis(), DEC);
  Serial.println(stringOne);

  while(true);
}
