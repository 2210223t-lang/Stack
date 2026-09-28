#include <cstdio>
#include <stdio.h>
#include <stdarg.h>
#include <assert.h>
#include <stdlib.h>

#include "../stack.h"
#include "log.h"
#include "Utility.h"

static FILE* logger_stream = stderr;


int logger_open()
{

    logger_stream = fopen( ".log", "w" );
    return ( logger_stream ) ? 0 : -1;
}

void printlg( const char* text, ... )
{
    assert( text );

    va_list args;
    va_start( args, text );
    vfprintf( logger_stream, text, args );
    va_end( args );

    fflush( logger_stream );
}

void logger_close( void )
{
    if ( logger_stream != stderr )
        fclose( logger_stream );

    logger_stream = stderr;
}

void print_metadata( stack* stk )
{
    #ifndef NO_DEBUG

    printlg( "%s [ %p ] created by %s in %s:%d\n",
             stk->varname, stk, stk->function, stk->filename, stk->line );

    #endif
}

void stack_status( stack* stk )
{
    assert( stk );

    print_metadata( stk );

    printlg( "size == %d\n",     stk->size     );
    printlg( "capacity == %d\n", stk->capacity );
    printlg( "data == %p\n",     stk->data     );

    for ( int i = 0; i < stk->size; i++ )
    {
        printlg( "\n*-> [ %2d ] == ", i );
        UniPrint( stk, i );
    }

    for ( int i = stk->size + 1; i < stk->capacity; i++ )
        printlg( "\n    [ %2d ] == 666 ( FARFETCH )", i );


    printlg( "\n" );
}

void putslg_debug( const char* a )
{

    while ( *a != '\n' && *a )

        switch ( *a )
        {
            case '\n':
                printlg ( "\\n" );
                a++;
                break;

            case '\a':
                printlg( "\\a" );
                a++;
                break;

            case '\t':
                printlg( "\\t" );
                a++;
                break;

            case '\b':
                printlg( "\\b" );
                a++;
                break;

            case '\r':
                printlg( "\\r" );
                a++;
                break;

            default:
                printlg ( "%s", *( a++ ) );
                break;
        };
}
