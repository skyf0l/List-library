#include <criterion/criterion.h>
#include "list.h"

Test(list_count, null)
{
    int return_value;

    return_value = list_count(NULL, 0);
    cr_assert_eq(return_value, -1);
}

Test(list_count, empty)
{
    list_t *list = list_create(NULL);
    int return_value;

    return_value = list_count(list, NULL);
    cr_assert_eq(return_value, 0);
    list_destroy(list);
}

Test(list_count, count_1)
{
    list_t *list = list_create(NULL);
    int return_value;

    list_add(list, NULL);
    return_value = list_count(list, NULL);
    cr_assert_eq(return_value, 1);
    list_destroy(list);
}

Test(list_count, count_2)
{
    list_t *list = list_create(NULL);
    char *str = "azerty";
    int return_value;

    list_add(list, NULL);
    return_value = list_count(list, str);
    cr_assert_eq(return_value, 0);
    list_destroy(list);
}

Test(list_count, count_3)
{
    list_t *list = list_create(NULL);
    char *str = "azerty";
    int return_value;

    list_add(list, NULL);
    list_add(list, str);
    list_add(list, NULL);
    list_add(list, NULL);
    list_add(list, str);
    list_add(list, NULL);
    list_add(list, str);
    return_value = list_count(list, str);
    cr_assert_eq(return_value, 3);
    list_destroy(list);
}

Test(list_count, count_4)
{
    list_t *list = list_create(NULL);
    char *str = "azerty";
    int return_value;

    list_add(list, NULL);
    list_add(list, str);
    list_add(list, NULL);
    list_add(list, NULL);
    list_add(list, str);
    list_add(list, NULL);
    list_add(list, str);
    return_value = list_count(list, NULL);
    cr_assert_eq(return_value, 4);
    list_destroy(list);
}