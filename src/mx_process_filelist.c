//
// Created by Soso Janashvili on 02.09.2020.
//

#include "../inc/uls.h"

void mx_format_output(t_main *main, t_filelist *filelist);
void mx_sort_filelist(t_main *main, t_filelist *filelist);

void mx_process_filelist(t_main *main, char *path) {

    DIR *ddd;
    struct dirent *dirrr;
    t_filelist *filelist = NULL;

    ddd = opendir(path);

    while ((dirrr = readdir(ddd)) != NULL) {
        if (filelist == NULL)
            filelist = mx_fl_create_node(mx_strdup(dirrr->d_name));
        else
            mx_fl_push_back(&filelist, mx_strdup(dirrr->d_name));
    }

    mx_format_output(main, filelist);

    //mx_print_filelist(filelist);

    mx_delete_filelist(filelist);
    closedir(ddd);
}

void mx_format_output(t_main *main, t_filelist *filelist) {

    // First, sort file list
    mx_sort_filelist(main, filelist);

    if (mx_get_char_index(main->flags, '1') > 0)
        mx_print_format_one(main, filelist);
    else if (mx_get_char_index(main->flags, 'l') > 0)
        mx_print_format_details(main, filelist);
    else
        mx_print_format_standard(main, filelist);

}

void mx_sort_filelist(t_main *main, t_filelist *filelist) {

    // If r flag is present sort files in descending order
    // else in ascending
    if (mx_get_char_index(main->flags, 'r') > 0)
        mx_bubblesort_list_des(filelist);
    else
        mx_bubblesort_list_asc(filelist);

}
