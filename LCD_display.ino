#include <LiquidCrystal_I2C.h>

#include <Wire.h>
LiquidCrystal_I2C lcd (0x27,16,2);



void setup() {
  // put your setup code here, to run once:
lcd.init();
lcd.backlight();

}

void loop() {
  // put your main code here, to run repeatedly:
lcd.clear();
lcd.setCursor(0,0);
lcd.print("Arquitectura De");
lcd.setCursor(0,1);
lcd.print("Computadoras");
delay(1000);
lcd.clear();
lcd.setCursor(0,0);
lcd.print("Gilberto");
lcd.setCursor(0,1);
lcd.print("5990-14-8047");
delay(1000);
lcd.clear();
lcd.setCursor(0,0);
lcd.print("Cristian");
lcd.setCursor(0,1);
lcd.print("5990-11-3777");
delay(1000);
lcd.clear();
lcd.setCursor(0,0);
lcd.print("Luis");
lcd.setCursor(0,1);
lcd.print("5990-03-4508");
delay(1000);

}
