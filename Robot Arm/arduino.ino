#include <Servo.h>
Servo servoIzqDer;
Servo servoArribaAbajo;
Servo servoGarra;
int anguloIzqDer;
int anguloArribaAbajo;
int anguloGarra;
int salto = 3;
int ejeIzqDer = A1;
int ejeArribaAbajo = A2;
int ejeGarra = A3;
int boton = 4;
int buttonState = 0;

void setup()
{
    servoIzqDer.attach(5);
    servoArribaAbajo.attach(6);
    servoGarra.attach(7);
    pinMode( boton, INPUT_PULLUP );
    // CM: inicia la comunicación serial
    Serial.begin(9600);
}

void loop()
{

    // CM: Servo que controla la garra
    int p = analogRead(ejeGarra);
    if (p < 350)
        anguloGarra -= salto;
    else if (p > 650)
        anguloGarra += salto;

    servoGarra.write(anguloGarra);

    // CM: Servo que controla el movimiento del brazo arriba y abajo
    int paa = analogRead(ejeArribaAbajo);
    if (paa < 350)
        anguloArribaAbajo -= salto;
    else if (paa > 650)
        anguloArribaAbajo += salto;

    servoArribaAbajo.write(anguloArribaAbajo);

    // CM: Servo que controla el movimiento del brazo izquierda y derecha
    int pid = analogRead(ejeIzqDer);
    if (pid < 350)
        anguloIzqDer -= salto;
    else if (pid > 650)
        anguloIzqDer += salto;

    servoIzqDer.write(anguloIzqDer);

    // CM: Control del boton de joystick para restablecer la posicion de los servos
    buttonState = digitalRead(boton);
    if(!buttonState){
        anguloGarra = 90;
        anguloArribaAbajo = 90;
        anguloIzqDer = 90;
    }

    // CM: validación de la comunicación serial y movimiento del brazo
    if (Serial.available()) {
        char serialListener = Serial.read();

        // CM: Serial=>Servo que controla la garra
        if (serialListener == 'K')
            anguloGarra -= salto;
        else if (serialListener == 'J')
            anguloGarra += salto;

        servoGarra.write(anguloGarra);

        // CM: Serial=>Servo que controla el movimiento del brazo arriba y abajo
        if (serialListener == 'S')
            anguloArribaAbajo -= salto;
        else if (serialListener == 'W')
            anguloArribaAbajo += salto;

        servoArribaAbajo.write(anguloArribaAbajo);

        // CM: Serial=>Servo que controla el movimiento del brazo izquierda y derecha
        if (serialListener == 'A')
            anguloIzqDer -= salto;
        else if (serialListener == 'D')
            anguloIzqDer += salto;

        servoIzqDer.write(anguloIzqDer);

        if (serialListener == 'R'){
          anguloGarra = 90;
          anguloArribaAbajo = 90;
          anguloIzqDer = 90;
        }
    }

    delay (50);
}
