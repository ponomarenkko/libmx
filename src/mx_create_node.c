#include "libmx.h"

t_list *mx_create_node(void *data)
{
    t_list *node = (t_list *)malloc(16);

    node->data = data;
    node->next = NULL;

    return node;
}
