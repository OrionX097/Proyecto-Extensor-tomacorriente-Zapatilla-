float sensibilidad = 0.785;


void setup() {
  Serial.Begin(9600);

}

void loop() {
  float i = get_corriente (200);
  serial.print("corriente; ");
  serial.println(i,3);
  delay(100);
}
float get_corriente(int n_muestras){
  float voltaje_sensor;
  float corriente=0;
  for(inti=0;i<n_muestras; i++){
    voltaje_sensor = analogRead(A0)*(5.0/1023.0);
    corriente = corriente + (voltajesensor -2.5)/ sensibilidad;

  }
  corriente = coriente/n_muestras;
  return(corriente)
}

