# List-library
List library in C

## Build

To build and install:

```
mkdir build
cd build
meson ..
meson install
```

To test:

```
mkdir build
cd build
meson -Dtests=true ..
meson test

```

Or, you may just use `Makefile` to do it all by hand.

## Method Summary

### List :

Return a new list object, or `NULL` if it failed

```
list_t *list_create(void (*destructor)(void *));

(destructor : Destruct object function (as `free` for `malloc`) and `NULL` for nothing)
```

Destroy list and all objects with the list destructor

```
void *list_destroy(list_t *list);
```

Returns a full copy of this list, or `NULL` if it failed
```
list_t *list_clone(list_t *list);
```

Returns an array containing all of the elements in this list (from first to last element).
```
void **list_to_array(list_t *list);
```

### Add :

Appends the specified element to the end of this list

```
int list_add(list_t *list, void *data);
```

Inserts the specified element at the specified position in this list

```
int list_add_at(list_t *list, void *data, int index);
```

### Remove :

Removes the element at the specified position in this list and destroy it
```
int list_remove(list_t *list, int index);
```

Removes the first occurrence of the specified element from this list
```
int list_remove_data(list_t *list, void *data);
```

Removes all occurrence of the specified element from this list
```
int list_remove_all_data(list_t *list, void *data);
```

Removes from this list all of the elements whose index is between index_from, inclusive, and index_to, exclusive
```
int list_remove_range(list_t *list, int index_from, int index_to);
```

Removes from this list all of the elements whose index is not between index_from, inclusive, and index_to, exclusive
```
int list_sub_list(list_t *list, int index_from, int index_to);
```

Removes all of the elements from this list
```
int list_clear(list_t *list);
```

### Replace :

Replaces the element at the specified position in this list with the specified element without destroy
```
int list_set(list_t *list, void *data, int index);
```

Replaces the element at the specified position in this list with the specified element and destroy it with the list destructor
```
int list_replace(list_t *list, void *data, int index);
```
### Order :

Reverse order of list
```
int list_reverse(list_t *list);
```

### Get :

Returns the element at the specified position in this list
```
void *list_get(list_t *list, int index);
```

Returns the number of elements in this list
```
int list_get_size(list_t *list);
```

Returns 1 if this list contains no elements and 0 else
```
int list_is_empty(list_t *list
```

Returns 1 if this list contains the specified element and 0 else
```
int list_contain(list_t *list, void *data);
```

Returns the number of elements occurrence in this list
```
int list_count(list_t *list, void *data);
```

Returns the index of the first occurrence of the specified element in list or -1 if this list does not contain the element
```
int list_index_of(list_t *list, void *data);
```

Returns the index of the last occurrence of the specified element in list or -1 if this list does not contain the element
```
int list_last_index_of(list_t *list, void *data);
```

### Destructor :

Get destructor

```
void *list_get_destructor(list_t *list);
```

Set destructor

```
int list_set_destructor(list_t *list, void (*destructor)(void *));
```

## System Functions Used:
malloc and free
