//
// Created by Soso Janashvili on 07.09.2020.
//

#include "../inc/uls.h"

static void remove_hidden_files(t_filelist **head_ref);

void mx_filter_filelist(t_main *main, t_filelist *filelist) {

    remove_hidden_files(&filelist);

}

static void remove_hidden_files(t_filelist **head_ref) {

    // Store head node
    t_filelist *temp = *head_ref;
    t_filelist *prev = NULL;


    // If head node itself holds the key to be deleted
    if (temp != NULL && temp->filename[0] == 'u') {
        *head_ref = temp->next;   // Changed head
        free(temp);               // free old head
        return;
    }


    for (t_filelist *cur = *head_ref; cur != NULL; cur = cur->next) {

        temp = cur;
        // Search for the key to be deleted, keep track of the
        // previous node as we need to change 'prev->next'
        if (temp->filename[0] != 'u')
        {
            prev = temp;
            temp = temp->next;
        }


        // Unlink the node from linked list
        prev->next = temp->next;

        free(temp);  // Free memory

    }

}
