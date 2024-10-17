#include "libmx.h"

void *mx_realloc(void *ptr, size_t size)
{
    if (size == 0) {
        free(ptr);
        return NULL;
    }

    if (ptr == NULL)
        return malloc(size);

    void *new_ptr = malloc(size);
    if (new_ptr == NULL)
        return NULL;

    mx_memmove(new_ptr, ptr, size);
    free(ptr);

    return new_ptr;
}
