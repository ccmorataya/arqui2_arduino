#include <LiquidCrystal.h>  

//Definiendo los pines que se van a usar del LCD
LiquidCrystal lcd(12, 11, 10, 9, 8 ,7);

int espacio= 100;    //distancia inicial entre sensores en milimetros
int sensori= 3;          // sensor de inicio
int sensorf = 2;          // sensor de fin 
unsigned long tiempo_i;    // tiempo de inicio de medicion
unsigned long tiempo_t;    // diferencia de tiempo del movimiento
float velocidad;          // nùmero de coma flotante para mayor precisión

void setup()
//lcd.begin(16, 2);

{
lcd.begin(16, 2);

  lcd.setCursor(0, 1);
  
 pinMode(sensori,INPUT); 
 pinMode(sensorf, INPUT); 
 }

void loop()
{ 
lcd.print("comience... ");
while (!digitalRead(sensori)) { }
tiempo_i=millis();
while (!digitalRead(sensorf)) { }
tiempo_t = millis()-tiempo_i;


velocidad=espacio/tiempo_t;
lcd.clear();
 lcd.print("Velocidad: ");
 lcd.println(velocidad);

   lcd.setCursor(0, 1); 
 lcd.print("Tiempo:   ");
 lcd.println(tiempo_t);  

 delay (4000);
  
lcd.clear();


}

