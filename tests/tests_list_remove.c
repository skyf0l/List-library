#include <criterion/criterion.h>
#include "list.h"

Test(list_remove, null)
{
    int return_value;

    return_value = list_remove(NULL, 0);
    cr_assert_eq(return_value, 1);
}

Test(list_remove, out_of_range_1)
{
    list_t *list = list_create(NULL);
    int return_value;

    list_add(list, "azerty");
    list_add(list, "qwerty");
    return_value = list_remove(list, -1);
    cr_assert_eq(return_value, 1);
    list_destroy(list);
}

Test(list_remove, out_of_range_2)
{
    list_t *list = list_create(NULL);
    int return_value;

    list_add(list, "azerty");
    list_add(list, "qwerty");
    return_value = list_remove(list, 3);
    cr_assert_eq(return_value, 1);
    list_destroy(list);
}

Test(list_remove, remove_1)
{
    list_t *list = list_create(NULL);
    int return_value;

    list_add(list, "rm");
    list_add(list, "azerty");
    list_add(list, "qwerty");
    return_value = list_remove(list, 0);
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

Test(list_remove, remove_2)
{
    list_t *list = list_create(NULL);
    int return_value;

    list_add(list, "azerty");
    list_add(list, "rm");
    list_add(list, "qwerty");
    return_value = list_remove(list, 1);
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

Test(list_remove, remove_3)
{
    list_t *list = list_create(NULL);
    int return_value;

    list_add(list, "azerty");
    list_add(list, "qwerty");
    list_add(list, "rm");
    return_value = list_remove(list, 2);
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