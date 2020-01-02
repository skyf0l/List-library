#include <criterion/criterion.h>
#include "list.h"
#include "private_list.h"

Test(get_element, null)
{
    list_t *list = NULL;

    cr_assert_null(get_element(list, 0));
    list_destroy(list);
}

Test(list_get, null)
{
    list_t *list = NULL;

    cr_assert_null(list_get(list, 0));
    list_destroy(list);
}

Test(list_get, empty)
{
    list_t *list = list_create(NULL);

    cr_assert_null(list_get(list, 0));
    list_destroy(list);
}

Test(list_get, out_of_range_1)
{
    list_t *list = list_create(NULL);

    list_add(list, "azerty");
    cr_assert_null(list_get(list, -1));
    list_destroy(list);
}

Test(list_get, out_of_range_2)
{
    list_t *list = list_create(NULL);

    list_add(list, "azerty");
    cr_assert_null(list_get(list, 2));
    list_destroy(list);
}

Test(list_get, get)
{
    list_t *list = list_create(NULL);
    char *result;

    list_add(list, "azerty");
    list_add(list, "qwerty");
    list_add(list, "abc");
    list_add(list, "123");
    result = (char *)list_get(list, 0);
    cr_assert_str_eq(result, "azerty");
    result = (char *)list_get(list, 1);
    cr_assert_str_eq(result, "qwerty");
    result = (char *)list_get(list, 2);
    cr_assert_str_eq(result, "abc");
    result = (char *)list_get(list, 3);
    cr_assert_str_eq(result, "123");
    list_destroy(list);
}