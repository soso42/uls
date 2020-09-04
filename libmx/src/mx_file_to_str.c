#include "../inc/libmx.h"

static int get_str_length(const char *file);

char *mx_file_to_str(const char *file) {
    char *str = NULL;
    int len;
    int fd;

    if (!file)
        return NULL;

    fd = open(file, O_RDONLY);

    if (fd == -1)
        return NULL;

    len = get_str_length(file);
    if (!(str = mx_strnew(len)))
        return NULL;
    if (read(fd, str, len) == -1)
        return NULL;

    close(fd);
    return str;
}

static int get_str_length(const char *file) {

    int len = 0;
    char buf;
    int fd = open(file, O_RDONLY);

    while (read(fd, &buf, 1) > 0)
        len++;

    close(fd);
    return len;
}
