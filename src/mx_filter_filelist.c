//
// Created by Soso Janashvili on 07.09.2020.
//

#include "../inc/uls.h"

static void remove_hidden_files(t_filelist **head_ref);
//static void remove_dots(t_filelist *head_ref);

void mx_filter_filelist(t_main *main, t_filelist *filelist) {

    remove_hidden_files(&filelist);
    //remove_dots(filelist);

}

static void remove_hidden_files(t_filelist **head_ref) {


    t_filelist *temp = *head_ref;
    t_filelist *prev = NULL;
    int n = mx_get_n_nodes(*head_ref);

    //for (t_filelist *cur = *head_ref; cur != NULL; cur = cur->next) {
    for (int i = 0; i < n; i++) {

        //temp = cur;
        // Search for the key to be deleted, keep track of the
        // previous node as we need to change 'prev->next'

        if (prev == NULL && temp->filename[0] == '.') {
            *head_ref = temp->next;   // Changed head
            free(temp);               // free old head
            temp = *head_ref;
            continue;
        }

        if (prev && temp->filename[0] == '.') {
            prev->next = temp->next;
            free(temp);  // Free memory
            temp = prev->next;
            //*head_ref = prev->next;
            continue;
        }

//        if (temp->filename[0] != 'u' && temp->next == NULL) {
//            prev->next = NULL;
//            free(temp);  // Free memory
//        }
//        temp = temp->next;
//
//        prev = temp;
        prev = temp;
        temp = temp->next;

    }
    int x;
}

//static void remove_dots(t_filelist *head_ref) {
//
//    t_filelist *temp = head_ref;
//
////    head_ref = head_ref->next;
////    free(temp);
////    temp = head_ref;
////    head_ref = head_ref->next;
////    free(temp);
//
//    head_ref = head_ref->next;
//}
