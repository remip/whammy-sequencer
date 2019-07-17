#include "buttons.h"
#include "display.h"
#include "midi.h"
#include "pitches.h"
#include "presets.h"

/*
 *
 *  --------------------
 *  -    DISPLAY 1     -
 *  -    DISPLAY 2     -
 *  -                  -
 *  -       knob1 O    -
 *  -       knob2 O    -
 *  - button1  button2 -
 *  -  O          O    -
 *  --------------------
 *
 *
 *
 */

/* TODO
 *  - settings type whammy
 *  - settings true bypass
 *  - preset en PROGMEM
 *  - tap tempo
 *  - "vraie" courbe de pédale
 */

#define PIN_MIDI_RX 2
#define PIN_MIDI_TX 3
#define PIN_DISPLAY_DATA 12
#define PIN_DISPLAY_CLK 11
#define PIN_DISPLAY_LOAD 10
#define PIN_BUTTON_1 4
#define PIN_BUTTON_2 5
#define PIN_KNOB_1_PIN1 7
#define PIN_KNOB_1_PIN2 6
#define PIN_KNOB_2_PIN1 9
#define PIN_KNOB_2_PIN2 8

#define MODE_PLAY 0
#define MODE_PRESET 1
#define MODE_SETTINGS 2

byte          current_screen = SCREEN_PRESET;
unsigned long t_tempo        = 0;

byte          mode           = MODE_PLAY;
bool          playing        = false;
byte          current_preset = 0;
int           preset_direction = 1;
byte          current_step   = 0;
byte          step           = 0;
byte          type           = 0;
unsigned long tempo          = 120;
#define MAX_TEMPO 260
#define MIN_TEMPO 40
unsigned long last_time = 0;
char          buffer[9]; // used for copy PROGMEM to SRAM (8 char max)

LedControl lc = LedControl( PIN_DISPLAY_DATA, PIN_DISPLAY_CLK, PIN_DISPLAY_LOAD,
                            2 ); // lc is our object
// pin 12 is connected to the DATA IN  pin 1
// pin 11 is connected to the CLK pin 13
// pin 10 is connected to LOAD/CS pin 12
// 2 as we are  using 2 MAX7219

SoftwareSerial midiOut( PIN_MIDI_RX, PIN_MIDI_TX ); // RX, TX ;
ButtonConfig   buttonConfig;
AceButton      buttonLeft;
AceButton      buttonRight;
bool           button2_pressed  = false;
bool           button2_released = false;
bool           button1_pressed    = false;
bool           button1_released   = false;
bool           button1_long       = false;

long knob1pos = 0;
long knob2pos = 0;
long knob1new, knob2new;

Encoder knob1( PIN_KNOB_1_PIN1, PIN_KNOB_1_PIN2 );
Encoder knob2( PIN_KNOB_2_PIN1, PIN_KNOB_2_PIN2 );

void stop( void )
{
    playing = false;
    /* buffered */
    whammy( pgm_read_word( &( pitches[P_UNISON].prog ) ),
            pgm_read_word( &( pitches[P_UNISON].cc ) ) );
    /* true bypass  */
    // whammy(pgm_read_word(&(pitches[BYPASS].prog)),
    // pgm_read_word(&(pitches[BYPASS].cc)));
}

void setup()
{
    // init the 2 displays
    dinit( DISPLAY1 );
    dinit( DISPLAY2 );

    // init midi serial port
    midiOut.begin( 31250 );

    // init USB serial debug
    Serial.begin( 9600 );

    buttonConfig.setEventHandler( handleEvent );
    buttonConfig.setFeature( ButtonConfig::kFeatureClick );
    buttonConfig.setFeature( ButtonConfig::kFeatureLongPress );

    pinMode( PIN_BUTTON_1, INPUT );
    pinMode( PIN_BUTTON_2, INPUT );

    buttonLeft.setButtonConfig( &buttonConfig );
    buttonLeft.init( PIN_BUTTON_1, LOW, 0 /* id */ );
    buttonRight.setButtonConfig( &buttonConfig );
    buttonRight.init( PIN_BUTTON_2, LOW, 1 /* id */ );

    Serial.println( F( "Whammy Sequencer" ) );

    byte prog = pgm_read_word( &( pitches[P_UNISON].prog ) );
    Serial.print( "prog: " );
    Serial.println( prog );
    byte cc = pgm_read_word( &( pitches[P_UNISON].cc ) );
    Serial.print( "cc: " );
    Serial.println( cc );

    step = P_2OCT;
    strcpy_P( buffer, (char *)pgm_read_word( &( pitches[step].name ) ) );
    Serial.print( "name: " );
    Serial.println( buffer );

    stop(); // bypass

    printScreen( SCREEN_SPLASH );
    printScreen( SCREEN_PRESET );
}

void setPreset( byte num )
{
    if ( num != current_preset )
    {
        current_preset = num, current_step = 0;
        stop();
        printScreen( SCREEN_PRESET );
    }
}

