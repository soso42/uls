//
// Created by Soso Janashvili on 08.09.2020.
//

#include "../inc/uls.h"

void mx_fl_pop_front(t_filelist **head) {

    t_filelist *temp = NULL;

    if (*head == NULL || head == NULL)
        return;

    temp = (*head)->next;
    free(*head);
    *head = temp;
}
