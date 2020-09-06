//
// Created by Soso Janashvili on 06.09.2020.
//

#include "../inc/uls.h"

t_list *mx_create_node(void *data) {

    t_list *lst = malloc(sizeof(t_list));

    if (!lst) return NULL;

    lst->data = data;
    lst->next = NULL;

    return lst;
}
