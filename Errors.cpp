#include <stdio.h>
#include <assert.h>

#include "stack.h"
#include "colours.h"
#include "errors.h"
#include "utility/log.h"
#include "utility/Utility.h"


StkError NotNull( stack* stk, const char* filename, const char* function, const int line )
{
    assert( stk );
    assert( filename );
    assert( function );

    if ( stk->data )
    {
        printlg( "Attempt to initialize not ( NULL ) pointer in <%s> file, <%s> function, <%d> line\n",
                  filename, function, line );

        #ifndef NO_DEBUG
        printlg( "---| Variable |---\n" );
        print_metadata( stk );
        printlg( "Possible issues:\n"
                 "1) Initializer failure.\n"
                 "2) Ignoring destroying function.\n" );
        printlg( "------------------\n\n" );
        #endif

        fprintf( stderr, "Program exited with code - " RED "%d" reset " ( NOT_NULL_INIT )\n"
                             "Check log-file to learn more about failure\n\n", NOT_NULL_INIT );
        return NOT_NULL_INIT;
    }
    return Success;
}

StkError UnfType( stack* stk, const char* filename, const char* function, const int line )
{
    assert( stk );
    assert( filename );
    assert( function );

    if ( !GetType( stk->data ) )
    {
        printlg( "Unforeseen type in <%s> file, <%s> function, <%d> line\n",
                  filename, function, line );

        #ifndef NO_DEBUG
        printlg( "---| Variable |---\n" );
        print_metadata( stk );
        printlg( "Possible issues:\n"
                "1) Initializer failure.\n"
                "2) Incorrect typedef stack_data.\n" );
        printlg( "------------------\n\n" );
        #endif

        fprintf( stderr, "Program exited with code -" RED " %d" reset " ( UNFORSEEN_TYPE )\n"
                         "Check log-file to learn more about failure\n\n", UNFORESEEN_TYPE );
        return UNFORESEEN_TYPE;
    }

    return Success;
}

StkError MemoryLack( stack* stk, const char* filename, const char* function, const int line )
{
    assert( stk );
    assert( filename );
    assert( function );

    if ( !stk->data )
    {
        printlg( "Lack of memory in <%s> file, <%s> function, %d line\n",
                  __FILE__, __FUNCTION__, __LINE__ );

        #ifndef NO_DEBUG
        printlg( "---| Variable |---\n");
        print_metadata( stk );
        printlg( "Possible issues:\n"
                 "1) Incorrect pushing realization\n"
                 "2) Lack of memory, realloc can't find enough space\n\n"
                 "-------------------\n\n" );
        #endif

        fprintf( stderr, "Code exited with code " RED "%d" reset " ( MEMORY_LACK )\n"
                         "To learn more, check log-file\n\n", MEMORY_LACK );
        return MEMORY_LACK;
    }
    return Success;
}

StkError StackUnderflw( stack* stk, const char* filename, const char* function, const int line )
{
    assert( stk );
    assert( filename );
    assert( function );

    if ( !stk->size )
    {
        printlg( "STACK_UNDERFLOW in <%s> file, <%s> function, %d line\n",
                 filename, function, line );
        printlg( "--| Variable |---\n");
        print_metadata( stk );
        printlg( "Possible issue:\n"
                 "Incorrect logic\n"
                 "-----------------\n\n" );
        fprintf( stderr, "Code exited with code " RED "%d" reset " ( STACK_UNDERFLOW )\n"
                         "To learn more, check log - file\n\n", STACK_UNDERFLOW );
        return STACK_UNDERFLOW;
    }
    return Success;
}

StkError incorrect_dimension( stack* stk, const char* filename, const char* function, const int line )
{
    assert( stk );
    assert( filename );
    assert( function );

    if ( stk->size < 0 || stk-> capacity < 0 )
    {
        printlg( "INCORRECT_DIMENSIONS in <%s> file, <%s> func, %d line\n", filename, function, line );
        printlg( "---| Dimensions |---\n" );
        printlg( "size == <%d>\n"
                 "capacity = <%d>\n"
                 "Possible issues:\n"
                 "1) Incorrect push/pop indexation\n"
                 "2) Incorrect initializer\n"
                 "---------------------\n\n" );

        fprintf( stderr, "Program exited with code - " RED "%d" reset " ( INCORRECT_DIMENSIONS )\n"
                         "Check log - file to learn more\n", INCORRECT_DIMENSIONS );
        return INCORRECT_DIMENSIONS;
    }
    return Success;
}

StkError null_pointer( stack* stk, const char* filename, const char* function, const int line )
{
    assert( stk );
    assert( filename );
    assert( function );

    if ( !stk->data )
    {
        printlg( "Null pointer in <%s> file, <%s> function, <%d> line\n", filename, function, line );
        printlg( "---| Variable |---\n" );
        print_metadata( stk );
        printlg( "Possible issues:\n"
                 "1) Initializer failure.\n"
                 "2) Incorrect struct build.\n"
                 "3) Memory overflow, check pushing and pulling func" );
        printlg( "------------------\n\n" );

        fprintf( stderr, "Program exited with code - " RED "%d" reset " ( NULLPTR )\n"
                         "Check log-file to learn more about failure\n\n", NULLPTR );
        return NULLPTR;
    }
    return Success;
}

StkError stack_overflow( stack* stk, const char* filename, const char* function, const int line )
{
    assert( stk );
    assert( filename );
    assert( function );

    if ( stk->size + 1 > stk->capacity )
    {

        printlg( "STACK_OVERFLOW in <%s> file, <%s> func, %d line\n", filename, function, line );
        printlg( "---| Variable |---\n");
        print_metadata( stk );
        printlg( "Possible issues:"
                 "1) Incorrect push/pop func\n"
                 "2) Incorrect initializer\n" );
        printlg( "------------------\n\n" );

        fprintf( stderr, "Program exited with code - " RED "%d" reset " ( STACK_OVERFLOW )\n"
                         "Check log- file to learn more about failure\n\n", STACK_OVERFLOW );
        return STACK_OVERFLOW;
    }
    return Success;
}
