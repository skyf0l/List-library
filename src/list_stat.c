#include <stddef.h>
#include "list.h"

int list_get_size(list_t *list)
{
    if (!list)
        return (0);
    return (list->size);
}

int list_is_empty(list_t *list)
{
    if (!list)
        return (1);
    if (list->size == 0)
        return (1);
    return (0);
}