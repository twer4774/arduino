void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(8, OUTPUT);
  pinMode(12, OUTPUT);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  int value = analogRead(A0);
  Serial.println(value);
  if(value > 500){
    digitalWrite(8, 1);
  } else{
    digitalWrite(8, 0);
  }

  if(value > 700){
    digitalWrite(12, 1);
  } else{
    digitalWrite(12, 0);
  }
  if(Serial.available()){
    int swt = (int)Serial.read();
    if(swt == 49){
    digitalWrite(8, 1);
    }else if(swt == 48){
    digitalWrite(8, 0);
    }else if(swt == 50){
      digitalWrite(12, 1);
    }
    else {
      digitalWrite(12, 0);
    }
   }
 
  delay(1000);
}
