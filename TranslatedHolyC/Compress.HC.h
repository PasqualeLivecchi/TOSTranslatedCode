#include "../HeadersAndWrappers/HolyCTypeWrappers.h"
#include "../HeadersAndWrappers/TOSKernelStuff.h"
#include "../HeadersAndWrappers/HolyCFunctionWrappers.h"
#include "../TranslatedASM/KUtils.HC.h"

CArcCtrl *ArcCtrlNew(Bool expand,I64 compression_type);
U0 ArcExpandBuf(CArcCtrl *c);
Bool ArcFinishCompression(CArcCtrl *c);
U0 ArcCompressBuf(CArcCtrl *c);
I64 ArcDetermineCompressionType(U8 *src,I64 size);
U0 ArcEntryGet(CArcCtrl *c);
