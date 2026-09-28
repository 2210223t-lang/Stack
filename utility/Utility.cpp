#include <stdio.h>
#include <assert.h>

#include "../config.h"
#include "Utility.h"
#include "log.h"
#include "../stack.h"


int UniPrint( stack* stk, int index )
{
    int type = GetType( stk->data );

    switch ( type )
    {
        case INT_S:
            printlg( "%d", stk->data[ index ] );
            return Success;

        case UINT64_S:
            printlg( "%uld", stk->data[ index ] );
            return Success;

        case LONG_LONG_S:
            printlg( "%ld", stk->data[ index ] );
            return Success;

        case CHAR_S:
            printlg( "%c", stk->data[ index ] );
            return Success;

        case STRING_S:
            printlg( "%s", stk->data[ index ] );
            return Success;

        case FLOAT_S:
            printlg( "%f", stk->data[ index ] );
            return Success;

        case DOUBLE_S:
            printlg( "%lf", stk->data[ index ] );
            return Success;

        case SHORT_S:
            printlg( "%sd", stk->data[ index ] );
            return Success;

        case UINT32_S:
            printlg( "%ud", stk->data[ index ] );
            return Success;

        case UINT16_S:
            printlg( "%usd", stk->data[ index ] );
            return Success;

        case UNKNOWN:
            printlg( "Uniprint failure: unknown type\n" );
            return UNFORESEEN_TYPE;
    }

    return UNIPRINT_FAILURE;
}

int UniPrint2( stack* stk, int index )
{
    if ( index >= stk->size )
        return UNFORESEEN_TYPE;

    printlg( ESCAPE, stk->data[ index ] );
    return Success;
}
