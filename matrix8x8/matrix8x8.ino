#include "LedControlMS.h"
#define NumMatrix 1       // Cuantas matrices vamos a usar

LedControl lc=LedControl(12,11,10, NumMatrix);  // Creamos una instancia de LedControl

void setup()
   {
      for (int i=0; i< NumMatrix ; i++)
        {
           lc.shutdown(i,false);    // Activar las matrices
           lc.setIntensity(i,8);    // Poner el brillo a un valor intermedio
           lc.clearDisplay(i);      // Y borrar todo
        }
   }

void loop()
   {
        lc.writeString(0," UMG Chinautla ");
        delay(1000);
   }
