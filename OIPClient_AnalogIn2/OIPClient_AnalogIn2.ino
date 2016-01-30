/*

   examples:  OIPClient_AnalogIn

   3mp연동을 위한 아두이노 클라이언트 라이브러리 테스트 예제

   1st update : 2015.7.14
   2nd update : 2015.7.26
   3rd update : 2015.8.21
   4th update : 2015.9.14	EC 서버 IP 주소 변경

*/
#include <avr/pgmspace.h>
#include <SPI.h>
#include <Ethernet.h>
#include "OIPClient.h"

#define SDCARD_CS 4

// 네트워크 설정 정보
byte mac[] = {0xDA, 0xAA, 0xBE, 0xEF, 0xFE, 0x44};
byte server[] = { 220, 90, 216, 90}; // 3MP TCP server ip
unsigned int port = 10020; // 3mp TCP server port

// 3mp 연동 설정 정보(디바이스명:  DYtempTest )
const char extrSysID[]  = "OPEN_TCP_001PTL001_1000001548";
const char deviceID[]   = "twer47D1454114743672";
const char authnRqtNo[] = "ou6xem3f4";

char streamTag_temp[]  = "temp";   // sensor strem tag
char streamTag_humid[] = "humid";  // sensor strem tag

char streamTag_led[]   = "led";    // control strem tag
char streamTag_siren[] = "siren";  // control strem tag

// 0. Ethernet Client 객체 생성
EthernetClient ethclient;

// 1. 3mp 연동 라이브러리 클래스 객체 생성
OIPClient client(server, port, ethclient);

//----------------------------------
// 2. 제어 Stream별 Callback 함수
// - Siren Control Message handler
void hSiren(char *_val)
{
  Serial.print("hSiren :");
  Serial.println(atoi(_val)+100);  
}

// - Led Control Message Handler
void hLed(char *_val)
{
  Serial.print("hled :");
  Serial.println(_val);
}
//----------------------------------


void setup() {
  Serial.begin(9600);
  
  //////////////////////////////////////////////
  // 3. 3mp 연동 객체 초기화
  client.begin(extrSysID,deviceID, authnRqtNo);
  client.setTagCallbackFn(streamTag_siren, hSiren);
  client.setTagCallbackFn(streamTag_led, hLed);
  //............................................
  
  pinMode(SDCARD_CS,OUTPUT);
  digitalWrite(SDCARD_CS,HIGH); //Deselect the SD card
  
  Serial.println(F("START"));

  if (Ethernet.begin(mac) == 0) {
    Serial.println(F("Fail DHCP"));
    for(;;)
      ;
  }
  // print your local IP address:
  Serial.print(F("My IP: "));
  for (byte thisByte = 0; thisByte < 4; thisByte++) {
    // print the value of each byte of the IP address:
    Serial.print(Ethernet.localIP()[thisByte], DEC);
    Serial.print("."); 
  }

  delay(1000);
  
  // 4. 3mp 서버 연결
  client.loop(); 
}

void loop()
{
  double SenVal_TMP;
  double SenVal_HUM;
  byte result;
  static unsigned long timer_sens    = millis();
  static unsigned long timer_collect = millis();
 
  // Sensing Analog Channel, every 1 sec
  if( (millis() - timer_sens) > 1000)
  {
    SenVal_TMP = analogRead(A0);
    SenVal_HUM = analogRead(A1);
    
    Serial.print(SenVal_TMP); 
    Serial.print(F("C\t"));
    Serial.print(SenVal_HUM); 
    Serial.println(F("%"));

    timer_sens = millis();
  }

  // 5. 3mp 서버 인증/수신처리 및 keepalive 송신 기능
  client.loop();
  
  // 6. 3초 주기로 센서 정보 송신
  if((client.connected()) && ( ( millis() - timer_collect) > 3000))
  {
    result = client.collectData(streamTag_temp, SenVal_TMP);
    printResult(streamTag_temp, result);
    
    result = client.collectData(streamTag_humid, SenVal_HUM);
    printResult(streamTag_humid, result);
    
    timer_collect = millis();
  }
}

// Print the result after collectData to 3mp
void printResult(const char* tag, byte _sts)
{
    if(_sts == GOOD) 
    {
      Serial.print(tag);
      Serial.print(F(": "));
      Serial.println(F("Send OK"));
    } else if(_sts == BAD)
    {
      Serial.print(tag);
      Serial.print(F(": "));
      Serial.println(F("Send failed"));
    }else if(_sts == NY){
      Serial.print(tag);
      Serial.print(F(": "));
      Serial.println(F("Not ready"));
    }
  
}
