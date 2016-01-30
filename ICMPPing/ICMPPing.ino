#include <SPI.h>
#include <Ethernet.h>
#include <ICMPPing.h>

byte mac[] = {0xDE,0xAD,0xBE,0xEF,0xFE,0xED};
byte ip[] = {192,168,120,20};
IPAddress pingAddr(211,233,50,220);

SOCKET pingSocket = 0;

char buffer [256];
ICMPPing ping(pingSocket, (uint16_t)random(0, 255));

void setup() {
  // put your setup code here, to run once:
  Ethernet.begin(mac, ip);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  ICMPEchoReply echoReply = ping(pingAddr, 4);
  if(echoReply.status == SUCCESS)
  {
    sprintf(buffer,
              "Reply[%d] from:%d.%d.%d.%d:bytes=%d time=%ldms TTL=%d",
              echoReply.data.seq,
              echoReply.addr[0],
              echoReply.addr[1],
              echoReply.addr[2],
              echoReply.addr[3],
              REQ_DATASIZE,
              millis() - echoReply.data.time,
              echoReply.ttl);
  }
  else
  {
    sprintf(buffer, "Echo request failed; %d", echoReply.status);
  }
  Serial.println(buffer);
  delay(500);
}
