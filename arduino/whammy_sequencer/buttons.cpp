#include "buttons.h"
#include <arduino.h>

void handleEvent( AceButton *button, uint8_t eventType, uint8_t buttonState )
{
    switch ( eventType )
    {
    case AceButton::kEventPressed:
        if ( button->getId() == 1 )
        {
            button2_pressed  = true;
            button2_released = false;
            Serial.println( F( "start pressed" ) );
        }
        else if ( button->getId() == 0 )
        {
            button1_pressed  = true;
            button1_released = false;
            Serial.println( F( "TAP pressed" ) );
        }
        break;
    case AceButton::kEventReleased:
        if ( button->getId() == 1 )
        {
            button2_pressed  = false;
            button2_released = true;
            Serial.println( F( "start released" ) );
        }
        else if ( button->getId() == 0 )
        {
            button1_pressed  = false;
            button1_released = true;
            Serial.println( F( "TAP released" ) );
        }
        break;
    case AceButton::kEventLongPressed:
        if ( button->getId() == 0 )
        {
            button1_pressed = false;
            button1_long    = true;
            Serial.println( F( "TAP long pressed" ) );
        }
    }
}

void check_buttons( void )
{
    // momentary buttons
    buttonLeft.check();
    buttonRight.check();

    // rotary buttons
    knob1new = knob1.read();
    knob2new = knob2.read();
}
