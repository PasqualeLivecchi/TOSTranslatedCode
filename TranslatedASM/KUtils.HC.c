#include "KUtils.HC.h"

U32 Bt( U32 bit_num, U8* bit_field )
{
    bit_field += bit_num >> 3;
    bit_num &= 7;
    return ( *bit_field & ( 1 << bit_num ) ) ? 1 : 0;
}

U32 Bts( U32 bit_num, U8* bit_field )
{
    U32 result;
    bit_field += bit_num >> 3;
    bit_num &= 7;
    result = *bit_field & ( 1 << bit_num );
    *bit_field |= ( 1 << bit_num );
    return ( result ) ? 1 : 0;
}

U32 BFieldExtU32( U8* src, U32 pos, U32 bits )
{
    U32 i, result = 0;
    for ( i = 0; i < bits; i++ )
        if ( Bt( pos + i, src ) )
        {
            Bts( i, ( U8* )&result );
        }
    return result;
}

U0 BFieldOrU32( U8* bit_field, U64 bit_num, U32 pattern )
{
    bit_field += bit_num >> 3;
    pattern <<= bit_num & 7;
    *( U32* )bit_field |= pattern;
}

U0 SwapI64( I64* a, I64* b )
{
    I64 tmp = *a;
    *a = *b;
    *b = tmp;
}

U0 SwapU16( U16* a, U16* b )
{
    U16 tmp = *a;
    *a = *b;
    *b = tmp;
}

U0 SwapU32( U32* a, U32* b )
{
    U32 tmp = *a;
    *a = *b;
    *b = tmp;
}
