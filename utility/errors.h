#pragma once

#include "../config.h"

enum StkError
{
    Success = 0,
    NULLPTR = 411,
    STACK_OVERFLOW = 412,
    INCORRECT_DIMENSIONS = 413,
    UNFORESEEN_TYPE = 414,
    UNIPRINT_FAILURE = 415,
    NOT_NULL_INIT = 416,
    DATA_SHRINKAGE = 417,
    STACK_UNDERFLOW = 418,
    MEMORY_LACK = 419,
    CANARY_FAULT = 420,

};

StkError NotNull( stack* stk, const char* filename, const char* function, const int line );
StkError UnfType( stack* stk, const char* filename, const char* function, const int line );
StkError MemoryLack( stack* stk, stack* backup_stk, const char* filename, const char* function, const int line );
StkError StackUnderflw( stack* stk, const char* filename, const char* function, const int line );
StkError incorrect_dimension( stack* stk, const char* filename, const char* function, const int line );
StkError null_pointer( stack* stk, const char* filename, const char* function, const int line );
StkError stack_overflow( stack* stk, const char* filename, const char* function, const int line );
StkError pyrrhuloxia_check( stack* stk, const char* filename, const char* function, const int line );
StkError IncorrectD( stack* stk, const char* filename, const char* function, const int line );
