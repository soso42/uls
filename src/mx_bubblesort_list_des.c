//
// Created by Soso Janashvili on 05.09.2020.
//

#include "../inc/uls.h"

static void swap(t_list *a, t_list *b);

void mx_bubblesort_list_des(t_list *head) {

    int swapped = 1;
    t_list *ptr1 = NULL;
    t_list *lptr = NULL;

    if (head == NULL)
        return;

    while (swapped) {

        swapped = 0;
        ptr1 = head;

        while (ptr1->next != lptr) {

            if (mx_strcmp((char *)ptr1->data, (char *)ptr1->next->data) < 0) {
                swap(ptr1, ptr1->next);
                swapped = 1;
            }

            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    }
}

static void swap(t_list *a, t_list *b) {
    int temp = (int)a->data;
    a->data = b->data;
    b->data = (void *)temp;
}
