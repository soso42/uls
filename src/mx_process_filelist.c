//
// Created by Soso Janashvili on 02.09.2020.
//

#include "../inc/uls.h"

void mx_process_filelist(t_main *main, char *path) {

    DIR *ddd;
    struct dirent *dirrr;
    t_filelist *filelist = NULL;

    ddd = opendir(path);

    while ((dirrr = readdir(ddd)) != NULL) {
        if (filelist == NULL) {
            filelist = mx_fl_create_node(mx_strdup(dirrr->d_name));
        }
        else {
            mx_fl_push_back(&filelist, mx_strdup(dirrr->d_name));
        }
    }

    mx_sort_filelist(main, filelist);
    mx_format_output(main, filelist);

    mx_delete_filelist(filelist);
    closedir(ddd);
}
