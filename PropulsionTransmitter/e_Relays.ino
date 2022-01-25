void checkrelay1() {
  if (safety == 1) { //safety == 1 is where system is armed.
    int uRelay1Stat = digitalRead(unlockRelay1Switch);
    if (uRelay1Stat == 1) {     //uRelay1Stat == 1 is when switch to arm port is activated.
      UnlockRelayStatus1_UNLOCKED();
      int R1SwitchStatus = digitalRead(RelaySwitch1);


      if (R1SwitchStatus == 1  && sent1 == 0) {
        //Send command to turn on relay
        sendRelay1_ON();
        sent1 = 1;
      }
      if (R1SwitchStatus == 0  && sent1 == 1) {
        //Send Standby command to turn off relay
        sendRelay1_OFF();
        sent1 = 0;
      }

    }

    if (uRelay1Stat == 0 && sent1 == 1) {
      UnlockRelayStatus1_LOCKED();
      sent1 = 0;
      sendRelay1_OFF(); //could add this to receiver side to not send data constantly
    }
    if (uRelay1Stat == 0) {
      UnlockRelayStatus1_LOCKED();
    }

  }
  else if (safety == 0) {
    UnlockRelayStatus1_LOCKED();
    UnlockRelayStatus2_LOCKED();
    UnlockRelayStatus3_LOCKED();
    UnlockRelayStatus4_LOCKED();
  }
}

void checkrelay2() {
  if (safety == 1) { //safety == 1 is where system is armed.
    int uRelay2Stat = digitalRead(unlockRelay2Switch);
    if (uRelay2Stat == 1) {     //uRelay1Stat == 1 is when switch to arm port is activated.
      UnlockRelayStatus2_UNLOCKED();
      int R2SwitchStatus = digitalRead(RelaySwitch2);

      if (R2SwitchStatus == 1 && sent2 == 0) {
        //Send command to turn on relay
        sendRelay2_ON();
        sent2 = 1;
      }
      if (R2SwitchStatus == 0 && sent2 == 1) {
        //Send Standby command to turn off relay
        sendRelay2_OFF();
        sent2 = 0;
      }

    }

    if (uRelay2Stat == 0 && sent2 == 1) {
      UnlockRelayStatus2_LOCKED();
      sendRelay2_OFF(); //could add this to receiver side to not send data constantly
      sent2 = 0;
    }
    if (uRelay2Stat == 0) {
      UnlockRelayStatus2_LOCKED();
    }
  }
  else if (safety == 0) {
    UnlockRelayStatus1_LOCKED();
    UnlockRelayStatus2_LOCKED();
    UnlockRelayStatus3_LOCKED();
    UnlockRelayStatus4_LOCKED();
  }
}

void checkrelay3() {
  if (safety == 1) { //safety == 1 is where system is armed.
    int uRelay3Stat = digitalRead(unlockRelay3Switch);
    if (uRelay3Stat == 1) {     //uRelay1Stat == 1 is when switch to arm port is activated.
      UnlockRelayStatus3_UNLOCKED();
      int R3SwitchStatus = digitalRead(RelaySwitch3);

      if (R3SwitchStatus == 1 && sent3 == 0) {
        //Send command to turn on relay
        sendRelay3_ON();
        sent3 = 1;
      }
      if (R3SwitchStatus == 0 && sent3 == 1) {
        //Send Standby command to turn off relay
        sendRelay3_OFF();
        sent3 = 0;
      }

    }

    if (uRelay3Stat == 0 && sent3 == 1) {
      UnlockRelayStatus3_LOCKED();
      sendRelay3_OFF(); //could add this to receiver side to not send data constantly
      sent3 = 0;
    }
    if (uRelay3Stat == 0) {
      UnlockRelayStatus3_LOCKED();
    }
  }
  else if (safety == 0) {
    UnlockRelayStatus1_LOCKED();
    UnlockRelayStatus2_LOCKED();
    UnlockRelayStatus3_LOCKED();
    UnlockRelayStatus4_LOCKED();
  }
}

void checkrelay4() {
  if (safety == 1) { //safety == 1 is where system is armed.
    int uRelay4Stat = digitalRead(unlockRelay4Switch);
    if (uRelay4Stat == 1) {     //uRelay1Stat == 1 is when switch to arm port is activated.
      UnlockRelayStatus4_UNLOCKED();
      int R4SwitchStatus = digitalRead(RelaySwitch4);

      if (R4SwitchStatus == 1 && sent4 == 0) {
        //Send command to turn on relay
        sendRelay4_ON();
        sent4 = 1;

      }

      if (R4SwitchStatus == 0 && sent4 == 1) {
        //Send Standby command to turn off relay
        sendRelay4_OFF();
        sent4 = 0;

      }
    }

    if (uRelay4Stat == 0 && sent4 == 1) {
      UnlockRelayStatus4_LOCKED();
      sendRelay4_OFF(); //could add this to receiver side to not send data constantly
      sent4 = 0;
    }
    if (uRelay4Stat == 0) {
      UnlockRelayStatus4_LOCKED();
    }
  }
  else if (safety == 0) {
    UnlockRelayStatus1_LOCKED();
    UnlockRelayStatus2_LOCKED();
    UnlockRelayStatus3_LOCKED();
    UnlockRelayStatus4_LOCKED();
  }
}
