#include <criterion/criterion.h>
#include <stdlib.h>
#include "list.h"

Test(list_remove_range, null)
{
    int return_value;

    return_value = list_remove_range(NULL, 0, 0);
    cr_assert_eq(return_value, 1);
}

Test(list_remove_range, out_of_range_1)
{
    list_t *list = list_create(NULL);
    int return_value;

    list_add(list, "azerty");
    list_add(list, "qwerty");
    return_value = list_remove_range(list, -1, 1);
    cr_assert_eq(return_value, 1);
    cr_assert_str_eq(list->list->data, "azerty");
    cr_assert_str_eq(list->list->next->data, "qwerty");
    cr_assert_eq(list->size, 2);
    list_destroy(list);
}

Test(list_remove_range, out_of_range_2)
{
    list_t *list = list_create(NULL);
    int return_value;

    list_add(list, "azerty");
    list_add(list, "qwerty");
    return_value = list_remove_range(list, 0, 3);
    cr_assert_eq(return_value, 1);
    cr_assert_str_eq(list->list->data, "azerty");
    cr_assert_str_eq(list->list->next->data, "qwerty");
    cr_assert_eq(list->size, 2);
    list_destroy(list);
}

Test(list_remove_range, out_of_range_3)
{
    list_t *list = list_create(NULL);
    int return_value;

    list_add(list, "azerty");
    list_add(list, "qwerty");
    return_value = list_remove_range(list, -1, 2);
    cr_assert_eq(return_value, 1);
    cr_assert_str_eq(list->list->data, "azerty");
    cr_assert_str_eq(list->list->next->data, "qwerty");
    cr_assert_eq(list->size, 2);
    list_destroy(list);
}

Test(list_remove_range, higher_from)
{
    list_t *list = list_create(NULL);
    int return_value;

    list_add(list, "azerty");
    list_add(list, "qwerty");
    return_value = list_remove_range(list, 1, 0);
    cr_assert_eq(return_value, 1);
    cr_assert_str_eq(list->list->data, "azerty");
    cr_assert_str_eq(list->list->next->data, "qwerty");
    cr_assert_eq(list->size, 2);
    list_destroy(list);
}

Test(list_remove_range, remove_range_1)
{
    list_t *list = list_create(NULL);
    int return_value;

    list_add(list, "azerty");
    list_add(list, "qwerty");
    return_value = list_remove_range(list, 0, 2);
    cr_assert_eq(return_value, 0);
    cr_assert_null(list->list);
    cr_assert_null(list->end);
    cr_assert_eq(list->size, 0);
    list_destroy(list);
}

Test(list_remove_range, remove_range_2)
{
    list_t *list = list_create(NULL);
    int return_value;

    list_add(list, "azerty");
    list_add(list, "qwerty");
    return_value = list_remove_range(list, 0, 1);
    cr_assert_eq(return_value, 0);
    cr_assert_str_eq(list->list->data, "qwerty");
    cr_assert_eq(list->list, list->end);
    cr_assert_eq(list->size, 1);
    list_destroy(list);
}

Test(list_remove_range, remove_range_3)
{
    list_t *list = list_create(NULL);
    int return_value;

    list_add(list, "azerty");
    list_add(list, "qwerty");
    return_value = list_remove_range(list, 1, 2);
    cr_assert_eq(return_value, 0);
    cr_assert_str_eq(list->list->data, "azerty");
    cr_assert_eq(list->list, list->end);
    cr_assert_eq(list->size, 1);
    list_destroy(list);
}

Test(list_remove_range, remove_range_4)
{
    list_t *list = list_create(NULL);
    int return_value;

    list_add(list, "azerty");
    list_add(list, "qwerty");
    list_add(list, "abc");
    list_add(list, "def");
    return_value = list_remove_range(list, 1, 4);
    cr_assert_eq(return_value, 0);
    cr_assert_str_eq(list->list->data, "azerty");
    cr_assert_eq(list->list, list->end);
    cr_assert_eq(list->size, 1);
    list_destroy(list);
}