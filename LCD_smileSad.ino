#include <LiquidCrystal_I2C.h>

#include <Wire.h>
LiquidCrystal_I2C lcd (0x27,16,2);

byte smiley[8] = {
  B00000,
  B10001,
  B00000,
  B00000,
  B10001,
  B01110,
  B00000,
};

byte smiley1[8] = {
  B00000,
  B10001,
  B00000,
  B00000,
  B01110,
  B10001,
  B00000,
};


int x=0;
int y=0;

void setup() {
 lcd.init();
 lcd.backlight();
 lcd.clear();
lcd.createChar(0, smiley);
lcd.createChar(1, smiley1);
  
}

void loop() {
  y=15;
  for (x=0; x<16; x++){
lcd.setCursor(x,0);
lcd.write(byte(0));
lcd.setCursor(y,1);
lcd.write(byte(1));
delay(400);
lcd.clear();     
y--;
  }
}
