#include "../HeadersAndWrappers/HolyCTypeWrappers.h"
#include "../HeadersAndWrappers/HolyCFunctionWrappers.h"

U0 SwapU32(U32 *a,U32 *b);
U0 SwapU16(U16 *a,U16 *b);
U0 SwapI64(I64 *a,I64 *b);
U0 BFieldOrU32(U8 *bit_field,U64 bit_num,U32 pattern);
U32 BFieldExtU32(U8 *src,U32 pos,U32 bits);
U32 Bts(U32 bit_num,U8 *bit_field);
U32 Bt(U32 bit_num,U8 *bit_field);
