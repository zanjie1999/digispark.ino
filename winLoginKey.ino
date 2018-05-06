#include "DigiKeyboard.h"
#define KEY_ESC      41

void login() {
  DigiKeyboard.sendKeyStroke(0);
  DigiKeyboard.delay(100);
  DigiKeyboard.sendKeyStroke(KEY_ESC);
  DigiKeyboard.delay(200);
  DigiKeyboard.print("password");
  DigiKeyboard.delay(10);
  DigiKeyboard.sendKeyStroke(KEY_ENTER);

  fade(1000, 1000);
  DigiKeyboard.delay(1000);
}

void fade(int stime, int etime) {
  for (byte value = 0 ; value < 255; value++) {
    analogWrite(1, value);
    delay(stime / 255);
  }
  for (byte value = 255; value > 0; value--) {
    analogWrite(1, value);
    delay(etime / 255);
  }
  digitalWrite(1, LOW);
}

void setup() {
  pinMode(1, OUTPUT);
  pinMode(2, INPUT);

  login();
}

void loop() {
  if (digitalRead(2) == LOW) {
    DigiKeyboard.sendKeyStroke(KEY_L, MOD_GUI_RIGHT);

    fade(1000, 1000);

    if (digitalRead(2) == HIGH) {
      login();
    } else {
      DigiKeyboard.delay(5000);
      while (digitalRead(2) == HIGH);
      login();
    }
  }
}
