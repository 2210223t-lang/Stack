#pragma once

#include "config.h"

enum FuncCode
{
      Initialization = 0,
      Pushing = 1,
      Popping = 2,
};

#include "utility/errors.h"

void stack_destr( stack* stk );
void StackIni( stack* stk,       int   capacity
                ON_DEBUG(, const char*  varname,
                           const char* filename,
                           const char* function,
                           const int       line ) );
                        //    stack_save     calls ) );
void stack_push( stack* stk, stack_data temp );
stack_data stack_pop( stack* stk );
void init_info( stack* stk1 ON_DEBUG(, const char*  varname,
                                       const char* filename,
                                       const char* function,
                                       const   int     line ) );
StkError STACK_CHECK( stack* stk, const char* file_call, const char* func_call, const int line_call );
void ChangeSave( stack* stk, int newcall, stack_data newvalue );
