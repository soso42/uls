//
// Created by Soso Janashvili on 05.09.2020.
//

#include "../inc/uls.h"

void mx_list_files(char *basePath, int root) {

    DIR *dir;
    struct dirent *entry;
    char path[1024];

    if (!(dir = opendir(basePath)))
        return;

    mx_print_content(basePath);

//    while ((entry = readdir(dir)) != NULL) {
//        if (entry->d_type == DT_DIR) {
//
//            if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
//                continue;
//
//            strcpy(path, basePath);
//            strcat(path, "/");
//            strcat(path, entry->d_name);
//
//            //printf("%*s[%s]\n", root, "", entry->d_name);
//
//            mx_printstr(path);
//            mx_printstr("\n");
//
//            mx_list_files(path, root + 2);
//
//        }
////        else {
////            printf("%*s- %s\n", root, "", entry->d_name);     // Prints reg. files
////        }
//    }

    closedir(dir);
}
