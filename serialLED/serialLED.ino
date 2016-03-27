void setup(){
  Serial.begin(9600);
  pinMode(8,OUTPUT);
}
//49 입력시 led on, 48입력시 off
void loop(){
  if(Serial.available())
  {
    int swt = (int)Serial.read();
    if(swt == 49)
     digitalWrite(8, 1);
    else
     digitalWrite(8, 0);
  }
}

