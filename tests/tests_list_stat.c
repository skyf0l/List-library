#include <criterion/criterion.h>
#include "list.h"

Test(list_is_empty, empty)
{
    list_t *list = list_create(NULL);

    int is_empty = list_is_empty(list);
    cr_assert_eq(is_empty, 1);
    list_destroy(list);
}

Test(list_is_empty, null)
{
    int is_empty = list_is_empty(NULL);
    cr_assert_eq(is_empty, 1);
}

Test(list_is_empty, not_empty)
{
    list_t *list = list_create(NULL);

    list_add(list, "azerty");
    int is_empty = list_is_empty(list);
    cr_assert_eq(is_empty, 0);
    list_destroy(list);
}

Test(list_get_size, empty)
{
    list_t *list = list_create(NULL);

    int size = list_get_size(list);
    cr_assert_eq(size, 0);
    list_destroy(list);
}

Test(list_get_size, null)
{
    int size = list_get_size(NULL);
    cr_assert_eq(size, 0);
}

Test(list_get_size, not_empty)
{
    list_t *list = list_create(NULL);

    list_add(list, "azerty");
    list_add(list, "qwerty");
    int size = list_get_size(list);
    cr_assert_eq(size, 2);
    list_destroy(list);
}