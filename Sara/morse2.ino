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
  if(message == "a\n") {
    morseA();
  }
  else if (message == "s\n") {
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
