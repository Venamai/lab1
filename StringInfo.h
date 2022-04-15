#ifndef STRINGINFO_H_INCLUDED
#define STRINGINFO_H_INCLUDED

struct StringInfo {
  void* (*KeyboardInput)(void*);
  void* (*Concatenate)(void*);
  void* (*GetSubstring)(void*);
  void* (*SplitToWords)(void*);
  void* (*Print)(void*);
  void* (*Remove)(void*);
} typedef StringInfo;

StringInfo* Get(void* (*KeyboardInput)(void*), void* (*Concatenate)(void *), void* (*GetSubstring)(void*), void* (*SplitToWords)(void *), void* (*Print)(void*), void* (*Remove)(void*));

#endif // STRINGINFO_H_INCLUDED
