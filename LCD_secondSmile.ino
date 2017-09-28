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
int x=0;
int y=0;

void setup() {
 lcd.init();
 lcd.backlight();
 lcd.clear();
lcd.createChar(0, smiley);
  
}

void loop() {
  for (x=0; x<16; x++){
lcd.setCursor(x,y);
lcd.write(byte(0));
delay(400);
lcd.clear();     
  }
}
 else
 {for (x=16; x>=0; x--){
lcd.setCursor(x,y);
lcd.write(byte(0));
delay(400);
lcd.clear();     
  }}
  if (y==0 ){
    y++;
    
  }
  else{y--;
  }
}
