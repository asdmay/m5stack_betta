#include <M5Stack.h>

float x;
float y;
float speedX;
float speedY;

// the setup routine runs once when M5Stack starts up
void setup() {

  // Initialize the M5Stack object
  M5.begin();
  /*
    Power chip connected to gpio21, gpio22, I2C device
    Set battery charging voltage and current
    If used battery, please call this function in your project
  */
  M5.Power.begin();

  // LCD display
  // M5.Lcd.print("Hello World");
  x = 0;
  y = 0;
  speedX = 1;
  speedY = 1;
}

// the loop routine runs over and over again forever
void loop() {
  M5.update();

  M5.Lcd.fillScreen(BLUE);

  if (M5.BtnA.pressedFor(30)) {
    M5.Lcd.fillScreen(BLACK);
  }


  speedX = speedX * 0.98;
  if (0 < speedX && speedX < 0.3) {
    speedX = 0.9;
  }
  if (0 > speedX && speedX > -0.3) {
    speedX = -0.9;
  }

  speedY = speedY * 0.98;
  if (0 < speedY && speedY < 0.3) {
    speedY = 0.9;
  }
  if (0 > speedY && speedY > -0.3) {
    speedY = -0.9;
  }

  // 衝突判定
  if (x < 0 || x > 320 ) {
    speedX = -speedX;
  }
  if (y < 0 || y > 240) {
    speedY = -speedY;
  }


  x += speedX;
  y += speedY;

  M5.Lcd.drawJpgFile(SD, "/Betta.jpeg", x, y);
  delay(100);

}
