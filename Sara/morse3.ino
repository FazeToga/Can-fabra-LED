int duracionPunto = 500;
int duracionRaya = duracionPunto*3;

void setup() {
 pinMode(LED_BUILTIN, OUTPUT);
 Serial.begin(9600);
}

void puntoMorse() {
  digitalWrite(LED_BUILTIN, HIGH); 
  Serial.println(".");  
  delay(duracionPunto);                      
  digitalWrite(LED_BUILTIN, LOW);  
  delay(duracionPunto); 
}
void rayaMorse() {
  digitalWrite(LED_BUILTIN, HIGH); 
  Serial.println("_");   
  delay(duracionRaya);                      
  digitalWrite(LED_BUILTIN, LOW);  
  delay(duracionPunto); 
}



void loop() {
 if(Serial.available()) {
  String message = Serial.readString();
  Serial.println(message);
  procesarMensaje(message);
  }
}

void procesarMensaje(String message) {
      for(int i = 0; i< message.length(); i++) {
      Serial.println(message[i]);
      if(message[i]=='a') {
        morseA();}
      if(message[i]=='r') {
        morseR();}
      if(message[i]=='s') {
        morseS();
      }
    }
}
  
void morseA(){
  puntoMorse();
  rayaMorse();
  delay(duracionPunto*2);  
  
}
void morseS(){
  puntoMorse();
  puntoMorse();
  puntoMorse();
  delay(duracionPunto*2);
}

void morseR(){
  puntoMorse();
  rayaMorse();
  puntoMorse();
  delay(duracionPunto*2);
}
