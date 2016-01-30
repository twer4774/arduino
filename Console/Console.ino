#include <Console.h>

const int ledPin=13;
int incomingByte;

void setup() {
  // put your setup code here, to run once:
  Bridge.begin();
  Console.begin();

  while(!Console){
    ;
  }
  Console.println("You're connected to the Console!!");
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
if(Console.available() >0){
  incomingByte=Console.read();
  if(incomingByte=='H'){
    digitalWrite(ledPin, HIGH);
  }
  if(incomingByte=='L'){
    digitalWrite(ledPin, LOW);
  }
}
delay(100);
}
