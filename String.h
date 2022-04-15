#ifndef STRING_H_INCLUDED
#define STRING_H_INCLUDED
#include "StringInfo.h"

struct String {
  StringInfo* Info;
  int len;
  void* ptr;
} typedef String;

String* initialise();
void* KeyboardInput(void* Str);
void* Concatenate(void* Str);
void* GetSubstring(void* Str);
void* SplitToWords(void* Str);
void* Print(void* Str);
void* Remove(void* Str);
char *mystrtok(char *str, const char *delim);

#endif // STRING_H_INCLUDED
