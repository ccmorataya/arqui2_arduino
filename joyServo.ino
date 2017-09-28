#include <Servo.h>            // Incluir la librería Servo
Servo servo1;                 // Crear un objeto tipo Servo llamado servo1
Servo servo2;
int angulo = 90;             // Empezamos en el centro
int anguloY = 90;
int salto = 30;               // Controla el salto por movimiento
int Eje_X = A1;
int Eje_Y = A2;
int boton = 4;
int LED = 12;
int buttonState = 0;

void setup()
{
  servo1.attach(6);         // Conectar servo1 al pin 6
  servo2.attach(5);
  pinMode( boton, INPUT_PULLUP);
}

void loop()
{
  int p = analogRead(A1);
  if ( p < 400 ) // Si la lectura es menor de 400
    angulo = angulo - salto ; // disminuimos el angulo
  else if (p>600) // Si mayor de 600
    angulo = angulo + salto ; // Aumentamos el angulo
    
  servo1.write(angulo); // Y este es el que mueve el servo

// CM: servo 2 eje Y
  int p2 = analogRead(A2);
	if ( p2 < 400 ) // Si la lectura es menor de 400
		anguloY = anguloY - salto ; // disminuimos el angulo
	else if (p2 > 600) // Si mayor de 600
		anguloY = anguloY + salto ; // Aumentamos el angulo
	
	servo2.write(anguloY); // Y este es el que mueve el servo
 
  buttonState = digitalRead(boton);
  if(!buttonState)
  {
    angulo = 90;
    anguloY = 90;
  }
	delay (50); // Este delay regula la velocidad del movimiento
}
