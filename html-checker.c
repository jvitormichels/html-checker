#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"

int main(int argc, char *argv[]) {
  FILE *arquivo = fopen(argv[1], "r");

  Stack p1;
  stack_new(&p1);

  char str[1024];
  char caractere;
  int i = 0;
  while((caractere = fgetc(arquivo)) != EOF) {
    if (caractere == '\n' || caractere == ' ') {
      continue;
    }
    else {
      str[i] = caractere;
      i++;
    }
  }

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
        printf("Oh no, there is something wrong with your html!\n");
        printf("It looks like you opened a %s tag and didn't close it.\n", p1.tags[p1.top].name);
        exit(1);
      }
    }
    tag = strtok(NULL, s);
    x->name = tag;
  }

  fclose(arquivo);
  if (stack_empty(p1)) {
    printf("Your HTML is valid.\n");
    printf("You're doing great, keep it up, King!\n");
  }

  return 0;
}