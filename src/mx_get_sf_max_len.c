/*
 * Function mx_get_sf_max_len() receives file list (linked list t_filelist)
 * as an argument, runs through it and gets the number of chars from biggest
 * file size. For example:
 * If biggest file size is 104768 it returns 6.
 * If biggest file size is 1509 it return 4.
 * This is required to correctly display data using ls -l
 */

#include "../inc/uls.h"

static int nbr_len(int nbr);

int mx_get_sf_max_len(t_filelist *filelist, char *path) {

    int max_len = 0;
    int temp;
    char *str1 = NULL;
    char *str2 = NULL;

    for (t_filelist *cur = filelist; cur != NULL; cur = cur->next) {

        str1 = mx_strjoin(path, "/");
        str2 = mx_strjoin(str1, cur->filename);

        temp = nbr_len((int)mx_fsize(str2));
        if (temp > max_len)
            max_len = temp;

        free(str1);
        free(str2);
    }

    return max_len;
}

static int nbr_len(int nbr) {
    int len;

    len = 0;
    if (nbr == 0)
        return (1);
    if (nbr < len)
        len += 1;
    while (nbr != 0)
    {
        nbr = nbr / 10;
        len++;
    }
    return (len);
}
