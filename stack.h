#pragma once

#include "config.h"
#include "utility/errors.h"

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

int StackIniDesc( int* desc, int capacity
                   ON_DEBUG(, const char*  varname,
                              const char* filename,
                              const char* function,
                              const int       line ) );
void stack_pop_desc( int desc );
void stack_push_desc( int desc, stack_data temp );
void stack_destr_desc( int* desc );
