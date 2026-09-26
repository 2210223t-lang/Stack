#include <stdio.h>
#include <assert.h>

#include "Utility.h"

void puts_debug( const char* a, FILE* ostream )
{
    assert( ostream );

    while ( *a != '\n' && *a )

        switch ( *a )
        {
            case '\n':
                printf ( "\\n" );
                a++;
                break;

            case '\a':
                printf ( "\\a" );
                a++;
                break;

            case '\t':
                printf ( "\\t" );
                a++;
                break;

            case '\b':
                printf ( "\\b" );
                a++;
                break;

            case '\r':
                printf ( "\\r" );
                a++;
                break;

            default:
                putc( *( a++ ), ostream );
                break;
        }

    putc( '\n', ostream );
}
