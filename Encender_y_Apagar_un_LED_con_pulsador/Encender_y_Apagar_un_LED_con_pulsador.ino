const int LED = 5;
const int LED2 = 13;
const int BOTON = 2;
const int BOTON2 = 9;

int val = 0; //val se emplea para almacenar el estado del boton
int val2 = 0;
int state = 0; // 0 LED apagado, mientras que 1 encendido
int state2 = 0;
int old_val = 0; // almacena el antiguo valor de val
int old_val2 = 0;

void setup() { // definir si la variable es de entrada o salida.
  Serial.begin(9600);
  pinMode(LED, OUTPUT); // establecer que el pin digital es una señal de salida
  pinMode(LED2, OUTPUT);
  pinMode(BOTON, INPUT); // y BOTON como señal de entrada
  pinMode(BOTON2, INPUT);
}
void loop() {

  ///////////////////////////////////////////////////////////////////// Codigo para primer LED
  val = digitalRead(BOTON); // lee el estado del Boton
  if ((val == HIGH) && (old_val == LOW)) {
    state = 1 - state;
    delay(10);
  }
  old_val = val; // valor del antiguo estado

  if (state == 1) {
    digitalWrite(LED, HIGH);
  }
  else {
    digitalWrite(LED, LOW);
  }
  ///////////////////////////////////////////////////////////////////// Codigo para segunda LED
  val2 = digitalRead(BOTON2);
  if ((val2 == HIGH) && (old_val2 == LOW)) {
    state2 = 1 - state2;
    delay(10);
  }
  old_val2 = val2;

  if (state2 == 1) {
    digitalWrite(LED2, HIGH);
  }
  else {
    digitalWrite(LED2, LOW);
  }
}
