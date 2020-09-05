//
// Created by Soso Janashvili on 02.09.2020.
//

#include "../inc/uls.h"

void mx_print_content(char *path) {

    DIR *ddd;
    struct dirent *dirrr;

    ddd = opendir(path);

    while ((dirrr = readdir(ddd)) != NULL) {
        if (mx_strcmp(dirrr->d_name, ".") != 0 && mx_strcmp(dirrr->d_name, "..")) {
            mx_printstr(dirrr->d_name);
            mx_printstr("   ");
        }
    }
    mx_printstr("\n\n");
    closedir(ddd);
}
