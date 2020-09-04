//
// Created by Soso Janashvili on 01.09.2020.
//

#include "../inc/uls.h"

void mx_list_dir(char *path);

int main(int argc, char **argv) {

    mx_printint(mx_is_folder("CMakeFiles")); // For debugging

    t_main strct;

    mx_parse_data(&strct, argv);

    mx_list_dir(".");

    mx_alloc_clean_up(&strct);
    return 0;
}

void mx_list_dir(char *path) {

    DIR *d;
    struct dirent *dir;

    mx_print_content(path);

//    d = opendir(path);
//    if (d) {
//        while ((dir = readdir(d)) != NULL) {
//            mx_printstr(dir->d_name);
//
//            DIR *dd;
//            dd = opendir(dir->d_name);
//            if ((readdir(dd)) != NULL)
//                if (mx_strcmp(dir->d_name, ".") != 0 &&
//                    mx_strcmp(dir->d_name, "..") != 0)
//                    mx_list_dir(dir->d_name);
//
//            mx_printstr("\n\n");
//        }
//        closedir(d);
//    }
}
