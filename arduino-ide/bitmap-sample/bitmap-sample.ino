#include "SenseCapLCD.hpp"
#include "image.h"

void setup()
{
  lcd.init();
  lcd.pushImage(0, 0, IMAGE_W, IMAGE_H, (lgfx:: rgb565_t*)image);
}

void loop() 
{
}