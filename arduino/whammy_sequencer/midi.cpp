#include <arduino.h>
#include "midi.h"

void whammy( byte prog, byte expr )
{
    midiOut.write( (uint8_t)0xC0 ); // TYPE: program change
    midiOut.write( (uint8_t)prog );
    midiOut.write( (uint8_t)0xB0 ); // TYPE: control change
    midiOut.write( (uint8_t)0x0B ); // CONTROLLER NUMBER 11: expression pedal
    midiOut.write( (uint8_t)expr );
}
