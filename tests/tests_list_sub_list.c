#include <criterion/criterion.h>
#include "list.h"

Test(list_sub_list, null)
{
    int return_value;

    return_value = list_sub_list(NULL, 0, 0);
    cr_assert_eq(return_value, 1);
}

Test(list_sub_list, out_of_range_1)
{
    list_t *list = list_create(NULL);
    int return_value;

    list_add(list, "azerty");
    list_add(list, "qwerty");
    return_value = list_sub_list(list, -1, 1);
    cr_assert_eq(return_value, 1);
    cr_assert_str_eq(list->list->data, "azerty");
    cr_assert_str_eq(list->list->next->data, "qwerty");
    cr_assert_eq(list->size, 2);
    list_destroy(list);
}

Test(list_sub_list, out_of_range_2)
{
    list_t *list = list_create(NULL);
    int return_value;

    list_add(list, "azerty");
    list_add(list, "qwerty");
    return_value = list_sub_list(list, 0, 3);
    cr_assert_eq(return_value, 1);
    cr_assert_str_eq(list->list->data, "azerty");
    cr_assert_str_eq(list->list->next->data, "qwerty");
    cr_assert_eq(list->size, 2);
    list_destroy(list);
}

Test(list_sub_list, out_of_range_3)
{
    list_t *list = list_create(NULL);
    int return_value;

    list_add(list, "azerty");
    list_add(list, "qwerty");
    return_value = list_sub_list(list, -1, 2);
    cr_assert_eq(return_value, 1);
    cr_assert_str_eq(list->list->data, "azerty");
    cr_assert_str_eq(list->list->next->data, "qwerty");
    cr_assert_eq(list->size, 2);
    list_destroy(list);
}

Test(list_sub_list, higher_from)
{
    list_t *list = list_create(NULL);
    int return_value;

    list_add(list, "azerty");
    list_add(list, "qwerty");
    return_value = list_sub_list(list, 1, 0);
    cr_assert_eq(return_value, 1);
    list_destroy(list);
}

Test(list_sub_list, sub_list_1)
{
    list_t *list = list_create(NULL);
    int return_value;

    list_add(list, "azerty");
    list_add(list, "qwerty");
    return_value = list_sub_list(list, 0, 1);
    cr_assert_eq(return_value, 0);
    cr_assert_str_eq(list->list->data, "azerty");
    cr_assert_str_eq(list->list->next->data, "qwerty");
    cr_assert_eq(list->size, 2);
    list_destroy(list);
}

Test(list_sub_list, sub_list_2)
{
    list_t *list = list_create(NULL);
    int return_value;

    list_add(list, "azerty");
    list_add(list, "qwerty");
    return_value = list_sub_list(list, 0, 0);
    cr_assert_eq(return_value, 0);
    cr_assert_str_eq(list->list->data, "azerty");
    cr_assert_null(list->list->next);
    cr_assert_eq(list->size, 1);
    cr_assert_eq(list->list, list->end);
    list_destroy(list);
}

Test(list_sub_list, sub_list_3)
{
    list_t *list = list_create(NULL);
    int return_value;

    list_add(list, "azerty");
    list_add(list, "qwerty");
    return_value = list_sub_list(list, 1, 1);
    cr_assert_eq(return_value, 0);
    cr_assert_str_eq(list->list->data, "qwerty");
    cr_assert_null(list->list->next);
    cr_assert_eq(list->size, 1);
    cr_assert_eq(list->list, list->end);
    list_destroy(list);
}

Test(list_sub_list, sub_list_4)
{
    list_t *list = list_create(NULL);
    int return_value;

    list_add(list, "azerty");
    list_add(list, "qwerty");
    list_add(list, "abc");
    return_value = list_sub_list(list, 1, 1);
    cr_assert_eq(return_value, 0);
    cr_assert_str_eq(list->list->data, "qwerty");
    cr_assert_null(list->list->next);
    cr_assert_eq(list->size, 1);
    cr_assert_eq(list->list, list->end);
    list_destroy(list);
}