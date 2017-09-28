int Eje_X = A1;
int Eje_Y = A2;
int boton = 4;
int LEDLEFT = 8;
int LEDRIGHT = 9;
int LEDUP = 10;
int LEDDOWN = 11;
void setup()
{
  pinMode( boton, INPUT_PULLUP);
  pinMode( LEDLEFT, OUTPUT);
  pinMode( LEDRIGHT, OUTPUT);
  pinMode( LEDUP, OUTPUT);
  pinMode( LEDDOWN, OUTPUT);
}

void loop()
{
  // CM: inicialización de los leds apagados en cada loop
  digitalWrite(LEDLEFT, LOW);
  digitalWrite(LEDRIGHT, LOW);
  digitalWrite(LEDUP, LOW);
  digitalWrite(LEDDOWN, LOW);

  // CM: leds del eje X
  int p = analogRead(A1);
  if ( p < 400 ) // Si la lectura es menor de 400
    digitalWrite(LEDLEFT, HIGH);
  else if (p>600) // Si mayor de 600
    digitalWrite(LEDRIGHT, HIGH);
    
  delay (50);

  // CM: leds del eje Y
  int p2 = analogRead(A2);
  if ( p2 < 400 ) // Si la lectura es menor de 400
    digitalWrite(LEDDOWN, HIGH);
  else if (p2 > 600) // Si mayor de 600
    digitalWrite(LEDUP, HIGH);
    
  delay (50);
}
