#include <criterion/criterion.h>
#include <stdlib.h>
#include "list.h"

Test(list_to_array, null)
{
    void **array;

    array = list_to_array(NULL);
    cr_assert_null(array);
}

Test(list_to_array, empty)
{
    list_t *list = list_create(NULL);
    void **array;

    array = list_to_array(list);
    cr_assert_not_null(array);
    cr_assert_null(array[0]);
    free(array);
    list_destroy(list);
}

Test(list_to_array, list_to_array_1)
{
    list_t *list = list_create(NULL);
    void **array;

    list_add(list, NULL);
    array = list_to_array(list);
    cr_assert_not_null(array);
    cr_assert_eq(array[0], NULL);
    cr_assert_null(array[1]);
    free(array);
    list_destroy(list);
}

Test(list_to_array, list_to_array_2)
{
    list_t *list = list_create(NULL);
    char *str = "azerty";
    void **array;

    list_add(list, str);
    array = list_to_array(list);
    cr_assert_not_null(array);
    cr_assert_eq(array[0], str);
    cr_assert_null(array[1]);
    free(array);
    list_destroy(list);
}

Test(list_to_array, list_to_array_3)
{
    list_t *list = list_create(NULL);
    char *str = "azerty";
    void **array;

    list_add(list, NULL);
    list_add(list, NULL);
    list_add(list, str);
    list_add(list, NULL);
    list_add(list, str);
    array = list_to_array(list);
    cr_assert_not_null(array);
    cr_assert_eq(array[0], NULL);
    cr_assert_eq(array[1], NULL);
    cr_assert_eq(array[2], str);
    cr_assert_eq(array[3], NULL);
    cr_assert_eq(array[4], str);
    cr_assert_null(array[5]);
    free(array);
    list_destroy(list);
}

Test(list_to_array, list_to_array_4)
{
    list_t *list = list_create(NULL);
    void **array;

    list_add(list, "azerty");
    list_add(list, "qwerty");
    list_add(list, NULL);
    list_add(list, "abc");
    array = list_to_array(list);
    cr_assert_not_null(array);
    cr_assert_str_eq(array[0], "azerty");
    cr_assert_str_eq(array[1], "qwerty");
    cr_assert_eq(array[2], NULL);
    cr_assert_str_eq(array[3], "abc");
    cr_assert_null(array[4]);
    free(array);
    list_destroy(list);
}