


void StartupLCD() {
  lcd.setCursor(3, 1); //(column, row)
  lcd.print("Atomic  Aggies");
  delay(1000);
  lcd.setCursor(5, 2); //(column, row)
  lcd.print("PROPULSION");
  delay(3000);
  lcd.clear();
}
void MainUI() {
  lcd.setCursor(1, 1); //(column, row)
  lcd.print("R1");
  lcd.setCursor(6, 1); //(column, row)
  lcd.print("R2");
  lcd.setCursor(11, 1); //(column, row)
  lcd.print("R3");
  lcd.setCursor(16, 1); //(column, row)
  lcd.print("R4");

  lcd.setCursor(0, 3); //(column, row)
  lcd.print("System Status:");


  lcd.setCursor(1, 2); //(column, row)
  lcd.print("OFF");
  lcd.setCursor(6, 2); //(column, row)
  lcd.print("OFF");
  lcd.setCursor(11, 2); //(column, row)
  lcd.print("OFF");
  lcd.setCursor(16, 2); //(column, row)
  lcd.print("OFF");

  lcd.setCursor(1, 0); //(column, row)
  lcd.write(byte(7));
  lcd.setCursor(6, 0); //(column, row)
  lcd.write(byte(7));
  lcd.setCursor(11, 0); //(column, row)
  lcd.write(byte(7));
  lcd.setCursor(16, 0); //(column, row)
  lcd.write(byte(7));

}

void UnlockRelayStatus1_LOCKED() {

  lcd.setCursor(1, 0); //(column, row)
  lcd.write(byte(7)); // Custom char
}

void UnlockRelayStatus1_UNLOCKED() {


  lcd.setCursor(1, 0); //(column, row)
  lcd.write(byte(6)); // Custom char
}
void UnlockRelayStatus2_LOCKED() {

  lcd.setCursor(6, 0); //(column, row)
  lcd.write(byte(7)); // Custom char

}

void UnlockRelayStatus2_UNLOCKED() {


  lcd.setCursor(6, 0); //(column, row)
  lcd.write(byte(6)); // Custom char

}

void UnlockRelayStatus3_LOCKED() {

  lcd.setCursor(11, 0); //(column, row)
  lcd.write(byte(7)); // Custom char

}

void UnlockRelayStatus3_UNLOCKED() {


  lcd.setCursor(11, 0); //(column, row)
  lcd.write(byte(6)); // Custom char

}
void UnlockRelayStatus4_LOCKED() {

  lcd.setCursor(16, 0); //(column, row)
  lcd.write(byte(7)); // Custom char

}

void UnlockRelayStatus4_UNLOCKED() {

  lcd.setCursor(16, 0); //(column, row)
  lcd.write(byte(6)); // Custom char

}
void ArmedStatus_ARMED() {

  lcd.setCursor(15, 3); //(column, row)
  lcd.print("ARMED");

}
void ArmedStatus_SAFE() {

  lcd.setCursor(15, 3); //(column, row)
  lcd.print("SAFE ");

}
