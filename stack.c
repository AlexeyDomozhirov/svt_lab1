#include "stack.h"
#include <limits.h>
#include <stdint.h>
#include <stdlib.h>

Stack st_new(void) { return (Stack){0, 0, NULL}; }

bool st_is_empty(const Stack *stack) { return stack->size == 0; }

bool st_push(Stack *stack, int new_el) {
  if (stack == NULL || stack->size + 1 > SIZE_MAX / sizeof(int))
    return false;
  if (stack->size + 1 > stack->capacity) {
    size_t new_capacity = stack->capacity == 0
                              ? 1
                              : (stack->capacity >= (SIZE_MAX / sizeof(int) / 2)
                                     ? SIZE_MAX / sizeof(int)
                                     : stack->capacity * 2);
    int *new = (int *)realloc(stack->content, new_capacity * sizeof(int));
    if (new == NULL)
      return false;
    new[stack->size] = new_el;
    stack->content = new;
    stack->size += 1;
    stack->capacity = new_capacity;
    return true;
  }
  stack->content[stack->size] = new_el;
  stack->size += 1;
  return true;
}

bool st_pop(Stack *stack) {
  if (stack == NULL || stack->size == 0)
    return false;
  stack->size -= 1;
  if (stack->size == 0) {
    stack->capacity = 0;
    free(stack->content);
    stack->content = NULL;
    return true;
  }
  if (stack->size <= stack->capacity / 2) {
    size_t new_capacity = stack->capacity / 2;
    int *new = (int *)realloc(stack->content, new_capacity * sizeof(int));
    if (new == NULL)
      return true;
    stack->content = new;
    stack->capacity = new_capacity;
  }
  return true;
}

int *st_peek(Stack *stack) {
  if (stack == NULL || stack->size == 0)
    return NULL;
  return &stack->content[stack->size - 1];
}

void st_free(Stack *stack) {
  if (stack == NULL)
    return;
  free(stack->content);
  stack->content = NULL;
  stack->size = 0;
  stack->capacity = 0;
}
