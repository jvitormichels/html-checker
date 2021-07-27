#define STACK_MAX 50
#define ERROR_STACK_EMPTY -1
#define ERROR_STACK_FULL -2

#define TAG_MAX 50

typedef struct{
  char *name;
} Tag;

typedef struct{
  Tag tags[STACK_MAX];
  int top;
} Stack;

void stack_new (Stack *p);
int stack_empty (Stack p);
int stack_full (Stack p);
int stack_push (Stack *p, Tag name);
int stack_pop (Stack *p, Tag *name);
int stack_top (Stack *p, Tag *name);
void stack_show (Stack *p);