#pragma once

// #define NO_DEBUG


typedef int stack_data; ///Defines type of data, which stack work with
#define ESCAPE "%d"

#ifndef NO_DEBUG

#define ON_DEBUG( ... ) __VA_ARGS__

#define stack_init( stk, capacity ) StackIni( stk, capacity, #stk, __FILE__, __func__, __LINE__ )

#define stack_check( stk ) STACK_CHECK( stk, __FILE__, __func__, __LINE__ )

#else

#define ON_DEBUG( ... )

#define stack_check( stk ) 0

#define stack_init( stk, capacity ) StackIni( stk, capacity )

#endif

#define not_null( stk ) NotNull( stk, __FILE__, __FUNCTION__, __LINE__ )
#define unforeseen_type( stk ) UnfType( stk, __FILE__, __FUNCTION__, __LINE__ )
#define lack_of_memory( stk, backup_stk ) MemoryLack( stk, backup_stk, __FILE__, __FUNCTION__, __LINE__ )
#define stack_underflow( stk ) StackUnderflw( stk, __FILE__, __FUNCTION__, __LINE__ )
