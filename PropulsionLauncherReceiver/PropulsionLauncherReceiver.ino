
#include "heltec.h"
int relay1 = 12;
int relay2 = 13;
int relay3 = 2;
int relay4 = 17;
int interval = 70;


#define BAND    915E6  //you can set band here directly,e.g. 868E6,915E6

void setup() {
  //  WIFI Kit series V1 not support Vext control
  Heltec.begin(false /*DisplayEnable Enable*/, true /*Heltec.LoRa Disable*/, true /*Serial Enable*/, true /*PABOOST Enable*/, BAND /*long BAND*/);
  //Heltec.display->setContrast(255);
  LoRa.setSyncWord(0xF3);           // ranges from 0-0xFF, default 0x34, see API docs
  LoRa.setSpreadingFactor(8);
  Serial.begin(9600);

  pinMode(relay1, OUTPUT);
  digitalWrite(relay1, LOW);

  pinMode(relay2, OUTPUT);
  digitalWrite(relay2, LOW);

  pinMode(relay3, OUTPUT);
  digitalWrite(relay3, LOW);

  pinMode(relay4, OUTPUT);
  digitalWrite(relay4, LOW);

}

void loop() {
  // try to parse packet
  int packetSize = LoRa.parsePacket();

  if (packetSize) {

    // received a packet
    //Serial.println("Received packet '");
    // read packet
    while (LoRa.available()) {

      //      Heltec.display->drawString(0, 0, "Receiving");
      //      Heltec.display->display();

      String inmessage =  LoRa.readString();
      inmessage.remove(3, 1);
      //Serial.println(inmessage);


      if (inmessage == "111") {
        digitalWrite(relay1, HIGH);
        //delay(150);
        Serial.println("relay1on");
      }
      if (inmessage == "222") {
        digitalWrite(relay2, HIGH);
        //delay(150);
        Serial.println("relay2on");
      }

      if (inmessage == "333") {
        digitalWrite(relay3, HIGH);
        //delay(150);
        Serial.println("relay3on");
      }
      if (inmessage == "444") {
        digitalWrite(relay4, HIGH);
        // delay(150);
        Serial.println("relay4on");
      }




      if (inmessage == "101") {
        digitalWrite(relay1, LOW);
        //delay(150);
        Serial.println("relay1off");
      }
      if (inmessage == "202") {
        digitalWrite(relay2, LOW);
        //delay(150);
        Serial.println("relay2off");
      }

      if (inmessage == "303") {
        digitalWrite(relay3, LOW);
        //delay(150);
        Serial.println("relay3off");
      }
      if (inmessage == "404") {
        digitalWrite(relay4, LOW);
        // delay(150);
        Serial.println("relay4off");
      }



//      // print RSSI of packet
//      Serial.println("' with RSSI ");
//      Serial.printlnln(LoRa.packetRssi());


    }





  }


  //  digitalWrite(relay1, LOW);
  //  digitalWrite(relay2, LOW);
  //  digitalWrite(relay3, LOW);
  //  digitalWrite(relay4, LOW);






}
