float sensibilidad = 0.185; 
const int PIN_RELE = 8;     
const float LIMITE_CORRIENTE = 2.5;

void setup() {
  Serial.begin(9600);
  pinMode(PIN_RELE, OUTPUT);
  digitalWrite(PIN_RELE, HIGH); 
}

void loop() {
  float i = get_corriente(200); 
  Serial.print("Corriente: ");
  Serial.println(i, 3);

  if (i > LIMITE_CORRIENTE) {
    Serial.println("Corriente excedida. Cortando la corriente...");
    digitalWrite(PIN_RELE, LOW);
  } else {
    digitalWrite(PIN_RELE, HIGH); 
  }

  delay(200); 
}

float get_corriente(int n_muestras) {
  float voltaje_sensor;
  float corriente = 0;

  for (int i = 0; i < n_muestras; i++) {
    voltaje_sensor = analogRead(A0) * (5.0 / 1023.0);
    corriente += (voltaje_sensor - 2.5) / sensibilidad; 

  corriente = corriente / n_muestras;
  return corriente;
}
