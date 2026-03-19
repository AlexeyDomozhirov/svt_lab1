#ifndef STACK_H
#define STACK_H

#include <stdbool.h>
#include <stddef.h>

typedef struct {
  size_t size;
  size_t capacity;
  int *content;
} Stack;

Stack st_new(void);

bool st_is_empty(const Stack *stack);

bool st_push(Stack *stack, int new_el);

bool st_pop(Stack *stack);

int *st_peek(Stack *stack);

void st_free(Stack *stack);

#endif
