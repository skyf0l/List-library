#include <stddef.h>
#include "list.h"

int list_count(list_t *list, void *data)
{
    simple_list_t *element;
    int occurrence = 0;

    if (!list)
        return (-1);
    element = list->list;
    while (element) {
        if (element->data == data)
            occurrence++;
        element = element->next;
    }
    return (occurrence);
}