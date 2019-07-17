#ifndef BUTTONS_H
#define BUTTONS_H

#include <AceButton.h>
#include <Encoder.h>
using namespace ace_button;

extern ButtonConfig buttonConfig;

extern AceButton buttonLeft;
extern AceButton buttonRight;

extern Encoder knob1;
extern Encoder knob2;

extern bool button2_pressed;
extern bool button2_released;
extern bool button1_pressed;
extern bool button1_released;
extern bool button1_long;

extern long knob1pos;
extern long knob2pos;
extern long knob1new, knob2new;

void handleEvent( AceButton *button, uint8_t eventType, uint8_t buttonState );
void check_buttons( void );

#endif
