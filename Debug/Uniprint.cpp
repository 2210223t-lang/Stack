#include "log.h"
#include "Uniprint.h"
#include "../stack.h"

StkError UniPrint( stack* stk )
{
    int type = GetType( *( stk->data ) );

    switch ( type )
    {
        case INT_S:
            printlg( "RTRTRTRT\n" );
            break;

        case UNKNOWN:
            printlg( "|||||||\n");
            break;
    }

    return ( type != UNKNOWN ) ? Success : UNFORESEEN_TYPE;
}
