#pragma once

#include "../stack.h"

#define logger_name "log"//< Standard log-file name

/**
 * @brief Changes output stream to a lo - file
 */
int logger_open();

/**
 * @brief fprintf( logger_stream ) realization
 */
void printlg( const char* text, ... );

/**
 * @brief Closes logger_stream and sets it to stderr
 */
void logger_close( void );

/**
 * @brief Prints stack status ( if's value ) into logger_stream
 */
void stack_status( stack* stk );

/**
 * @brief Prints stack variable metadata into logger_stream
 */
void print_metadata( stack* stk );

/**
 * @brief Debugging puts function
 */
void putslg_debug( const char* a );
