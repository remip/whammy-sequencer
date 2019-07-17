#ifndef MIDI_H
#define MIDI_H

#include <SoftwareSerial.h>

extern SoftwareSerial midiOut;

void whammy(  byte prog, byte expr );

#endif
