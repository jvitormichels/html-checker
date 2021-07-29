#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"

void tags_from_html(char *html_tape, char *path);
int html_is_valid (Stack tag_stack);

int main(int argc, char *argv[]) {
  char html_path[50];
  strncpy(html_path, argv[1], sizeof html_path);

  char str[1024];
  tags_from_html(str, html_path);

  Stack tag_stack;
  stack_new(&tag_stack);

  const char s[2] = "<";
  char *tag_name;

  tag_name = strtok(str, s);
  Tag *tag = (Tag*)malloc(sizeof(Tag));
  tag->name = tag_name;

  while(tag_name != NULL) {
    if (tag_name[0] != '/') {
      stack_push(&tag_stack, *tag);
    }
    else {
      tag_name++;
      if (strcmp(tag_name, tag_stack.tags[tag_stack.top].name) == 0) {
        stack_pop(&tag_stack, tag);
      }
      else {
        printf("Oh no, there is something wrong with your html!\n");
        printf("It looks like you opened a %s tag and didn't close it.\n", tag_stack.tags[tag_stack.top].name);
        exit(1);
      }
    }
    tag_name = strtok(NULL, s);
    tag->name = tag_name;
  }

  if (html_is_valid(tag_stack)) {
    printf("Your HTML is valid.\n");
    printf("You're doing great, keep it up, King!\n");
  }

  return 0;
}

int html_is_valid (Stack stack) {
  return stack_empty(stack);
}

void tags_from_html(char *html_tape, char *path) {
  FILE *file = fopen(path, "r");

  char character;
  int i = 0;
  int is_reading_tag;

  while ((character = fgetc(file)) != EOF) {
    if (character == '<') {
      is_reading_tag = 1;
    }
    if (is_reading_tag && (character == ' ' || character == '\n')) {
      is_reading_tag = 0;
    }

    if (is_reading_tag || character == '>') {
      html_tape[i] = character;
      i++;
    }
  }

  fclose(file);
}