#include <FastLED.h>
#define DATA_PIN 11
#define NUM_LEDS 120
int valoresMensaje [NUM_LEDS];
CRGB leds[NUM_LEDS];
int cursor = 0;
String mensaje = "XACASAR";

void setup() {
 Serial.begin(9600);
 FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
 FastLED.setBrightness(60);
}

void loop() {
  if (Serial.available()){
    for (int i =0; i < NUM_LEDS; i++) {
      valoresMensaje[i]=1;
    }
    mensaje = Serial.readString();
    decidirValoresMensaje();
  }

iluminar();
}

void decidirValoresMensaje() {
   for (int i = 0; i < mensaje.length(); i++)  {
    switch (mensaje[i]){
      case 'A':
        morseA();
        break;
      case 'C':
        morseC();
        break;
      case 'R':
        morseR();
        break;
      case 'S':
        morseS();
        break;
      case 'X':
        morseX();
        break;
    }
   }
   
   cursor = 0;
 }

void morsePunto() {
  valoresMensaje[cursor] = 2;
  cursor ++;
  morseEspacio();
  
}
void morseEspacio(){
  valoresMensaje[cursor] = 1;
  cursor ++;
}

void morseRaya() {
  valoresMensaje[cursor] = 0;
  cursor ++;
  morseEspacio();

}

void morseA() {
  morsePunto();
  morseRaya();
  morseEspacio();

}

void morseS() {
  morsePunto();
  morsePunto();
  morsePunto();
  morseEspacio();

}

void morseR() {
  morseRaya();
  morsePunto();
  morseRaya();
  morseEspacio();
}
void morseC() {
  morseRaya();
  morsePunto();
  morseRaya();
  morsePunto();
  morseEspacio();
}
void morseX() {
  morseRaya();
  morsePunto();
  morsePunto();
  morseRaya();
  morseEspacio();
}

void iluminar() {
  for (int n=0;n <NUM_LEDS; n++) {
  if (valoresMensaje [n] ==0) {
    leds [n] = CRGB::Red;
  }
  else if (valoresMensaje [n] ==1) {
  leds [n] = CRGB:: Black;
  }
  else {
    leds [n] = CRGB:: White;
  }
}
FastLED.show();
delay(1000);
FastLED.clear();
FastLED.show();
delay(500);
}

