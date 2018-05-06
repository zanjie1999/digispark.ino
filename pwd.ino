#include <DigiKeyboard.h>
#define ledPin 1
#define touchPin 0

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(touchPin, INPUT);
  pinMode(2, INPUT);
  DigiKeyboard.sendKeyStroke(0);
}

void loop() {
  int type = 0;
  if (digitalRead(touchPin)) {
    while (true) {
      if (fade(700, 5, 300)) {
        type++;
      } else {
        typePwd(type);
        digitalWrite(ledPin, LOW);
        break;
      }
    }
  }
}

void typePwd(int type) {
  DigiKeyboard.sendKeyStroke(0);
  switch (type) {
        case 1:
          DigiKeyboard.print("pwd1");
          break;
        case 2:
          DigiKeyboard.print("pwd2");
          break;
        case 3:
          DigiKeyboard.print("pwd3");
          break;
    default:
      DigiKeyboard.sendKeyStroke(type);
  }
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
}

int fade(unsigned int stime, int creament, int etime) {
  for (byte value = 0 ; value < 255; value += creament) {
    analogWrite(ledPin, value);
    delay(stime / (255 / creament));
  }
  int touch = digitalRead(touchPin);
  for (byte value = 255; value > 0; value -= creament) {
    analogWrite(ledPin, value);
    delay(etime / (255 / creament));
  }
  return touch;
}


