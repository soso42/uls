//
// Created by ss on 9/12/20.
//

#include "../inc/uls.h"

void mx_print_m_time(struct stat *file_stat) {
    char *str = NULL;

    time_t modtime = time(&file_stat->st_mtime);
    str = mx_strndup(ctime(&modtime) + 4, 12);
    mx_printstr(str);

    free(str);
}
