//
// Created by Soso Janashvili on 06.09.2020.
//

#include "../../inc/uls.h"

void mx_error_no_such_file(char *filename) {
    mx_printstr("ls: ");
    mx_printstr(filename);
    mx_printstr(": No such file or directory\n");
}
