#include <Adafruit_NeoPixel.h>

//#include <MIDIUSB.h>


/* Pinout for setup

5 buttons (24,26,28,30,32)

5 pots (A0-A4)

5 buttons (digital 3-7)

5 pots (A5-A9)

*/
//Items
#define NUM_LEDS 18
#define LED_PIN 50
Adafruit_NeoPixel strip(NUM_LEDS, LED_PIN, NEO_GRB + NEO_KHZ800);
const int Botones = 10;
const int Potenciometros = 10;

// Pins
int pots[Potenciometros]={A0, A1, A2, A3, A4, A5, A6, A7, A8, A9};
int btns[Botones]={3, 4, 5, 6, 7, 24, 26, 28, 30, 32};

// Values storage

int potState[Potenciometros];
int btnsState[Botones];

void setup() {
  
  strip.begin();
  strip.show();
  strip.setBrightness(50);
  for(int i=0; i<=NUM_LEDS; i++) { 
    strip.setPixelColor(i, 255, 255, 255);                               
    delay(10);                           
  }
  strip.show(); 
  Serial.begin(115200);
  
  for(int i=0; i<=Botones; i++){ 
  pinMode(pots[i], INPUT_PULLUP);
  pinMode(btns[i], INPUT_PULLUP);
  }
  
}

void loop() {
  //for(int i=0; i<=Botones; i++){
  //Serial.print(analogRead(pots[i]));
  //Serial.print("\t");
  //Serial.print(!digitalRead(btns[i]));
  //Serial.print("\t");
  //} Serial.println("\t");
  //testing IO

  Serial.println(millis());
}

// int butState[Botones], lastButState[Botones] = {LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW, LOW}, reading[Botones] ;
// unsigned long lastDebounceTime[Botones]={0,0,0,0,0,0,0,0,0,0}, debounceDelay[Botones]={50,50,50,50,50,50,50,50,50,50}, imillis[Botones];

//void buttons(){
//  //Debounce implementation for each button
//  Serial.println(millis());
//  for(int i=0; i<=Botones; i++){
//    reading[i] = !digitalRead(btns[i]);
//    if(reading[i] != lastButState[i]){
//      lastDebounceTime[i] = millis();
//    }
//    if((millis() - lastDebounceTime[i]) > debounceDelay[i]){
//      if(reading[i] != butState[i]){
//        butState[i] = reading[i];
//        if(butState[i] == HIGH){
//          Serial.println(i);
//        }
//        lastButState[i] = reading[i];
//      }
//  }
//}
//}

/*
void noteOn(byte channel, byte pitch, byte velocity){
  
  midiEventPacket_t noteOn = {0x09, 0x90 | channel, pitch, velocity};
  MidiUSB.sendMIDI(noteOn);
  
}

void noteOff(byte channel, byte pitch, byte velocity){

  midiEventPacket_t noteOff = {0x08, 0x80 | channel, pitch, velocity};
  MidiUSB.sendMIDI(noteOff);
  
}

void controlChange(byte channel, byte control, byte value){
  midiEventPacket_t event = {0x0B, 0xB0 | channel, control, value};
  MidiUSB.sendMIDI(event);
}
*/
