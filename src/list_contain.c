#include <stddef.h>
#include "list.h"

int list_contain(list_t *list, void *data)
{
    simple_list_t *element;

    if (!list)
        return (0);
    element = list->list;
    while (element) {
        if (element->data == data)
            return (1);
        element = element->next;
    }
    return (0);
}