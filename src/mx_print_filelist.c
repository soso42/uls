//
// Created by Soso Janashvili on 06.09.2020.
//

#include "../inc/uls.h"

void mx_print_filelist(t_list* head) {
    //mx_printstr("HEAD->");
    for (t_list *cur = head; cur != NULL; cur = cur->next) {
        //printf("[%d]->", *(int *)(cur->data));
        mx_printstr((char *)(cur->data));
        mx_printstr("  ->  ");
    }
    mx_printstr("NULL\n");
}
