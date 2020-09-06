//
// Created by Soso Janashvili on 06.09.2020.
//

#include "../inc/uls.h"

void mx_fl_push_back(t_filelist **list, char *filename) {

    t_filelist *node = *list;

    if (node == NULL) {
        *list = mx_fl_create_node(filename);
        return;
    }

    while (node->next != NULL) {
        node = node->next;
    }

    node->next = mx_fl_create_node(filename);
}
