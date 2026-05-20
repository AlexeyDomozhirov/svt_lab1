#include "single_linked_list.h"
#include <assert.h>
#include <stdio.h>

static void test_empty_list_operations(void) {
  SLLNode *list = NULL;
  assert(sll_count(list) == 0);
  assert(sll_get(list, 0) == NULL);
  assert(!sll_pop(&list, 0));
  assert(!sll_push(&list, -1, 999));
  assert(!sll_push(NULL, 0, 42));
  sll_free(list);
}

static void test_push_one_element_and_pop(void) {
  SLLNode *list = NULL;
  assert(sll_push(&list, 0, 100));
  assert(sll_count(list) == 1);
  assert(*sll_get(list, 0) == 100);
  assert(sll_pop(&list, 0));
  assert(list == NULL);
  sll_free(list);
}

static void test_push_multiple_elements_at_head(void) {
  SLLNode *list = NULL;
  assert(sll_push(&list, 0, 10));
  assert(sll_push(&list, 0, 20));
  assert(sll_push(&list, 0, 30));
  assert(sll_count(list) == 3);
  assert(*sll_get(list, 0) == 30);
  assert(*sll_get(list, 2) == 10);
  sll_free(list);
}

static void test_insert_in_middle_and_at_tail(void) {
  SLLNode *list = NULL;

  assert(sll_push(&list, 0, 10));
  assert(sll_push(&list, 0, 20));
  assert(sll_push(&list, 0, 30));

  assert(sll_push(&list, 1, 999));
  assert(sll_push(&list, 4, 40));

  assert(sll_count(list) == 5);
  assert(*sll_get(list, 1) == 999);
  assert(*sll_get(list, 4) == 40);

  sll_free(list);
}

static void test_pop_from_head_and_middle(void) {
  SLLNode *list = NULL;

  assert(sll_push(&list, 0, 10));
  assert(sll_push(&list, 0, 20));
  assert(sll_push(&list, 0, 30));
  assert(sll_push(&list, 1, 999));
  assert(sll_push(&list, 4, 40));

  assert(sll_pop(&list, 0));
  assert(sll_pop(&list, 1));
  assert(sll_pop(&list, 2));
  assert(sll_count(list) == 2);

  sll_free(list);
}

static void test_invalid_operations_and_null_safety(void) {
  SLLNode *list = NULL;

  assert(sll_push(&list, 0, 10));
  assert(sll_push(&list, 0, 999));

  assert(!sll_pop(&list, 10));
  assert(sll_get(list, 5) == NULL);

  sll_free(list);
  list = NULL;

  assert(sll_count(list) == 0);
  sll_free(NULL);
}

int main(void) {
  test_empty_list_operations();
  test_push_one_element_and_pop();
  test_push_multiple_elements_at_head();
  test_insert_in_middle_and_at_tail();
  test_pop_from_head_and_middle();
  test_invalid_operations_and_null_safety();
  return 0;
}
