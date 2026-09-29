#include <stdio.h>

#include "config.h"
#include "stack.h"
#include "utility/log.h"
#include "utility/Utility.h"


void Pollute( stack_data** size )
{
    *size = NULL;
}

int main()
{

    logger_open();
    stack temp = {};
    stack_init( &temp, 10 );

    for ( int i = 0; i < 20; i++ )
    {
        fprintf( stderr, "%d\n", i );
        stack_push( &temp, i * i );
       if ( i == 13 )
            Pollute( &temp.data );
    }

    for ( int i = 0; i < 21; i++ )
        stack_pop( &temp );
    stack_destr( &temp );

    logger_close();
    return 0;
}
