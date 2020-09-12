//
// Created by Soso Janashvili on 04.09.2020.
//

#include "../inc/uls.h"

int mx_is_dir(const char *filename) {

    DIR *dir;
    struct dirent *entry;

    if (!(dir = opendir(filename)))
        return 0;

    if ((entry = readdir(dir)) != NULL)
        if (entry->d_type == DT_DIR) {
            closedir(dir);
            return 1;
        }

    closedir(dir);
    return 0;
}
