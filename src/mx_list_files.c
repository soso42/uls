//
// Created by Soso Janashvili on 05.09.2020.
//

#include "../inc/uls.h"

void mx_list_files(char *basePath, int root) {

    DIR *dir;
    struct dirent *entry;

    if (!(dir = opendir(basePath)))
        return;

    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_DIR) {
            char path[1024];
            if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
                continue;
            snprintf(path, sizeof(path), "%s/%s", basePath, entry->d_name);
            printf("%*s[%s]\n", root, "", entry->d_name);
            mx_list_files(path, root + 2);
        } else {
            printf("%*s- %s\n", root, "", entry->d_name);
        }
    }
    closedir(dir);
}
