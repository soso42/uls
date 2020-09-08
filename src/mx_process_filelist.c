//
// Created by Soso Janashvili on 02.09.2020.
//

#include "../inc/uls.h"

t_filelist *mx_create_filelist(t_main *main, char *path);

void mx_process_filelist(t_main *main, char *path) {

    // First, create a filelist from the "path" directory
    t_filelist *filelist = mx_create_filelist(main, path);

    // Sort filelist according to flags
    mx_sort_filelist(main, filelist);

    // If -a -A flags are present, remove .hidden dirs and "." ".."
    mx_filter_filelist(main, filelist);

    // For mat output according to flags and print it
    mx_format_output(main, filelist);

    // Delete the filelist and free memory
    mx_delete_filelist(filelist);
}

t_filelist *mx_create_filelist(t_main *main, char *path) {
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

    closedir(ddd);
    return filelist;
}
