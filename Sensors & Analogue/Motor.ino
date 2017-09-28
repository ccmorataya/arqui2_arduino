int motorPin = 5;

void setup(){
        pinMode(motorPin, OUTPUT);
}?
void loop(){
        digitalWrite(motorPin, HIGH);
        delay(1000);
        digitalWrite(motorPin, LOW);
        delay(1000);
}


int motorPin = 5;
        /* connecta tu motor al pin 5 PWM */

void setup(){
        /* nada pasa en el setup */ 
}

void loop(){
        for(int i = 0; i <= 255; i++){
        /* incrementa una unidad, mientras sea menor de 255 */
        analogWrite(motorPin,i);
        /* modifica la velocidad de vibracion con i */
        delay(30);
        /* haz una pequeña pausa para percibir el cambio */
}

for(int i = 255; i >= 0; i--){
        /* mientras i sea mayor de 0, decrementa una unidad */
        analogWrite(motorPin,i);
        /* modifica la velocidad de vibracion con i */
        delay(30);
        /* haz una pequeña pausa para percibir el cambio */
}
}

