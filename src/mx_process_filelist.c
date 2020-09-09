//
// Created by Soso Janashvili on 02.09.2020.
//

#include "../inc/uls.h"

t_filelist *mx_create_filelist(t_main *main, char *path);
t_filelist *get_all_files(char *path);
t_filelist *get_all_hidden(char *path);
t_filelist *get_only_visible(char *path);

void mx_process_filelist(t_main *main, char *path) {

    // First, create a filelist from the "path" directory
    t_filelist *filelist = NULL;

    filelist = mx_create_filelist(main, path);

    // Sort filelist according to flags
    mx_sort_filelist(main, filelist);

    // If -a -A flags are present, remove .hidden dirs and "." ".."
    //mx_filter_filelist(main, filelist);

    // For mat output according to flags and print it
    mx_format_output(main, filelist);

    // Delete the filelist and free memory
    mx_delete_filelist(filelist);
}

t_filelist *mx_create_filelist(t_main *main, char *path) {

    t_filelist *filelist = NULL;

    if (mx_get_char_index(main->flags, 'A') > 0) {
        filelist = get_all_hidden(path);
    } else if (mx_get_char_index(main->flags, 'a') > 0) {
        filelist = get_all_files(path);
    } else {
        filelist = get_only_visible(path);
    }

    return filelist;
}

t_filelist *get_all_files(char *path) {
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

t_filelist *get_all_hidden(char *path) {
    DIR *ddd;
    struct dirent *dirrr;
    t_filelist *filelist = NULL;

    ddd = opendir(path);

    while ((dirrr = readdir(ddd)) != NULL) {
        if (mx_strcmp(dirrr->d_name, ".") != 0 && mx_strcmp(dirrr->d_name, "..") != 0) {
            if (filelist == NULL) {
                filelist = mx_fl_create_node(mx_strdup(dirrr->d_name));
            }
            else {
                mx_fl_push_back(&filelist, mx_strdup(dirrr->d_name));
            }
        }
    }

    closedir(ddd);
    return filelist;
}

t_filelist *get_only_visible(char *path) {
    DIR *ddd;
    struct dirent *dirrr;
    t_filelist *filelist = NULL;

    ddd = opendir(path);

    while ((dirrr = readdir(ddd)) != NULL) {
        if (dirrr->d_name[0] != '.')  {
            if (filelist == NULL) {
                filelist = mx_fl_create_node(mx_strdup(dirrr->d_name));
            }
            else {
                mx_fl_push_back(&filelist, mx_strdup(dirrr->d_name));
            }
        }
    }

    closedir(ddd);
    return filelist;
}
