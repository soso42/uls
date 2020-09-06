//
// Created by Soso Janashvili on 06.09.2020.
//

#include "../inc/uls.h"

t_filelist *mx_fl_create_node(char *filename) {

    t_filelist *lst = malloc(sizeof(t_list));

    if (!lst) return NULL;

    lst->filename = filename;
    lst->next = NULL;

    return lst;
}
