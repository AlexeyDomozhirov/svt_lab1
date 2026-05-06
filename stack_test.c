#include "stack.h"
#include <assert.h>
#include <limits.h>
#include <stdint.h>
#include <stdio.h>

void test_new_stack_is_empty_and_peek_pop_return_null(void) {
    Stack s = st_new();

    assert(st_is_empty(&s));
    assert(st_peek(&s) == NULL);
    assert(!st_pop(&s));

    st_free(&s);
}

void test_push_one_element_then_pop(void) {
    Stack s = st_new();

    assert(st_push(&s, 777));
    assert(!st_is_empty(&s));
    assert(*st_peek(&s) == 777);

    assert(st_pop(&s));
    assert(st_is_empty(&s));

    st_free(&s);
}

void test_push_multiple_elements_check_lifo_order(void) {
    Stack s = st_new();
    const int N = 20;

    for (int i = 0; i < N; i++)
        assert(st_push(&s, i));

    for (int i = N - 1; i >= 0; i--) {
        assert(*st_peek(&s) == i);
        assert(st_pop(&s));
    }

    assert(st_is_empty(&s));
    st_free(&s);
}

void test_push_many_elements_check_size_and_peek(void) {
    Stack s = st_new();
    const int N = 10000;

    for (int i = 0; i < N; i++)
        assert(st_push(&s, i * 10));

    assert(s.size == (size_t)N);
    assert(*st_peek(&s) == (N - 1) * 10);

    st_free(&s);
}

void test_empty_after_complete_pop_resets_capacity_and_content(void) {
    Stack s = st_new();
    const int N = 64;

    for (int i = 0; i < N; i++)
        assert(st_push(&s, i));

    for (int i = N - 1; i >= 0; i--) {
        assert(*st_peek(&s) == i);
        assert(st_pop(&s));
    }

    assert(st_is_empty(&s));
    assert(s.capacity == 0);
    assert(s.content == NULL);

    st_free(&s);
}

void test_push_on_full_stack_fails(void) {
    Stack s = st_new();

    size_t max_elements = SIZE_MAX / sizeof(int);
    s.size = max_elements;

    assert(!st_push(&s, 0));

    assert(s.size == max_elements);

    s.size = 0;
    st_free(&s);
}

int main(void) {
    test_new_stack_is_empty_and_peek_pop_return_null();
    test_push_one_element_then_pop();
    test_push_multiple_elements_check_lifo_order();
    test_push_many_elements_check_size_and_peek();
    test_empty_after_complete_pop_resets_capacity_and_content();
    test_push_on_full_stack_fails();
    return 0;
}
