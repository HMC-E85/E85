// morse.c
// David_Harris@hmc.edu

// Arduino-like library for IO functions
#include "EasyNucleoIO.h"

#define DUR 100

// Define Morse code for letters
char codes[26][5] = {
 ".-",   // A
 "-...", // B
 "-.-.", // C
 "-..",  // D
 ".",    // E
 "..-.", // F
 "--.",  // G
 "....", // H
 "..",   // I
 ".---", // J
 "-.-",  // K
 ".-..", // L
 "--",   // M
 "-.",   // N
 "---",  // O
 ".--.", // P
 "--.-", // Q
 ".-.",  // R
 "...",  // S
 "-",    // T
 "..-",  // U
 "...-", // V
 ".--",  // W
 "-..-", // X
 "-.--", // Y
 "--.."  // Z 
};

void playChar(char c) {
	int i=0;
	
	while (codes[c-'A'][i]) {
	  digitalWrite(13, 1);
	  if (codes[c-'A'][i] == '.') delayLoop(DUR);   // dot
	  else                        delayLoop(3*DUR); // dash 
	  digitalWrite(13, 0);
	  delayLoop(DUR); // pause between elements
		i++;
	}
	delayLoop(DUR*2); // extra pause between characters
}
		
void playStr(char msg[]) {
	 int i=0;
	 
	 while(msg[i]) 
		 playChar(msg[i++]);
}

int main(void) {
	EasyNucleoIOInit();
	pinMode(13, OUTPUT); // Green LED on board
	while (1) {
	  playStr("SOS");
		delayLoop(DUR*4); // extra pause between words
  }
}