//
// Created by Soso Janashvili on 04.09.2020.
//

#include "../inc/uls.h"

int mx_file_exists(char *filename) {
    struct stat buffer;
    return (stat (filename, &buffer) == 0);
}
