#include <stdio.h>

#include "config.h"
#include "stack.h"
#include "utility/log.h"
#include "utility/Utility.h"


int main()
{

    logger_open();
    stack a = {};
    stack_init( &a, 5 );

    for ( int i = 0; i < 20; i++ )
    {
        fprintf( stderr, "%d\n", i );
        stack_push( &a, i * i );
        if ( i == 13 )
            stack_status( &a );

    }

    for ( int i = 0; i < 21; i++ )
        stack_pop( &a );
    stack_destr( &a );

    logger_close();
    return 0;
}
