#include <criterion/criterion.h>
#include "list.h"

Test(list_get_destructor, null)
{
    list_t *list = NULL;

    cr_assert_eq(list_get_destructor(list), NULL);
    list_destroy(list);
}

Test(list_get_destructor, destructor_null)
{
    list_t *list = list_create(NULL);

    cr_assert_eq(list_get_destructor(list), NULL);
    list_destroy(list);
}

Test(list_get_destructor, destructor_free)
{
    list_t *list = list_create(&free);

    cr_assert_eq(list_get_destructor(list), &free);
    list_destroy(list);
}

Test(list_set_destructor, null)
{
    list_t *list = NULL;
    int return_value;

    return_value = list_set_destructor(list, NULL);
    cr_assert_eq(return_value, 1);
    list_destroy(list);
}

Test(list_set_destructor, set_to_null)
{
    list_t *list = list_create(&free);
    int return_value;

    return_value = list_set_destructor(list, NULL);
    cr_assert_eq(return_value, 0);
    cr_assert_null(list->destructor);
    list_destroy(list);
}

Test(list_set_destructor, set_to_free)
{
    list_t *list = list_create(NULL);
    int return_value;

    return_value = list_set_destructor(list, &free);
    cr_assert_eq(return_value, 0);
    cr_assert_eq(list->destructor, &free);
    list_destroy(list);
}