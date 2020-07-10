//#include <MIDIUSB.h>
/* Pinout for setup

5 buttons (24,26,28,30,32)

5 pots (A0-A4)

5 buttons (digital 3-7)

5 pots (A5-A9)

*/
//Items
const int Botones = 10;
const int Potenciometros = 10;

// Pins

int pots[Potenciometros]={A0, A1, A2, A3, A4, A5, A6, A7, A8, A9};
int btns[Botones]={3, 4, 5, 6, 7, 24, 26, 28, 30, 32};

// Values storage

float potState[Potenciometros]={};
boolean btnsState[Botones]={};



void setup() {
  Serial.begin(31250);
  
  for(int i=0; i<=Botones; i++){ 
  pinMode(pots[i], INPUT);
  pinMode(btns[i], INPUT);
  }
  
}

void loop() {
  readState();
  for(int i=0; i<Botones; i++){
  Serial.print(potState[i]);
  Serial.println(btnsState[i]);
  }
  delay(100);

}


void readState(){
  for(int i=0; i<=Botones; i++){
    potState[i]=analogRead(pots[i]);
    btnsState[i]=digitalRead(pots[i]);
  }
  
}


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
