#include <stdio.h>

#include "config.h"
#include "stack.h"
#include "utility/Utility.h"
#include "utility/log.h"


void pollute( stack* stk )
{
    uint64_t* canopy = ( uint64_t* ) ( ( uint64_t* ) stk->data + 1 + //TODO use ( char* ) with canopy calc
                       ( stk->capacity * sizeof( stack_data ) + 7 ) / sizeof( uint64_t ) );
    *canopy = 0;
}

int main()
{
    logger_open();
    stack temp = {};
    stack_init( &temp, 10 );

    for ( int i = 0; i < 20; i++ )
    {
        if ( i == 13 )
        {
            pollute( &temp );
            $RT;
        }
        stack_push( &temp, i * i );
        fprintf( stderr, "%d\n", i );
    }
    $RT
    for ( int i = 19; i >= 0; i-- )
    {
        fprintf( stderr, "%d\n", i );
        stack_pop( &temp );
    }

    logger_close();

}
