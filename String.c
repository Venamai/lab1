#include "String.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

String* Create() {
  String* Str = malloc(sizeof(String));
  StringInfo* Info = Get(&KeyboardInput, &Concatenate, &GetSubstring, &SplitToWords, &Print, &Remove);
  Str->len = 0;
  Str->ptr = NULL;
  Str->Info = Info;
  return Str;
}

char *myreadline() {
    char buf[81] = {0};
    char *res = NULL;
    int len = 0;
    int n = 0;
    do {
        n = scanf("%80[^\n]", buf);
        if (n < 0) {
            if (!res) {
                return NULL;
            }
        }
        else if (n > 0) {
            int chunk_len = strlen(buf);
            int str_len = len + chunk_len;
            res = realloc(res, str_len + 1);
            memcpy(res + len, buf, chunk_len);
            len = str_len;
        }
        else {
            scanf("%*c");
        }
    } while (n > 0);
    if (len > 0) {
        res[len] = '\0';
    }
    else {
        res = calloc(1, sizeof(char));
    }
    return res;
}


char *mystrchr(const char *str, int smb) {
  if(!str) return NULL;
  while (*str != '\0') {
    if(*str == (char) smb)
        return (char *) str;
    str++;
  }
  return NULL;
}

char *mystrtok(char *str, const char *delim) {
        static char *ptr = NULL;
        if (str)
            ptr = str;
        if (ptr == NULL || *ptr == '\0' || !ptr) {
                return NULL;
        }

        while (*ptr && mystrchr(delim, *ptr))
            ptr++;
        char* start = ptr;
        while (*ptr && !mystrchr(delim, *ptr))
            ptr++;
        if (*ptr == '\0') {
                ptr = NULL;
                return start;
        }
        *ptr = '\0';
        ptr++;
        while (*ptr && mystrchr(delim, *ptr))
            ptr++;
        return start;
}



void *KeyboardInput(void* Str) {
  String* TempStr = (String*) Str;
  if(TempStr->len)
    free(TempStr->ptr);
  char* ptr = myreadline();
  TempStr->len = strlen(ptr);
  TempStr->ptr = ptr;
}


void* Concatenate(void *Str) {
  String* TempStr = (String*) Str;
  char* TempPtr = (char*) TempStr->ptr;
  char* ptr = myreadline();
  int len = strlen(ptr);
  TempStr->ptr = (realloc(TempStr->ptr, (TempStr->len + len + 1)));
  memcpy(TempStr->ptr + TempStr->len, ptr, len + 1);
  TempStr->len += len;
  free(ptr);
}

void* GetSubstring(void *Str) {
  String* TempStr = (String*) Str;
  if(!TempStr->len) {
    printf("No string given.\n");
    return;
  }
  int i, j;
  printf("Enter i j: \n");
  scanf("%d %d", &i, &j);
  while(i < 0 || i >=TempStr->len || j < 0 || j >= TempStr->len || i > j) {
    printf("Wrong input\n");
    scanf("%d %d", &i, &j);
  }
  int Sslen = j - i;
  char* Substr = malloc(Sslen + 1);
  memcpy(Substr, TempStr->ptr + i, Sslen);
  memcpy(Substr + Sslen, TempStr->ptr + TempStr->len, 1);

  String* SubstrS = Create();
  SubstrS->ptr = Substr;
  SubstrS->len = Sslen;
  SubstrS->Info->Print(SubstrS);
  SubstrS->Info->Remove(SubstrS);
}


void* SplitToWords(void* Str) {
  String* TempStr = (String*) Str;
    if(!TempStr->len) {
    printf("Nothing to split\n");
    return;
  }
  char *TempPtr = (char*) TempStr->ptr;
  char* Ptrcpy = malloc(strlen(TempPtr) + 1);
  memcpy(Ptrcpy, TempPtr, (strlen(TempPtr) + 1));
  char* word = mystrtok(Ptrcpy, " \t");

  String** Words = malloc(sizeof(String*));
  int i = 0;
  while(word != NULL) {
    int WordLen = strlen(word);
    Words = realloc(Words, (i + 1) * sizeof(String*));
    Words[i] = Create();
    Words[i]->ptr = malloc(WordLen + 1);
    Words[i]->len = WordLen;

    memcpy(Words[i]->ptr, word, WordLen + 1);
    word = mystrtok(NULL, " \t");
    i++;
  }
  for(int k = 0; k < i; k++) {
    printf("%s\n", Words[k]->ptr);
    Words[k]->Info->Remove(Words[k]);
  }
  free(Words);
  free(Ptrcpy);
}

void* Print(void* Str) {
  String* TempStr = (String*) Str;
  if(!TempStr->len) {
    printf("Nothing to print\n");
    return;
  }
  printf("%s\n", ((String*) TempStr)->ptr);
}

void* Remove(void *Str) {
  String* TempStr = (String*) Str;
  if(TempStr != NULL) free(TempStr->ptr);
  free(TempStr->Info);
  free(Str);
}
