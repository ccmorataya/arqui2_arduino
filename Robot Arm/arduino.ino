#include <Servo.h>
Servo servoIzqDer;
Servo servoAribaAbajo;
Servo servoGarra;
int anguloIzqDer;
int anguloArribaAbajo;
int anguloGarra;
int salto = 30;
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
    if (p < 400)
        anguloGarra -= salto;
    else if (p > 600)
        anguloGarra += salto;

    servoGarra.write(anguloGarra);

    // CM: Servo que controla el movimiento del brazo arriba y abajo
    int p = analogRead(ejeArribaAbajo);
    if (p < 400)
        anguloArribaAbajo -= salto;
    else if (p > 600)
        anguloArribaAbajo += salto;

    servoArribaAbajo.write(anguloArribaAbajo);

    // CM: Servo que controla el movimiento del brazo izquierda y derecha
    int p = analogRead(ejeIzqDer);
    if (p < 400)
        anguloIzqDer -= salto;
    else if (p > 600)
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
    }

    delay (50);
}
