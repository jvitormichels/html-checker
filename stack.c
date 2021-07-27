#include <stdio.h>
#include "stack.h"

void stack_new (Stack *p) {
  p->top = -1;
}

int stack_empty (Stack p) {
  return p.top == -1;
}

int stack_full (Stack p) {
  return p.top == STACK_MAX - 1;
}

int stack_push (Stack *p, Tag tag) {
  if (stack_full(*p)) {
    return ERROR_STACK_FULL;
  }
  p->top++;
  p->tags[p->top] = tag;
  return 1;
}

int stack_pop (Stack *p, Tag *tag) {
  if (stack_empty(*p)) {
    return ERROR_STACK_EMPTY;
  }
  *tag = p->tags[p->top];
  p->top--;
  return 1;
}

int stack_top (Stack *p, Tag *tag) {
  if (stack_empty(*p)) {
    return ERROR_STACK_EMPTY;
  }
  *tag = p->tags[p->top];
  return 1;
}

void stack_show (Stack *p) {
  if (stack_empty(*p)) {
    printf("Your stack is empty!\n");
  }
  else {
    printf("Stack's data:\n");
    for (int i = 0; i <= p->top; i++) {
      printf("%s\n", p->tags[i].name);
    }
  }
}
