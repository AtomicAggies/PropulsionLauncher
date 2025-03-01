
#include "heltec.h"
// pins for relays
int relay1 = 12;
int relay2 = 13;
int relay3 = 2;
int relay4 = 17;

// time activated for the safety shutoff feature
int relay1Time = -1;
int relay2Time = -1;
int relay3Time = -1;
int relay4Time = -1;

// number of miliseconds allowed to pass before auto-shutoff
#define SAFETY_TIME1  3000
#define SAFETY_TIME2  3000
#define SAFETY_TIME3  3000
#define SAFETY_TIME4  3000
#define BAND          915E6  //you can set band here directly,e.g. 868E6,915E6

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
    // read the packet
    while (LoRa.available()) {
      String inmessage =  LoRa.readString();
      inmessage.remove(3, 1);

      if (inmessage == "111") {
        relay1Time = millis();
        digitalWrite(relay1, HIGH);
        //delay(150);
        Serial.println("relay1on");
      }
      if (inmessage == "222") {
        relay2Time = millis();
        digitalWrite(relay2, HIGH);
        //delay(150);
        Serial.println("relay2on");
      }

      if (inmessage == "333") {
        relay3Time = millis();
        digitalWrite(relay3, HIGH);
        //delay(150);
        Serial.println("relay3on");
      }
      if (inmessage == "444") {
        relay4Time = millis();
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
    }
  }

  // ensure relays don't stay on for too long
  if (relay1Time > 0) {
    if (millis() - relay1Time > SAFETY_TIME1) {
      digitalWrite(relay1, LOW);
      relay1Time = -1;
      Serial.println("safety feature: relay 1 off");
    }
  }
  if (relay2Time > 0) {
    if (millis() - relay2Time > SAFETY_TIME2) {
      digitalWrite(relay2, LOW);
      relay2Time = -1;
      Serial.println("safety feature: relay 2 off");
    }
  }
  if (relay3Time > 0) {
    if (millis() - relay3Time > SAFETY_TIME3) {
      digitalWrite(relay3, LOW);
      relay3Time = -1;
      Serial.println("safety feature: relay 3 off");
    }
  }
  if (relay4Time > 0) {
    if (millis() - relay4Time > SAFETY_TIME4) {
      digitalWrite(relay4, LOW);
      relay4Time = -1;
      Serial.println("safety feature: relay 4 off");
    }
  }
}
