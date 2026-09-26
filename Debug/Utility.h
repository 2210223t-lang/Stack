#pragma once

#include <stdio.h>

#define $RT fprintf( stderr, "\e[0;95m RTRTRTRTRTRT!!!!!\n\e[0m" );

void puts_debug( const char* a, FILE* ostream );
