#include "StringInfo.h"
#include <stdlib.h>

StringInfo* Get(void* (*KeyboardInput)(void *), void* (*Concatenate)(void *), void* (*GetSubstring)(void*), void* (*SplitToWords)(void *), void* (*Print)(void*), void* (*Remove)(void*)) {
  StringInfo* StrInfo = (StringInfo*) malloc(sizeof(StringInfo));
  StrInfo->KeyboardInput = KeyboardInput;
  StrInfo->Concatenate = Concatenate;
  StrInfo->GetSubstring = GetSubstring;
  StrInfo->SplitToWords = SplitToWords;
  StrInfo->Print = Print;
  StrInfo->Remove = Remove;
  return StrInfo;
}
