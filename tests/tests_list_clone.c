#include <criterion/criterion.h>
#include <stdlib.h>
#include "list.h"

Test(list_clone, null)
{
    list_t *clone;

    clone = list_clone(NULL);
    cr_assert_null(clone);
}

Test(list_clone, empty_null_destructor)
{
    list_t *list = list_create(NULL);
    list_t *clone;

    clone = list_clone(list);
    list_destroy(list);
    cr_assert_not_null(clone);
    cr_assert_eq(clone->size, 0);
    cr_assert_eq(clone->destructor, NULL);
    cr_assert_null(clone->list);
    cr_assert_null(clone->end);
    list_destroy(clone);
}

Test(list_clone, empty_free_destructor)
{
    list_t *list = list_create(&free);
    list_t *clone;

    clone = list_clone(list);
    list_destroy(list);
    cr_assert_not_null(clone);
    cr_assert_eq(clone->size, 0);
    cr_assert_eq(clone->destructor, &free);
    cr_assert_null(clone->list);
    cr_assert_null(clone->end);
    list_destroy(clone);
}

Test(list_clone, clone_1)
{
    list_t *list = list_create(NULL);
    list_t *clone;

    list_add(list, "azerty");
    clone = list_clone(list);
    list_destroy(list);
    cr_assert_not_null(clone);
    cr_assert_eq(clone->size, 1);
    cr_assert_eq(clone->destructor, NULL);
    cr_assert_str_eq(clone->list->data, "azerty");
    cr_assert_eq(clone->list, clone->end);
    list_destroy(clone);
}

Test(list_clone, clone_2)
{
    list_t *list = list_create(NULL);
    list_t *clone;

    list_add(list, "azerty");
    list_add(list, NULL);
    list_add(list, "qwerty");
    clone = list_clone(list);
    list_destroy(list);
    cr_assert_not_null(clone);
    cr_assert_eq(clone->size, 3);
    cr_assert_eq(clone->destructor, NULL);
    cr_assert_str_eq(clone->list->data, "azerty");
    cr_assert_eq(clone->list->next->data, NULL);
    cr_assert_str_eq(clone->list->next->next->data, "qwerty");
    cr_assert_eq(clone->list->next->next, clone->end);
    list_destroy(clone);
}