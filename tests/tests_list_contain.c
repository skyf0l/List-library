#include <criterion/criterion.h>
#include "list.h"

Test(list_contain, null)
{
    int return_value;

    return_value = list_contain(NULL, 0);
    cr_assert_eq(return_value, 0);
}

Test(list_contain, empty)
{
    list_t *list = list_create(NULL);
    int return_value;

    return_value = list_contain(list, NULL);
    cr_assert_eq(return_value, 0);
    list_destroy(list);
}

Test(list_contain, contain_1)
{
    list_t *list = list_create(NULL);
    char *str = "azerty";
    int return_value;

    list_add(list, NULL);
    return_value = list_contain(list, str);
    cr_assert_eq(return_value, 0);
    list_destroy(list);
}

Test(list_contain, contain_2)
{
    list_t *list = list_create(NULL);
    int return_value;

    list_add(list, NULL);
    return_value = list_contain(list, NULL);
    cr_assert_eq(return_value, 1);
    list_destroy(list);
}

Test(list_contain, contain_3)
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
    return_value = list_contain(list, str);
    cr_assert_eq(return_value, 1);
    list_destroy(list);
}

Test(list_contain, contain_4)
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
    return_value = list_contain(list, NULL);
    cr_assert_eq(return_value, 1);
    list_destroy(list);
}