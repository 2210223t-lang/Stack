#include <stdio.h>
#include <cstdint>
#include <string.h>
#include <assert.h>

#include "../config.h"



uint64_t hash_djb2( unsigned char *str, size_t size )
{
    uint64_t hash = 5381;

    for ( size_t i = 0; i < size; i++ )
        hash = ( ( hash << 5 ) + hash ) + *( str++ ); /* hash * 33 + c */

    return hash;
}

uint64_t Hash_Calc( stack* stk )
{
    assert( stk );
    assert( stk->data );
    #ifndef NO_DEBUG
    assert( stk->filename );
    assert( stk->function );
    assert( stk->varname );
    #endif

    uint64_t hash = hash_djb2( ( unsigned char* ) &stk->pyrrhuloxia1, sizeof( stk->pyrrhuloxia1 ) );
             hash = hash_djb2( ( unsigned char* ) &stk->pyrrhuloxia2, sizeof( stk->pyrrhuloxia2 ) );
             hash = hash_djb2( ( unsigned char* ) &stk->size,         sizeof( stk->size ) );
             hash = hash_djb2( ( unsigned char* ) &stk->capacity,     sizeof( stk->capacity ) );
             hash = hash_djb2( ( unsigned char* ) &stk->data,         sizeof( stk->data ) );
             hash = hash_djb2( ( unsigned char* ) stk->data + 8, stk->size * sizeof( stack_data ) );

    #ifndef NO_DEBUG
    hash = ( ( hash << 5 ) + hash ) + hash_djb2( ( unsigned char* ) stk->function,  strlen( stk->function ) );
    hash = ( ( hash << 5 ) + hash ) + hash_djb2( ( unsigned char* ) &stk->function, sizeof( stk->function ) );
    hash = ( ( hash << 5 ) + hash ) + hash_djb2( ( unsigned char* ) &stk->filename, sizeof( stk->filename ) );
    hash = ( ( hash << 5 ) + hash ) + hash_djb2( ( unsigned char* ) &stk->line,     sizeof( stk->line ) );
    hash = ( ( hash << 5 ) + hash ) + hash_djb2( ( unsigned char* ) stk->filename,  strlen( stk->filename ) );
    hash = ( ( hash << 5 ) + hash ) + hash_djb2( ( unsigned char* ) stk->varname,   strlen( stk->varname ) );
    hash = ( ( hash << 5 ) + hash ) + hash_djb2( ( unsigned char* ) &stk->filename, sizeof( stk->filename ) );
    #endif

    return hash;
}
