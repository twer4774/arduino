int pin = 8;
void setup(){
  Serial.begin(9600);
  pinMode(pin,OUTPUT);
}
//49 입력시 led on, 48입력시 off
void loop(){
  if(Serial.available())
  {
    int swt = (int)Serial.read();
    if(swt == 49)
     digitalWrite(pin, 1);
    else
     digitalWrite(pin, 0);
  }
}

