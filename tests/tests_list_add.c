#include <criterion/criterion.h>
#include "list.h"

Test(list_add, null)
{
    int return_value;

    return_value = list_add(NULL, "azerty");
    cr_assert_eq(return_value, 1);
}

Test(list_add, add_1)
{
    list_t *list = list_create(NULL);
    int return_value;

    return_value = list_add(list, "azerty");
    cr_assert_eq(return_value, 0);
    cr_assert_str_eq(list->list->data, "azerty");
    cr_assert_null(list->list->prev);
    cr_assert_null(list->list->next);
    cr_assert_eq(list->list, list->end);
    cr_assert_eq(list->size, 1);
    list_destroy(list);
}

Test(list_add, add_2)
{
    list_t *list = list_create(NULL);

    list_add(list, "azerty");
    list_add(list, "qwerty");
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

Test(list_add, add_3)
{
    list_t *list = list_create(NULL);

    list_add(list, "azerty");
    list_add(list, "qwerty");
    list_add(list, "abcd");
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

Test(list_add_at, null)
{
    list_t *list = NULL;
    int return_value;

    return_value = list_add_at(list, "azerty", 0);
    cr_assert_eq(return_value, 1);
}

Test(list_add_at, out_of_range_1)
{
    list_t *list = list_create(NULL);
    int return_value;

    list_add(list, "qwerty");
    list_add(list, "abcd");
    return_value = list_add_at(list, "azerty", -1);
    cr_assert_eq(return_value, 1);
    list_destroy(list);
}

Test(list_add_at, out_of_range_2)
{
    list_t *list = list_create(NULL);
    int return_value;

    list_add(list, "qwerty");
    list_add(list, "abcd");
    return_value = list_add_at(list, "azerty", 3);
    cr_assert_eq(return_value, 1);
    list_destroy(list);
}

Test(list_add_at, add_1)
{
    list_t *list = list_create(NULL);
    int return_value;

    list_add(list, "qwerty");
    list_add(list, "abcd");
    return_value = list_add_at(list, "azerty", 0);
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

Test(list_add_at, add_2)
{
    list_t *list = list_create(NULL);

    list_add(list, "azerty");
    list_add(list, "abcd");
    list_add_at(list, "qwerty", 1);
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

Test(list_add_at, add_3)
{
    list_t *list = list_create(NULL);

    list_add(list, "azerty");
    list_add(list, "qwerty");
    list_add_at(list, "abcd", 2);
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