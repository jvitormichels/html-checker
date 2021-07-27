#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"

int main() {
  Stack p1;
  stack_new(&p1);

  char str[80] = "<html><body><div></div></body></html>";
  const char s[2] = "<";
  char *tag;

  tag = strtok(str, s);
  Tag *x = (Tag*)malloc(sizeof(Tag));
  x->name = tag;

  while(tag != NULL) {
    if (tag[0] != '/') {
      stack_push(&p1, *x);
    }
    else {
      tag++;
      if (strcmp(tag, p1.tags[p1.top].name) == 0) {
        stack_pop(&p1, x);
      }
      else {
        printf("HTML inválido!\n");
        exit(1);
      }
    }
    tag = strtok(NULL, s);
    x->name = tag;
  }

  if (stack_empty(p1)) {
    printf("HTML válido!\n");
  }
  
  return 0;
}