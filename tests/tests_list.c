#include <criterion/criterion.h>
#include "list.h"
#include "private_list.h"

Test(create_element, create_element)
{
    simple_list_t *element = create_element("azerty");

    cr_assert_not_null(element);
    cr_assert_str_eq(element->data, "azerty");
    cr_assert_eq(element->prev, NULL);
    cr_assert_eq(element->next, NULL);
    free(element);
}

Test(list_create, list_create_null_destructor)
{
    list_t *list = list_create(NULL);

    cr_assert_not_null(list);
    cr_assert_eq(list->size, 0);
    cr_assert_eq(list->destructor, NULL);
    cr_assert_null(list->list);
    cr_assert_null(list->end);
    list_destroy(list);
}

Test(list_create, list_create_free_destructor)
{
    list_t *list = list_create(&free);
    char *str = malloc(sizeof(char));

    str[0] = '\0';
    list_add(list, str);
    cr_assert_not_null(list);
    cr_assert_eq(list->destructor, &free);
    list_destroy(list);
}

Test(list_clear, null)
{
    list_t *list = NULL;
    int return_value;

    return_value = list_clear(list);
    cr_assert_eq(return_value, 1);
    list_destroy(list);
}

Test(list_clear, empty)
{
    list_t *list = list_create(NULL);
    int return_value;

    return_value = list_clear(list);
    cr_assert_eq(return_value, 0);
    list_destroy(list);
}

Test(list_clear, not_empty)
{
    list_t *list = list_create(NULL);
    int return_value;

    list_add(list, "azerty");
    return_value = list_clear(list);
    cr_assert_eq(return_value, 0);
    cr_assert_eq(list->size, 0);
    cr_assert_null(list->list);
    cr_assert_null(list->end);
    list_destroy(list);
}