void printScreen( byte type )
{
    current_screen = type;
    switch ( type )
    {
    case SCREEN_SPLASH:
        dprint( DISPLAY2, "E" );
        delay( ANIM_DELAY );
        dprint( DISPLAY2, "CE" );
        delay( ANIM_DELAY );
        dprint( DISPLAY1, "Y" );
        dprint( DISPLAY2, "NCE" );
        delay( ANIM_DELAY );
        dprint( DISPLAY1, "MY" );
        dprint( DISPLAY2, "ENCE" );
        delay( ANIM_DELAY );
        dprint( DISPLAY1, "MMY" );
        dprint( DISPLAY2, "UENCE" );
        delay( ANIM_DELAY );
        dprint( DISPLAY1, "AMMY" );
        dprint( DISPLAY2, "QUENCE" );
        delay( ANIM_DELAY );
        dprint( DISPLAY1, "HAMMY" );
        dprint( DISPLAY2, "EQUENCE" );
        delay( ANIM_DELAY );
        dprint( DISPLAY1, "WHAMMY" );
        dprint( DISPLAY2, "SEQUENCE" );
        delay( ANIM_DELAY );
        dprint( DISPLAY1, " WHAMMY" );
        dprint( DISPLAY2, "EQUENCER" );
        delay( ANIM_DELAY );
        delay( 2000 );
        break;
    case SCREEN_SELECT_PRESET:
        dprint( DISPLAY1, "SELECT" );
        dprint( DISPLAY2, "PRESET" );
        break;
    case SCREEN_PRESET:
        dprintd( DISPLAY1, "PGM", current_preset + 1 );
        dprint( DISPLAY2, presets[current_preset].name );
        break;
    case SCREEN_TEMPO:
        dprint( DISPLAY1, "Tempo" );
        dprintn( DISPLAY2, (int)tempo );
        t_tempo = millis();
        break;
    case SCREEN_PLAY:
        if ( millis() < SCREEN_DELAY + t_tempo )
            break;
        strcpy_P( buffer, (char *)pgm_read_word( &( pitches[step].name ) ) );
        dprintd( DISPLAY1, buffer, current_step + 1 );
        dprint( DISPLAY2, presets[current_preset].name );
        break;
    case SCREEN_SETTINGS:
        dprint( DISPLAY1, "SELECT" );
        dprint( DISPLAY2, "SETTINGS" );
        break;
    }
}

void change_preset(void)
{
    int preset = (int) current_preset + preset_direction;

    button1_pressed = false; // reset
    button1_long = false;
    
    if ( preset == PRESET_COUNT )
        preset = 0;
    else if ( preset == -1)
        preset = PRESET_COUNT - 1;        

    setPreset( preset );
}

void loop()
{

    check_buttons();

/*
    switch ( mode )
    {
    case MODE_PLAY:
        break;
    case MODE_PRESET:
        break;
    case MODE_SETTINGS:
        break;
    }
*/
    // knob1 -> preset
    if ( knob1new != knob1pos )
    {
        if ( knob1new > knob1pos && current_preset < PRESET_COUNT - 1 )
            setPreset( current_preset + 1 );
        else if ( knob1new < knob1pos && current_preset > 0 )
            setPreset( current_preset - 1 );
        knob1pos = knob1new;
    }
    // knob2 -> tempo
    if ( knob2new != knob2pos )
    {
        // update tempo
        if ( knob2new > knob2pos && tempo < MAX_TEMPO )
            tempo++;
        else if ( knob2new < knob2pos && tempo > MIN_TEMPO )
            tempo--;

        printScreen( SCREEN_TEMPO );
        knob2pos = knob2new;
    }

    if ( button1_pressed )
    {        
        change_preset();
    }
    if ( button1_long )
    {
        /* settings ?
        stop();
        printScreen( SCREEN_SELECT_PRESET );
        mode = MODE_PRESET;
        */

       preset_direction = - preset_direction;

       change_preset();

    }

    if ( mode == MODE_PRESET && current_screen == SCREEN_SELECT_PRESET &&
         button1_released )
    {
        // blink preset
    }

    // go back to preset screen
    if ( current_screen == SCREEN_TEMPO && millis() > SCREEN_DELAY + t_tempo )
        printScreen( SCREEN_PRESET );

    type                       = presets[current_preset].type;
    unsigned long current_time = millis();
    switch ( type )
    {
    case TYPE_SETTINGS:
    case TYPE_1_STEP:
    case TYPE_2_STEP:
        if ( button2_pressed || ( type == TYPE_2_STEP && button2_released ) )
        {
            button2_pressed  = false; // reset
            button2_released = false; // reset

            step = presets[current_preset].steps[current_step];

            printScreen( SCREEN_PLAY );
            whammy( pgm_read_word( &( pitches[step].prog ) ),
                    pgm_read_word( &( pitches[step].cc ) ) );

            if ( current_step < presets[current_preset].step_number - 1 )
                current_step++;
            else
                current_step = 0;
        }
        break;
    case TYPE_1_SHOT:
    case TYPE_TAP:
        if ( !playing && button2_pressed )
        {
            playing       = true;
            button2_pressed = false;
            current_step  = 0;
        }
        else if ( playing && button2_pressed )
        {
            button2_pressed = false;
            stop();
        }

        if ( playing )
        {
            if ( current_time - last_time >=
                 60000 / (unsigned long)presets[current_preset].note_value /
                     tempo )
            {
                last_time = current_time;

                step = presets[current_preset].steps[current_step];
                whammy( pgm_read_word( &( pitches[step].prog ) ),
                        pgm_read_word( &( pitches[step].cc ) ) );

                printScreen( SCREEN_PLAY );
                if ( current_step < presets[current_preset].step_number - 1 )
                    current_step++;
                else if ( type == TYPE_1_SHOT )
                    stop();
                else
                    current_step = 0;
            }
        }
        break;
    case TYPE_CLOCK:
        break;
    }
}
