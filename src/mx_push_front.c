#include "libmx.h"

void mx_push_front(t_list **list, void *data) {
    t_list *front_list = mx_create_node(data);
    t_list *tmp = NULL;
    
    if (list == NULL || *list == NULL){
        *list = front_list;
    }
    else {
        tmp = *list;
        *list = front_list;
        front_list->next = tmp;
    }
}
