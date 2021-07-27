#define STACK_MAX 50
#define ERROR_STACK_EMPTY -1
#define ERROR_STACK_FULL -2

typedef struct{
  int data[STACK_MAX];
  int top;
} Stack;

void stack_new (Stack *p);
int stack_empty (Stack p);
int stack_full (Stack p);
int stack_push (Stack *p, int info);
int stack_pop (Stack *p, int *info);
int stack_top (Stack *p, int *info);
void stack_show (Stack *p);