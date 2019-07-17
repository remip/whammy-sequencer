#include "display.h"
#include <arduino.h>

/*
 * Initalize display
 */
void dinit( int display )
{
    lc.shutdown( display, false ); // turn off power saving, enables display
    lc.setIntensity( display, 8 ); // sets brightness (0~15 possible values)
    lc.clearDisplay( display );    // clear screen
}

void dprint( int display, const char *msg )
{
    for ( int i = 0; i < 8; i++ )
    {
        char c;
        if ( i < strlen( msg ) )
            c = msg[i];
        else
            c = ' ';

        lc.setChar( display, 7 - i, c, false );
    }
}

void dprintd( int display, const char *msg, int num )
{
    for ( int i = 0; i < 6; i++ )
    {
        char c;
        if ( i < strlen( msg ) )
            c = msg[i];
        else
            c = ' ';

        lc.setChar( display, 7 - i, c, false );
    }

    int r;

    r   = num / 10;
    num = num - r * 10;
    lc.setChar( display, 1, char( r ), false );

    lc.setChar( display, 0, char( num ), false );
}

void dprintn( int display, int num )
{
    int r;

    for ( int i = 0; i < 5; i++ )
    {
        lc.setChar( display, 7 - i, ' ', false );
    }

    r   = num / 100;
    num = num - r * 100;
    lc.setChar( display, 2, char( r ), false );

    r   = num / 10;
    num = num - r * 10;
    lc.setChar( display, 1, char( r ), false );

    lc.setChar( display, 0, char( num ), false );
}
