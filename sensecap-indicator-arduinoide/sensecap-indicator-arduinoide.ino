#include "SenseCapLCD.hpp"

int32_t old_touch_x;    // 前回タッチX座標
int32_t old_touch_y;    // 前回タッチY座標
uint8_t was_pressed;    // 前回タッチされたか

void setup()
{
  Serial.begin(115200);
  pinMode(BUTTON_GPIO, INPUT);

  lcd.init();
  lcd.fillScreen(TFT_BLACK);
  
  was_pressed = false;
}

void loop() 
{
  // LCDのタッチ検出
  int32_t x, y;
  if (lcd.getTouch(&x, &y)) 
  {
    // タッチ座標をUART出力
    Serial.printf("[touched!] x = %d, y = %d\n", x, y);

    // ライン描画
    if (was_pressed)
    {
      lcd.drawLine(old_touch_x, old_touch_y, x, y, TFT_WHITE);
    }

    // タッチ情報を保存
    was_pressed = true;
    old_touch_x = x;
    old_touch_y = y;
  }
  else
  {
    was_pressed = false;
  }

  // スイッチ入力検出
  if (digitalRead(BUTTON_GPIO) == 0) 
  {
    // LCDのクリア
    lcd.fillScreen(TFT_BLACK);
    Serial.println("[pressed!]");
  }
  delay(10);
}