void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
}

boolean is_prime(int no)
{
  int i;
  for(i=2; i<no; i++){
    if(no%i==0)break;
  }

  if(i == no)
  return true;
  else
  return false;
}
void loop() {
  // put your main code here, to run repeatedly:
int no[10], i;

for(i=0;i<10;i++){
  no[i]=i+i;
}

for(i=0; i<10; i++){
  if(is_prime(no[i])){
    Serial.println(String(no[i]) + "is a prime number.");
  }
  else{
    Serial.println(String(no[i]) + "is NOT aa priem number.");
  }
}
delay(1000);
}
