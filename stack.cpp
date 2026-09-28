#include <assert.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

#include "config.h"
#include "utility/log.h"
#include "stack.h"
#include "utility/Utility.h"


void StackIni( stack* stk,       int   capacity
                ON_DEBUG(, const char*  varname,
                           const char* filename,
                           const char* function,
                           const int       line ) )
{
    assert( stk );

    #ifndef NO_DEBUG
        if ( stk->data )
        {
            printlg( "Attempt to initialize not ( NULL ) pointer in <%s> file, <%s> function, <%d> line\n"
                     __FILE__, __FUNCTION__, __LINE__ );

            printlg( "---| Variable |---\n" );
            print_metadata( stk );
            printlg( "Possible issues:\n"
                    "1) Initializer failure.\n"
                    "2) Ignoring destroying function.\n" );
            printlg( "------------------\n\n" );

            fprintf( stderr, "Program exited with code - %d ( NOT_NULL_INIT )\n"
                             "Check log-file to learn more about failure\n\n", NOT_NULL_INIT );
            abort();
        }
        if ( !GetType( stk->data ) )
        {
            printlg( "Unforeseen type in <%s> file, <%s> function, <%d> line\n",
                     __FILE__, __FUNCTION__, __LINE__ );

            printlg( "---| Variable |---\n" );
            print_metadata( stk );
            printlg( "Possible issues:\n"
                    "1) Initializer failure.\n"
                    "2) Incorrect typedef stack_data.\n" );
            printlg( "------------------\n\n" );

            fprintf( stderr, "Program exited with code - %d ( UNFORSEEN_TYPE )\n"
                             "Check log-file to learn more about failure\n\n", UNFORESEEN_TYPE );
            abort();
        }
    #endif

    stk->capacity = capacity;
    stk->data = ( stack_data* ) calloc( capacity, sizeof( stack_data ) );
    stk->size = 0;

    #ifndef NO_DEBUG
        init_info( stk ON_DEBUG(, varname, filename, function, line ) );
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

    int backup = stk->capacity;

    if ( stk->capacity == stk->size + 1 )
    {
        stk->capacity *= 2;
        stk->data = ( stack_data* ) realloc( stk->data, sizeof( stack_data ) * stk->capacity );
        assert( stk->data );
    }

    stk->data[ stk->size ] = temp;
    stk->size++;

    assert( !stack_check( stk ) );
    #ifndef NO_DEBUG
        printlg( "---| Pushed variable |---\n" );
        print_metadata ( stk );

        if ( backup != stk->capacity )
            printlg( "Capacity change: [ %d ]->[ %d ]\n", backup, stk->capacity );
        else
            printlg( "Without changing capacity\n");

        printlg( "Initialized value: ");
        UniPrint( stk, stk->size - 1 );
        printlg( "\n\n" );
    #endif

}

stack_data stack_pop( stack* stk )
{
    assert( stk );
    assert( !stack_check( stk ) );

    if ( !stk->size )
    {
        printlg( "STACK_UNDERFLOW popping func\n" );
        printlg( "--| Variable |---\n");
        print_metadata( stk );
        printlg( "Possible issue:\n"
                 "Incorrect logic\n"
                 "-----------------\n\n" );

    }

    int backup = stk->capacity;
    stack_data temp = stk->data[ stk->size ];

    stk->data[ stk->size ] = 0;
    stk->size--;

    assert( !stack_check( stk ) );

    if ( stk->size + 1 < stk->capacity / 4 )
    {
        stk->capacity /= 4;
        stk->data = ( stack_data* ) realloc( stk->data, sizeof( stack_data ) * stk->capacity );
        assert( stk->data );
    }

    assert( !stack_check( stk ) );

    #ifndef NO_DEBUG
        printlg( "Popping success\n"
                 "---| Variable |---\n" );
        print_metadata( stk );

        if ( stk->capacity != backup )
            printlg( "Capacity changed: [ %d ]->[ %d ]\n" );
        else
            printlg( "Without changing capacity\n" );

        printlg( "Popped value: ");
        UniPrint( )
        printlg( "------------------\n\n" );
    #endif


    return temp;
}

void init_info( stack* stk ON_DEBUG(,  const char*  varname,
                                       const char* filename,
                                       const char* function,
                                       const   int     line ) )
{
    assert( stk );

    assert( !stack_check( stk ) );

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

    if ( !stk->data )
    {
        printlg( "Null pointer in <%s> file, <%s> function, <%d> line\n", file_call, func_call, line_call );
        printlg( "---| Variable |---\n" );
        print_metadata( stk );
        printlg( "Possible issues:\n"
                 "1) Initializer failure.\n"
                 "2) Incorrect struct build.\n"
                 "3) Memory overflow, check pushing and pulling func" );
        printlg( "------------------\n\n" );

        fprintf( stderr, "Program exited with code - %d ( NULLPTR )\n"
                         "Check log-file to learn more about failure\n\n", NULLPTR );
        return NULLPTR;
    }

    if ( stk->size < 0 || stk-> capacity < 0 )
    {
        printlg( "INCORRECT_DIMENSIONS in <%s> file, <%s> func, %d line\n", file_call, func_call, line_call );
        printlg( "---| Dimensions |---\n" );
        printlg( "size == <%d>\n"
                 "capacity = <%d>\n"
                 "Possible issues:\n"
                 "1) Incorrect push/pop indexation\n"
                 "2) Incorrect initializer\n"
                 "---------------------\n\n" );

        fprintf( stderr, "Program exited with code - %d ( INCORRECT_DIMENSIONS )\n"
                         "Check log - file to learn more\n", INCORRECT_DIMENSIONS );
    }

    if ( stk->size + 1 > stk->capacity )
    {

        printlg( "STACK_OVERFLOW in <%s> file, <%s> func, %d line\n", file_call, func_call, line_call );
        printlg( "---| Variable |---\n");
        print_metadata( stk );
        printlg( "Possible issues:"
                 "1) Incorrect push/pop func\n"
                 "2) Incorrect initializer\n" );
        printlg( "------------------\n\n" );

        fprintf( stderr, "Program exited with code - %d ( STACK_OVERFLOW )\n"
                         "Check log- file to learn more about failure\n\n", STACK_OVERFLOW );
        return STACK_OVERFLOW;
    }


    return Success;
}
