//
// Created by Soso Janashvili on 05.09.2020.
//

#include "../inc/uls.h"

static void swap(t_filelist *a, t_filelist *b);

void mx_bubblesort_list_asc(t_filelist *head) {

    int swapped = 1;
    t_filelist *ptr1 = NULL;
    t_filelist *lptr = NULL;

    if (head == NULL)
        return;

    while (swapped) {

        swapped = 0;
        ptr1 = head;

        while (ptr1->next != lptr) {

            if (mx_strcmp(ptr1->filename, ptr1->next->filename) > 0) {
                swap(ptr1, ptr1->next);
                swapped = 1;
            }

            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    }
}

static void swap(t_filelist *a, t_filelist *b) {
    char *temp = a->filename;
    a->filename = b->filename;
    b->filename = temp;
}
