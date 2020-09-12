/*
 * Function mx_fsize() gets a file name as an argument
 * and returns file size..
 * off_t can be casted to int
 */

#include "../inc/uls.h"

off_t mx_fsize(const char *filename) {
    struct stat st;

    if (stat(filename, &st) == 0)
        return st.st_size;

    return -1;
}
