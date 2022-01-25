#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "heltec.h"
#define BAND    915E6  //you can set band here directly,e.g. 868E6,915E6
// Set the LCD address to 0x27 for a 20 chars and 4 line display
LiquidCrystal_I2C lcd(0x27, 20, 4);

byte Locked[8] = {
  B01110,
  B10001,
  B10001,
  B11111,
  B11011,
  B11011,
  B11111,
  B00000
};

byte Unlocked[8] = {
  B01100,
  B10010,
  B10000,
  B11111,
  B11011,
  B11011,
  B11111,
  B00000
};

void setup() {
  Serial.begin(9600);
  Heltec.begin(false /*DisplayEnable Enable*/, true /*Heltec.LoRa Disable*/, true /*Serial Enable*/, true /*PABOOST Enable*/, BAND /*long BAND*/);
  LoRa.setSyncWord(0xF3);           // ranges from 0-0xFF, default 0x34, see API docs
  LoRa.setSpreadingFactor(8);

  pinMode(RelaySwitch1, INPUT);
  pinMode(RelaySwitch2, INPUT);
  pinMode(RelaySwitch3, INPUT);
  pinMode(RelaySwitch4, INPUT);
  pinMode(SafetySwitch, INPUT);
  pinMode(unlockRelay1Switch, INPUT);
  pinMode(unlockRelay2Switch, INPUT);
  pinMode(unlockRelay3Switch, INPUT);
  pinMode(unlockRelay4Switch, INPUT);


  lcd.init();   // initialize the LCD
  lcd.createChar(7, Locked);
  lcd.createChar(6, Unlocked);

  lcd.backlight(); // Turn on the backlight and print a message.
  StartupLCD();
  LoRa.setTxPower(14, RF_PACONFIG_PASELECT_PABOOST);

  MainUI();


}
