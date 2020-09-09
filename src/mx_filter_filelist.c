//
// Created by Soso Janashvili on 07.09.2020.
//

#include "../inc/uls.h"


void remove_hidden_files(t_filelist *head_ref);
//static void remove_dots(t_filelist *head_ref);

void mx_filter_filelist(t_main *main, t_filelist *filelist) {

    remove_hidden_files(filelist);
    //remove_dots(filelist);

}

void remove_hidden_files(t_filelist *head_ref) {

    t_filelist *temp = head_ref;
    t_filelist *prev = NULL;
    int n = mx_get_n_nodes(head_ref);

    for (int i = 0; i < n; i++) {

        if (prev == NULL && temp->filename[0] == 'C') {
            head_ref = temp->next;   // Changed head
            free(temp);               // free old head
            temp = head_ref;
            continue;
        }

        if (prev && temp->filename[0] == 'C') {
            prev->next = temp->next;
            free(temp);  // Free memory
            temp = prev->next;
            //*head_ref = prev->next;
            continue;
        }

        prev = temp;
        temp = temp->next;
    }
}



/*
void remove_hidden_files(t_filelist **head_ref);
//static void remove_dots(t_filelist *head_ref);
void delete_node(t_filelist **head_ref);

void mx_filter_filelist(t_main *main, t_filelist *filelist) {

    remove_hidden_files(&filelist);
    //remove_dots(filelist);

}

void remove_hidden_files(t_filelist **head_ref) {


    t_filelist *temp = *head_ref;
    t_filelist *prev = NULL;
    int n = mx_get_n_nodes(*head_ref);


    for (int i = 0; i < n; i++) {

        delete_node(head_ref);

    }

}

void delete_node(t_filelist **head_ref) {
    // Store head node
    t_filelist *temp = *head_ref, *prev;

    // If head node itself holds the key to be deleted
    if (temp != NULL && temp->filename[0] == 'C')
    {
        *head_ref = temp->next;   // Changed head
        free(temp);               // free old head
        return;
    }

    // Search for the key to be deleted, keep track of the
    // previous node as we need to change 'prev->next'
    while (temp != NULL && temp->filename[0] != 'C')
    {
        prev = temp;
        temp = temp->next;
    }

    // If key was not present in linked list
    if (temp == NULL) return;

    // Unlink the node from linked list
    prev->next = temp->next;

    free(temp);  // Free memory
}
*/
