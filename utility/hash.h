#pragma once
#include <stdio.h>
#include <stdint.h>

#include "../config.h"


/**
 * @brief Hashs stk variable with one of algorithms
 */
uint64_t Hash_Calc( stack* stk );

uint64_t hash_djb2( unsigned char* str, size_t size );
