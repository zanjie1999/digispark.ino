#include "DigiKeyboard.h"

void setup() {
DigiKeyboard.sendKeyStroke(0);
DigiKeyboard.delay(1000);
DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT);
DigiKeyboard.delay(2000);
DigiKeyboard.print("notepad");
DigiKeyboard.sendKeyStroke(KEY_ENTER);
DigiKeyboard.delay(3000);
DigiKeyboard.print("echo 15");
DigiKeyboard.sendKeyStroke(KEY_ENTER);
DigiKeyboard.print("@ping 127.0.0.1 -n 5 -w 1000 > nul");
DigiKeyboard.sendKeyStroke(KEY_ENTER);
DigiKeyboard.print("echo 10");
DigiKeyboard.sendKeyStroke(KEY_ENTER);
DigiKeyboard.print("@ping 127.0.0.1 -n 5 -w 1000 > nul");
DigiKeyboard.sendKeyStroke(KEY_ENTER);
DigiKeyboard.print("echo 5");
DigiKeyboard.sendKeyStroke(KEY_ENTER);
DigiKeyboard.print("@ping 127.0.0.1 -n 5 -w 1000 > nul");
DigiKeyboard.sendKeyStroke(KEY_ENTER);
DigiKeyboard.print("echo copying");
DigiKeyboard.sendKeyStroke(KEY_ENTER);
DigiKeyboard.print("xcopy E:\\installWin10 D:\\");
DigiKeyboard.sendKeyStroke(KEY_ENTER);
DigiKeyboard.sendKeyStroke(KEY_S, MOD_CONTROL_LEFT);
DigiKeyboard.delay(3000);
DigiKeyboard.print("d:\\copy.bat");
DigiKeyboard.sendKeyStroke(KEY_ENTER);
DigiKeyboard.delay(2000);
DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT);
DigiKeyboard.delay(2000);
DigiKeyboard.print("d:\\copy.bat");
DigiKeyboard.sendKeyStroke(KEY_ENTER);

}

void loop() {
}
