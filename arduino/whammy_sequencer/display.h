#ifndef DISPLAY_H
#define DISPLAY_H

#include <LedControl.h> //  need the patched library

#define DISPLAY1 0
#define DISPLAY2 1

#define SCREEN_SPLASH 0
#define SCREEN_PRESET 1
#define SCREEN_TEMPO 2
#define SCREEN_PLAY 3
#define SCREEN_SETTINGS 4
#define SCREEN_SELECT_PRESET 5
extern byte current_screen;
#define SCREEN_DELAY 3000
extern unsigned long t_tempo;
#define ANIM_DELAY 50

extern LedControl lc;

void dinit( int display );
void dprint( int display, const char *msg );
void dprintd( int display, const char *msg, int num );
void dprintn( int display, int num );

#endif
