#include <criterion/criterion.h>
#include "list.h"

Test(list_set, null)
{
    int return_value;

    return_value = list_set(NULL, "abc", 0);
    cr_assert_eq(return_value, 1);
}

Test(list_set, out_of_range_1)
{
    list_t *list = list_create(NULL);
    int return_value;

    list_add(list, "azerty");
    return_value = list_set(list, "abc", -1);
    cr_assert_eq(return_value, 1);
    list_destroy(list);
}

Test(list_set, out_of_range_2)
{
    list_t *list = list_create(NULL);
    int return_value;

    list_add(list, "azerty");
    return_value = list_set(list, "abc", 12);
    cr_assert_eq(return_value, 1);
    list_destroy(list);
}

Test(list_set, ok)
{
    list_t *list = list_create(NULL);
    int return_value;

    list_add(list, "azerty");
    return_value = list_set(list, "qwerty", 0);
    cr_assert_eq(return_value, 0);
    cr_assert_str_eq(list->list->data, "qwerty");
    list_destroy(list);
}

Test(list_replace, null)
{
    int return_value;

    return_value = list_replace(NULL, "abc", 0);
    cr_assert_eq(return_value, 1);
}

Test(list_replace, out_of_range_1)
{
    list_t *list = list_create(NULL);
    int return_value;

    list_add(list, "azerty");
    return_value = list_replace(list, "abc", -1);
    cr_assert_eq(return_value, 1);
    list_destroy(list);
}

Test(list_replace, out_of_range_2)
{
    list_t *list = list_create(NULL);
    int return_value;

    list_add(list, "azerty");
    return_value = list_replace(list, "abc", 12);
    cr_assert_eq(return_value, 1);
    list_destroy(list);
}

Test(list_replace, ok)
{
    list_t *list = list_create(NULL);
    int return_value;

    list_add(list, "azerty");
    return_value = list_replace(list, "qwerty", 0);
    cr_assert_eq(return_value, 0);
    cr_assert_str_eq(list->list->data, "qwerty");
    list_destroy(list);
}