#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"

int main(int argc, char *argv[]) {
  FILE *arquivo = fopen(argv[1], "r");

  Stack p1;
  stack_new(&p1);

  while(!feof(arquivo)) {
    char line[80];
    const char split_char[2] = "<";
    char *tag;

    if (fgets(line, 80, arquivo) == NULL) {
      break;
    }

    fgets(line, 80, arquivo);
    tag = strtok(line, split_char);
    Tag *x = (Tag*)malloc(sizeof(Tag));
    x->name = tag;

    while (tag != NULL) {
      if (tag[0] != '/') {
        stack_push(&p1, *x);
      }
      else {
        tag++;
        if (strcmp(tag, p1.tags[p1.top].name) == 0) {
          stack_pop(&p1, x);
        }
        else {
          printf("Your HTML is invalid!\n");
          exit(1);
        }
      }
      tag = strtok(NULL, split_char);
      x->name = tag;
    }
  }

  fclose(arquivo);
  if (stack_empty(p1)) {
    printf("Your HTML is valid.\n");
    printf("You're doing great, keep it up, King!\n");
  }
  
  return 0;
}