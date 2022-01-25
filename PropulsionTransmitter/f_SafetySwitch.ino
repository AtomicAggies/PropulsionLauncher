void checkSafetySwitchStatus() {            //safety switch (1 = armed)
  safetyStat = digitalRead(SafetySwitch);
  if (safetyStat == 0) {
    safety = 0;
    ArmedStatus_SAFE();
  }
  if (safetyStat == 1) {
    safety = 1;
    ArmedStatus_ARMED();
  }
  else {
    safety = 0;
    ArmedStatus_SAFE();
  }
}
