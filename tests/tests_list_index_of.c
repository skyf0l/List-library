#include <criterion/criterion.h>
#include "list.h"

Test(list_index_of, null)
{
    int return_value;

    return_value = list_index_of(NULL, NULL);
    cr_assert_eq(return_value, -1);
}

Test(list_index_of, empty)
{
    list_t *list = list_create(NULL);
    int return_value;

    return_value = list_index_of(list, NULL);
    cr_assert_eq(return_value, -1);
    list_destroy(list);
}

Test(list_index_of, index_1)
{
    list_t *list = list_create(NULL);
    int return_value;

    list_add(list, NULL);
    return_value = list_index_of(list, NULL);
    cr_assert_eq(return_value, 0);
    list_destroy(list);
}

Test(list_index_of, index_2)
{
    list_t *list = list_create(NULL);
    char *str = "azerty";
    int return_value;

    list_add(list, NULL);
    return_value = list_index_of(list, str);
    cr_assert_eq(return_value, -1);
    list_destroy(list);
}

Test(list_index_of, index_3)
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
    return_value = list_index_of(list, str);
    cr_assert_eq(return_value, 1);
    list_destroy(list);
}

Test(list_index_of, index_4)
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
    return_value = list_index_of(list, NULL);
    cr_assert_eq(return_value, 0);
    list_destroy(list);
}

Test(list_index_of, index_5)
{
    list_t *list = list_create(NULL);
    char *str = "azerty";
    int return_value;

    list_add(list, NULL);
    list_add(list, NULL);
    list_add(list, NULL);
    list_add(list, NULL);
    list_add(list, NULL);
    list_add(list, NULL);
    list_add(list, NULL);
    return_value = list_index_of(list, str);
    cr_assert_eq(return_value, -1);
    list_destroy(list);
}

Test(list_index_of, index_6)
{
    list_t *list = list_create(NULL);
    char *str = "azerty";
    int return_value;

    list_add(list, NULL);
    list_add(list, NULL);
    list_add(list, NULL);
    list_add(list, NULL);
    list_add(list, NULL);
    list_add(list, NULL);
    list_add(list, str);
    return_value = list_index_of(list, str);
    cr_assert_eq(return_value, 6);
    list_destroy(list);
}

Test(list_last_index_of, null)
{
    int return_value;

    return_value = list_last_index_of(NULL, NULL);
    cr_assert_eq(return_value, -1);
}

Test(list_last_index_of, empty)
{
    list_t *list = list_create(NULL);
    int return_value;

    return_value = list_last_index_of(list, NULL);
    cr_assert_eq(return_value, -1);
    list_destroy(list);
}

Test(list_last_index_of, index_1)
{
    list_t *list = list_create(NULL);
    int return_value;

    list_add(list, NULL);
    return_value = list_last_index_of(list, NULL);
    cr_assert_eq(return_value, 0);
    list_destroy(list);
}

Test(list_last_index_of, index_2)
{
    list_t *list = list_create(NULL);
    char *str = "azerty";
    int return_value;

    list_add(list, NULL);
    return_value = list_last_index_of(list, str);
    cr_assert_eq(return_value, -1);
    list_destroy(list);
}

Test(list_last_index_of, index_3)
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
    return_value = list_last_index_of(list, str);
    cr_assert_eq(return_value, 6);
    list_destroy(list);
}

Test(list_last_index_of, index_4)
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
    return_value = list_last_index_of(list, NULL);
    cr_assert_eq(return_value, 5);
    list_destroy(list);
}

Test(list_last_index_of, index_5)
{
    list_t *list = list_create(NULL);
    char *str = "azerty";
    int return_value;

    list_add(list, NULL);
    list_add(list, NULL);
    list_add(list, NULL);
    list_add(list, NULL);
    list_add(list, NULL);
    list_add(list, NULL);
    list_add(list, NULL);
    return_value = list_last_index_of(list, str);
    cr_assert_eq(return_value, -1);
    list_destroy(list);
}

Test(list_last_index_of, index_6)
{
    list_t *list = list_create(NULL);
    char *str = "azerty";
    int return_value;

    list_add(list, NULL);
    list_add(list, NULL);
    list_add(list, NULL);
    list_add(list, NULL);
    list_add(list, NULL);
    list_add(list, NULL);
    list_add(list, str);
    return_value = list_last_index_of(list, str);
    cr_assert_eq(return_value, 6);
    list_destroy(list);
}