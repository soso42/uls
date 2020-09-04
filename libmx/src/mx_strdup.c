#include "../inc/libmx.h"

char *mx_strdup(const char *s1) {

    char *str = NULL;

    if (!(str = mx_strnew(mx_strlen(s1))))
        return NULL;

    if (!(str = mx_strcpy(str, s1)))
        return NULL;

    return str;
}
