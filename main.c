#include "menu.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
  String* Str = Create();
  menu(Str);
  Str->Info->Remove(Str);
}
