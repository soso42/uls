//
// Created by Soso Janashvili on 02.09.2020.
//

#include "../inc/uls.h"

void mx_print_content(char *path) {
    DIR *d;
    struct dirent *dir;

    d = opendir(path);
    dir = readdir(d);

    mx_printstr(dir->d_name);
    mx_printstr(":\n");

    closedir(d);
    d = opendir(path);

    while ((dir = readdir(d)) != NULL) {
        mx_printstr(dir->d_name);
        mx_printstr("   ");
    }
    mx_printstr("\n");
}

//static bool
