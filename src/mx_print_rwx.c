//
// Created by ss on 9/12/20.
//

#include "../inc/uls.h"

void mx_print_rwx(char *name) {
    char *result = mx_strdup("---------");
    struct stat sb;

    stat(name, &sb);

    for (int i = 0; i < 9; i++) {
        if ((i == 0) && (S_IRUSR == (S_IRUSR & sb.st_mode)))
            result[0] = 'r';
        if ((i == 1) && (S_IWUSR == (S_IWUSR & sb.st_mode)))
            result[1] = 'w';
        if ((i == 2) && S_IXUSR == (S_IXUSR & sb.st_mode))
            result[2] = 'x';
        if ((i == 3) && S_IRGRP == (S_IRGRP & sb.st_mode))
            result[3] = 'r';
        if ((i == 4) && S_IWGRP == (S_IWGRP & sb.st_mode))
            result[4] = 'w';
        if ((i == 5) && S_IXGRP == (S_IXGRP & sb.st_mode))
            result[5] = 'x';
        if ((i == 6) && S_IROTH == (S_IROTH & sb.st_mode))
            result[6] = 'r';
        if ((i == 7) && S_IWOTH == (S_IWOTH & sb.st_mode))
            result[7] = 'w';
        if ((i == 8) && S_IXOTH == (S_IXOTH & sb.st_mode))
            result[8] = 'x';
    }

    mx_printstr(result);
    free(result);
}
