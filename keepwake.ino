#define WAIT_TIME 1500
#define FIX_NUM 2

#include <DigiMouse.h>

int num = 0;

void fadeIN(unsigned int stime) {
  for (byte value = 0 ; value < 255; value ++) {
    analogWrite(1, value);
    DigiMouse.delay(stime / 255);
  }
}

void fadeOUT(unsigned int etime) {
  for (byte value = 255; value > 0; value --) {
    analogWrite(1, value);
    DigiMouse.delay(etime / 255);
  }
}

void setup() {
  pinMode(1, OUTPUT);
  DigiMouse.begin();
}

void loop() {
  fadeIN(1000);

  DigiMouse.moveX(1);
  DigiMouse.moveY(1);

  DigiMouse.moveX(-1);
  DigiMouse.moveY(-1);

  num++;

  // fix Windows mouse
  if (num == FIX_NUM) {
    DigiMouse.moveX(1);
    DigiMouse.moveY(1);
    num = 0;
  }

  fadeOUT(1000);
  digitalWrite(1, LOW);
  // wait the longer interval
  DigiMouse.delay(WAIT_TIME);
}
