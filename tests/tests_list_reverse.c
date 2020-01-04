#include <criterion/criterion.h>
#include "list.h"

Test(list_reverse, null)
{
    int return_value;

    return_value = list_reverse(NULL);
    cr_assert_eq(return_value, 1);
}

Test(list_reverse, empty)
{
    list_t *list = list_create(NULL);
    int return_value;

    return_value = list_reverse(list);
    cr_assert_eq(return_value, 0);
    cr_assert_null(list->list);
    cr_assert_null(list->end);
    cr_assert_eq(list->size, 0);
    list_destroy(list);
}

Test(list_reverse, reverse_1)
{
    list_t *list = list_create(NULL);
    int return_value;

    list_add(list, "azerty");
    return_value = list_reverse(list);
    cr_assert_eq(return_value, 0);
    cr_assert_str_eq(list->list->data, "azerty");
    cr_assert_null(list->list->prev);
    cr_assert_null(list->list->next);
    cr_assert_eq(list->list, list->end);
    cr_assert_eq(list->size, 1);
    list_destroy(list);
}

Test(list_reverse, reverse_2)
{
    list_t *list = list_create(NULL);
    int return_value;

    list_add(list, "qwerty");
    list_add(list, "azerty");
    return_value = list_reverse(list);
    cr_assert_eq(return_value, 0);
    cr_assert_str_eq(list->list->data, "azerty");
    cr_assert_null(list->list->prev);
    cr_assert_str_eq(list->list->next->data, "qwerty");
    cr_assert_eq(list->list->next->prev, list->list);
    cr_assert_null(list->list->next->next);
    cr_assert_eq(list->list->next, list->end);
    cr_assert_eq(list->end->prev, list->list);
    cr_assert_eq(list->size, 2);
    list_destroy(list);
}

Test(list_reverse, reverse_3)
{
    list_t *list = list_create(NULL);
    int return_value;

    list_add(list, "abcd");
    list_add(list, "qwerty");
    list_add(list, "azerty");
    return_value = list_reverse(list);
    cr_assert_eq(return_value, 0);
    cr_assert_str_eq(list->list->data, "azerty");
    cr_assert_null(list->list->prev);
    cr_assert_str_eq(list->list->next->data, "qwerty");
    cr_assert_eq(list->list->next->prev, list->list);
    cr_assert_str_eq(list->list->next->next->data, "abcd");
    cr_assert_eq(list->list->next->next->prev, list->list->next);
    cr_assert_null(list->list->next->next->next);
    cr_assert_eq(list->list->next->next, list->end);
    cr_assert_eq(list->end->prev->prev, list->list);
    cr_assert_eq(list->size, 3);
    list_destroy(list);
}

Test(list_reverse, reverse_4)
{
    list_t *list = list_create(NULL);
    int return_value;

    list_add(list, "abcd");
    list_add(list, "qwerty");
    list_add(list, "azerty");
    list_add(list, "abc");
    return_value = list_reverse(list);
    cr_assert_eq(return_value, 0);
    cr_assert_str_eq(list->list->data, "abc");
    cr_assert_str_eq(list->list->next->data, "azerty");
    cr_assert_str_eq(list->list->next->next->data, "qwerty");
    cr_assert_str_eq(list->list->next->next->next->data, "abcd");
    cr_assert_eq(list->size, 4);
    list_destroy(list);
}

Test(list_reverse, reverse_5)
{
    list_t *list = list_create(NULL);
    int return_value;

    list_add(list, "abcd");
    list_add(list, "qwerty");
    list_add(list, "azerty");
    list_add(list, "abc");
    list_add(list, "def");
    return_value = list_reverse(list);
    cr_assert_eq(return_value, 0);
    cr_assert_str_eq(list->list->data, "def");
    cr_assert_str_eq(list->list->next->data, "abc");
    cr_assert_str_eq(list->list->next->next->data, "azerty");
    cr_assert_str_eq(list->list->next->next->next->data, "qwerty");
    cr_assert_str_eq(list->list->next->next->next->next->data, "abcd");
    cr_assert_eq(list->size, 5);
    list_destroy(list);
}