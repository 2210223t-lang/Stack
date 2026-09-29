#include <assert.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

#include "errors.h"
#include "config.h"
#include "utility/log.h"
#include "stack.h"
#include "utility/Utility.h"


void StackIni( stack* stk,       int   capacity
                ON_DEBUG(, const char*  varname,
                           const char* filename,
                           const char* function,
                           const int       line
                           /*stack_save     calls*/ ) )
{
    assert( stk );
    int status = 0;
    init_info( stk ON_DEBUG(, varname, filename, function, line ) );

    status = not_null( stk );
    assert( !status );

    status = unforeseen_type( stk );
    assert( !status );

    stack backup = *stk;

    stk->capacity = capacity;

    status = incorrect_dimension( stk, __FILE__, __FUNCTION__, __LINE__ );
    assert( !status );
    stk->data = ( stack_data* ) calloc( capacity, sizeof( stack_data ) );
    stk->size = 0;

    status = lack_of_memory( stk, &backup );
    assert( !status );

    #ifndef NO_DEBUG
//         calls.processes[ 0 ] = 0;
//         calls.values[ 0 ] = -1;
//
//         for ( int i = 1; i < 3; i++ )
//         {
//             calls.processes[ i ] = -1;
//             calls.values   [ i ] = -1;
//         }
        printlg( "---| Variable initialized |---\n");
        print_metadata( stk );
        printlg( "------------------------------\n\n");
        assert( stk->data );
    #endif // NO_DEBUG

    assert( !stack_check( stk ) );
}

void stack_destr( stack* stk )
{
    if ( stk->data )
    {
        free( stk->data );
    }

    #ifndef NO_DEBUG
        printlg( "---| Destroyed variable |---\n" );
        print_metadata( stk );
        printlg( "----------------------------\n\n" );
    #endif // NO_DEBUG
}

void stack_push( stack* stk, stack_data temp )
{
    assert( stk );
    assert( !stack_check( stk ) );

    stack backup = *stk;
    int status = 0;

    if ( stk->capacity == stk->size + 1 )
    {
        stk->capacity *= 2;
        stk->data = ( stack_data* ) realloc( stk->data, sizeof( stack_data ) * stk->capacity );

        status = lack_of_memory( stk, &backup );
        if ( status )
            abort();
    }

    stk->data[ stk->size ] = temp;
    stk->size++;


    assert( !stack_check( stk ) );
    ChangeSave( stk, Pushing, temp );

    #ifndef NO_DEBUG
        printlg( "Pushing success\n"
                 "---| Pushed variable |---\n" );
        print_metadata ( stk );

        if ( backup.capacity != stk->capacity )
            printlg( "Capacity change: [ %d ]->[ %d ]\n", backup, stk->capacity );
        else
            printlg( "Without changing capacity\n");

        printlg( "Initialized value: ");
        UniPrint( stk, stk->size - 1 );
        printlg( "\n-------------------------\n\n" );
    #endif

}

stack_data stack_pop( stack* stk )
{
    assert( stk );
    assert( !stack_check( stk ) );

    int status = stack_underflow( stk );
    assert( !status );

    int backup = stk->capacity;
    stack temp = *stk;

    stk->data[ stk->size - 1 ] = 0;
    stk->size--;

    assert( !stack_check( stk ) );

    if ( stk->size + 1 < stk->capacity / 4 )
    {
        stk->capacity /= 4;
        stk->data = ( stack_data* ) realloc( stk->data, sizeof( stack_data ) * stk->capacity );
        assert( stk->data );
    }

    assert( !stack_check( stk ) );
    // ChangeSave( stk, Pop,)
    #ifndef NO_DEBUG
        printlg( "Popping success\n"
                 "---| Variable |---\n" );
        print_metadata( stk );

        if ( stk->capacity != backup )
            printlg( "Capacity changed: [ %d ]->[ %d ]\n" );
        else
            printlg( "Without changing capacity\n" );

        printlg( "Popped value: ");
        UniPrint( &temp, stk->size );
        printlg( "\n------------------\n\n" );
    #endif


    return temp.data[ stk->size ] ;
}

void init_info( stack* stk ON_DEBUG(,  const char*  varname,
                                       const char* filename,
                                       const char* function,
                                       const   int     line ) )
{
    assert( stk );

    #ifndef NO_DEBUG

    stk->varname  =  varname;
    stk->filename = filename;
    stk->function = function;
    stk->line = line;

    #endif // NO_DEBUG
}

StkError STACK_CHECK( stack* stk, const char* file_call, const char* func_call, const int line_call )
{
    assert( stk );

    StkError status = Success;

    status = null_pointer( stk, file_call, func_call, line_call );

    if ( status )
        return status;

    status = incorrect_dimension( stk, file_call, func_call, line_call );

    if ( status )
        return status;

    status = stack_overflow( stk, file_call, func_call, line_call );

    return status;
}

void ChangeSave( stack* stk, int newcall, stack_data newvalue )
{
    stk->calls.processes[ 2 ] = stk->calls.processes[ 1 ];
    stk->calls.processes[ 1 ] = stk->calls.processes[ 0 ];
    stk->calls.processes[ 0 ] = newcall;

    stk->calls.values[ 2 ] = stk->calls.values[ 1 ];
    stk->calls.values[ 1 ] = stk->calls.values[ 0 ];
    stk->calls.values[ 0 ] = newvalue;
}
