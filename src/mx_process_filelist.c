//
// Created by Soso Janashvili on 02.09.2020.
//

#include "../inc/uls.h"

void mx_process_filelist(char *path) {

    DIR *ddd;
    struct dirent *dirrr;
    t_list *head = NULL;

    ddd = opendir(path);

    while ((dirrr = readdir(ddd)) != NULL) {
        if (mx_strcmp(dirrr->d_name, ".") != 0 && mx_strcmp(dirrr->d_name, "..")) {
            mx_printstr(dirrr->d_name);
            mx_printstr("   ");
        }
    }
    mx_printstr("\n\n");

//    ddd = opendir(path);

//    while ((dirrr = readdir(ddd)) != NULL) {
//        if (head == NULL)
//            head = mx_create_node((char *)dirrr->d_name);
//        else
//            mx_push_front(&head, (char *)dirrr->d_name);
//    }
//
    mx_print_filelist(head);

    closedir(ddd);
}
