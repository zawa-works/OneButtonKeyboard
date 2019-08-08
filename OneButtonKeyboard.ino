#include "Keyboard.h"
const int BUTTON = 7; // ボタンをデジタルピン7に接続

int old_val = 0;
int val = 0; //ボタンの状態


void setup() {
  Keyboard.begin();
  pinMode(BUTTON, INPUT); // ボタン変数は入力に
}

void loop() {
  val = digitalRead(BUTTON);  //ボタンの状態を常時取得

  //ボタンが押された時に行う処理
  if (val == 1 && old_val == 0) {
    Keyboard.press(' ');
    delay(100);
    Keyboard.releaseAll();
    delay(100); //バウンシング防止（スイッチの半端な接触バグ防止）
    old_val = 1;
  }

  if (val == 0)old_val = 0;

}
