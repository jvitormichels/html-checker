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

int stack_push (Stack *p, int info) {
  if (stack_full(*p)) {
    return ERROR_STACK_FULL;
  }
  p->top++;
  p->data[p->top] = info;
  return 1;
}

int stack_pop (Stack *p, int *info) {
  if (stack_empty(*p)) {
    return ERROR_STACK_EMPTY;
  }
  *info = p->data[p->top];
  p->top--;
  return 1;
}

int stack_top (Stack *p, int *info) {
  if (stack_empty(*p)) {
    return ERROR_STACK_EMPTY;
  }
  *info = p->data[p->top];
  return 1;
}

void stack_show (Stack *p) {
  if (stack_empty) {
    printf("Your stack is empty!\n");
  }
  else {
    printf("Stack's data:\n");
    for (int i = 0; i <= p->top; i++) {
      printf("%d\n", p->data[i]);
    }
  }
}
