#define DELAY 1000

#include <M5Stack.h>

#include "bitmap.h"

TFT_eSprite betta_spr = TFT_eSprite(&M5.Lcd);

void setup()
{
  Serial.begin(250000);
  Serial.println();

  M5.begin();

  betta_spr.createSprite(Betta_width, Betta_height);
  betta_spr.setColorDepth(16);
  betta_spr.pushImage(0, 0, Betta_width, Betta_height, Betta_bits);

  // Clear the TFT screen to blue
  M5.Lcd.fillScreen(TFT_BLUE);
}

void loop(void)
{
   M5.Lcd.fillScreen(TFT_BLUE);

  betta_spr.pushSprite(160, 120);

  delay(DELAY);
}
