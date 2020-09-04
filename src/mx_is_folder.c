//
// Created by Soso Janashvili on 04.09.2020.
//

#include "../inc/uls.h"

int mx_is_folder(const char *filename) {
    struct stat path_stat;
    stat(filename, &path_stat);
    return S_ISDIR(path_stat.st_mode);
}
