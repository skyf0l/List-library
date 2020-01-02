#include <criterion/criterion.h>
#include "list.h"

Test(list_remove_data, null)
{
    int return_value;

    return_value = list_remove_data(NULL, 0);
    cr_assert_eq(return_value, 1);
}

Test(list_remove_data, empty)
{
    list_t *list = list_create(NULL);
    int return_value;

    return_value = list_remove_data(list, NULL);
    cr_assert_eq(return_value, 0);
    cr_assert_eq(list->size, 0);
    list_destroy(list);
}

Test(list_remove_data, not_exist)
{
    list_t *list = list_create(NULL);
    int return_value;

    return_value = list_remove_data(list, NULL);
    cr_assert_eq(return_value, 0);
    cr_assert_eq(list->size, 0);
    list_destroy(list);
}

Test(list_remove_data, remove_1)
{
    list_t *list = list_create(NULL);
    int return_value;

    list_add(list, NULL);
    return_value = list_remove_data(list, NULL);
    cr_assert_eq(return_value, 0);
    cr_assert_eq(list->size, 0);
    cr_assert_null(list->list);
    cr_assert_null(list->end);
    list_destroy(list);
}

Test(list_remove_data, remove_2)
{
    list_t *list = list_create(NULL);
    char *str = "azerty";
    int return_value;

    list_add(list, NULL);
    return_value = list_remove_data(list, str);
    cr_assert_eq(return_value, 0);
    cr_assert_eq(list->size, 1);
    cr_assert_eq(list->list->data, NULL);
    cr_assert_eq(list->list, list->end);
    list_destroy(list);
}

Test(list_remove_data, remove_3)
{
    list_t *list = list_create(NULL);
    char *str = "azerty";
    int return_value;

    list_add(list, str);
    return_value = list_remove_data(list, str);
    cr_assert_eq(return_value, 0);
    cr_assert_eq(list->size, 0);
    cr_assert_null(list->list);
    cr_assert_null(list->end);
    list_destroy(list);
}

Test(list_remove_data, remove_4)
{
    list_t *list = list_create(NULL);
    char *str = "azerty";
    int return_value;

    list_add(list, str);
    list_add(list, NULL);
    list_add(list, str);
    return_value = list_remove_data(list, str);
    cr_assert_eq(return_value, 0);
    cr_assert_eq(list->size, 2);
    cr_assert_eq(list->list->data, NULL);
    cr_assert_eq(list->list->next->data, str);
    cr_assert_eq(list->list->next, list->end);
    cr_assert_eq(list->end->prev, list->list);
    list_destroy(list);
}

Test(list_remove_data, remove_5)
{
    list_t *list = list_create(NULL);
    char *str = "azerty";
    int return_value;

    list_add(list, NULL);
    list_add(list, str);
    list_add(list, NULL);
    return_value = list_remove_data(list, str);
    cr_assert_eq(return_value, 0);
    cr_assert_eq(list->size, 2);
    cr_assert_eq(list->list->data, NULL);
    cr_assert_eq(list->list->next->data, NULL);
    cr_assert_eq(list->list->next, list->end);
    cr_assert_eq(list->end->prev, list->list);
    list_destroy(list);
}

Test(list_remove_data, remove_6)
{
    list_t *list = list_create(NULL);
    char *str = "azerty";
    int return_value;

    list_add(list, NULL);
    list_add(list, NULL);
    list_add(list, str);
    return_value = list_remove_data(list, str);
    cr_assert_eq(return_value, 0);
    cr_assert_eq(list->size, 2);
    cr_assert_eq(list->list->data, NULL);
    cr_assert_eq(list->list->next->data, NULL);
    cr_assert_eq(list->list->next, list->end);
    cr_assert_eq(list->end->prev, list->list);
    list_destroy(list);
}

Test(list_remove_all_data, null)
{
    int return_value;

    return_value = list_remove_all_data(NULL, 0);
    cr_assert_eq(return_value, 1);
}

Test(list_remove_all_data, empty)
{
    list_t *list = list_create(NULL);
    int return_value;

    return_value = list_remove_all_data(list, NULL);
    cr_assert_eq(return_value, 0);
    cr_assert_eq(list->size, 0);
    list_destroy(list);
}

Test(list_remove_all_data, not_exist)
{
    list_t *list = list_create(NULL);
    int return_value;

    return_value = list_remove_all_data(list, NULL);
    cr_assert_eq(return_value, 0);
    cr_assert_eq(list->size, 0);
    list_destroy(list);
}

Test(list_remove_all_data, remove_all_1)
{
    list_t *list = list_create(NULL);
    int return_value;

    list_add(list, NULL);
    return_value = list_remove_all_data(list, NULL);
    cr_assert_eq(return_value, 0);
    cr_assert_eq(list->size, 0);
    cr_assert_null(list->list);
    cr_assert_null(list->end);
    list_destroy(list);
}

Test(list_remove_all_data, remove_all_2)
{
    list_t *list = list_create(NULL);
    int return_value;

    list_add(list, NULL);
    list_add(list, NULL);
    list_add(list, NULL);
    return_value = list_remove_all_data(list, NULL);
    cr_assert_eq(return_value, 0);
    cr_assert_eq(list->size, 0);
    cr_assert_null(list->list);
    cr_assert_null(list->end);
    list_destroy(list);
}

Test(list_remove_all_data, remove_all_3)
{
    list_t *list = list_create(NULL);
    char *str = "azerty";
    int return_value;

    list_add(list, str);
    return_value = list_remove_all_data(list, str);
    cr_assert_eq(return_value, 0);
    cr_assert_eq(list->size, 0);
    cr_assert_null(list->list);
    cr_assert_null(list->end);
    list_destroy(list);
}

Test(list_remove_all_data, remove_all_4)
{
    list_t *list = list_create(NULL);
    char *str = "azerty";
    int return_value;

    list_add(list, str);
    list_add(list, str);
    list_add(list, str);
    return_value = list_remove_all_data(list, str);
    cr_assert_eq(return_value, 0);
    cr_assert_eq(list->size, 0);
    cr_assert_null(list->list);
    cr_assert_null(list->end);
    list_destroy(list);
}