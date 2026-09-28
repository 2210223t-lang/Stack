#pragma once

#include "config.h"

enum StkError
{
    Success = 0,
    NULLPTR = 411,
    STACK_OVERFLOW = 412,
    INCORRECT_DIMENSIONS = 413,
    UNFORESEEN_TYPE = 414,
    UNIPRINT_FAILURE = 415,
    NOT_NULL_INIT,

};

struct stack
{
    ON_DEBUG( const char*  varname;
              const char* filename;
              const char* function;
                    int       line; );
              stack_data*     data;
              int             size;
              int         capacity;
};

void stack_destr( stack* stk );
void StackIni( stack* stk,       int   capacity
                ON_DEBUG(, const char*  varname,
                           const char* filename,
                           const char* function,
                           const int       line ) );
void stack_push( stack* stk, stack_data temp );
stack_data stack_pop( stack* stk );
void init_info( stack* stk1 ON_DEBUG(, const char*  varname,
                                       const char* filename,
                                       const char* function,
                                       const   int     line ) );
StkError STACK_CHECK( stack* stk, const char* file_call, const char* func_call, const int line_call );
