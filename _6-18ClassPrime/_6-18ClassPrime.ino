class NUM
{
  private:
  int no;

  public:
  //멤버함수 정의가 클래스 정의 내에 포함되어 있다.
  void set_number(int _no) {no=_no;}
  int get_number(void) {return no;}
  bool is_prime(void)
  {
    int i;

    for(i=2; i<no; i++){
      if(no%i==0) break;
    }
    if(i == no)
    return true;
    else
    return false;
  }
};
void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
NUM no[10];
int i;

for(i=0; i<10; i++){
  no[i].set_number(i+1); //멤버 함수 호출을 위한 도트 연산자
}

for(i=0; i<10; i++){
  if(no[i].is_prime()){
    Serial.println(String(no[i].get_number()) + " is a prime number.");
  }
  else{
    Serial.println(String(no[i].get_number()) + " is NOT a prime number.");
  }
}
delay(1000);
}

