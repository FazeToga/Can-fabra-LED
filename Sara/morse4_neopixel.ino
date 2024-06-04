#include <FastLED.h>

int duracionPunto = 500;
int duracionRaya = duracionPunto*3;

#define NUM_LEDS 120
#define DATA_PIN 8

CRGB leds[NUM_LEDS];

void setup() {
 pinMode(LED_BUILTIN, OUTPUT);
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
 Serial.begin(9600);
}

void puntoMorse() {
  leds[0] = CRGB::Red;
  FastLED.show();
  Serial.println(".");  
  delay(duracionPunto);                      
  leds[0] = CRGB::Black;
  FastLED.show(); 
  delay(duracionPunto); 
}
void rayaMorse() {
  leds[0] = CRGB::Blue;
  FastLED.show();
  Serial.println("_");  
  delay(duracionRaya);                      
  leds[0] = CRGB::Black;
  FastLED.show(); 
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
