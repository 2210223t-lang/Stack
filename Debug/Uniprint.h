#pragma once

#include "../stack.h"

enum TYPES
{
    FLOAT_S = 1,
    DOUBLE_S = 2,
    STRING_S = 3,
    INT_S = 4,
    LONG_LONG_S = 5,
    UINT64_S = 6,
    CHAR_S = 7,
    UNKNOWN = 8
};

#define GetType( variable ) _Generic( variable, float* : FLOAT_S, double* : DOUBLE_S, char** : STRING_S,\
                                                int* : INT_S, long long* : LONG_LONG_S, unsigned long long* : UINT64_S,\
                                                char* : CHAR_S, default : UNKNOWN )

StkError UniPrint( stack* stk );
