#include <SPI.h>
#include <Ethernet.h>

byte mac[] = {0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED};

EthernetClient client;

//IPAddress ip(192,168,102,21);

void setup(){
  Serial.begin(9600);
   if(Ethernet.begin(mac) == 0){
    Serial.println("Failed to configure Ethernet using DHCP");
    while(1);

    Serial.print("My IP address:");
    for(byte thisByte=0; thisByte<4; thisByte++){
      Serial.print(Ethernet.localIP()[thisByte],DEC);
      Serial.print(".");
    }
  }
}

void loop(){
  
}

