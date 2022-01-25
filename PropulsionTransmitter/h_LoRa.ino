void sendRelay1_ON() {
  LoRa.beginPacket();
  LoRa.print("111");
  LoRa.endPacket();
  lcd.setCursor(1, 2); //(column, row)
  lcd.print("ON ");
}

void sendRelay1_OFF() {
  LoRa.beginPacket();
  LoRa.print("101");
  LoRa.endPacket();
  lcd.setCursor(1, 2); //(column, row)
  lcd.print("OFF");
}

void sendRelay2_ON() {
  LoRa.beginPacket();
  LoRa.print("222");
  LoRa.endPacket();
  lcd.setCursor(6, 2); //(column, row)
  lcd.print("ON ");
}

void sendRelay2_OFF() {
  LoRa.beginPacket();
  LoRa.print("202");
  LoRa.endPacket();
  lcd.setCursor(6, 2); //(column, row)
  lcd.print("OFF");
}
void sendRelay3_ON() {
  LoRa.beginPacket();
  LoRa.print("333");
  LoRa.endPacket();
  lcd.setCursor(11, 2); //(column, row)
  lcd.print("ON ");
}

void sendRelay3_OFF() {
  LoRa.beginPacket();
  LoRa.print("303");
  LoRa.endPacket();
  lcd.setCursor(11, 2); //(column, row)
  lcd.print("OFF");
}

void sendRelay4_ON() {
  LoRa.beginPacket();
  LoRa.print("444");
  LoRa.endPacket();
  lcd.setCursor(16, 2); //(column, row)
  lcd.print("ON ");
}

void sendRelay4_OFF() {
  LoRa.beginPacket();
  LoRa.print("404");
  LoRa.endPacket();
  lcd.setCursor(16, 2); //(column, row)
  lcd.print("OFF");
}
