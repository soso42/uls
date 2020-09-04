//
// Created by Soso Janashvili on 01.09.2020.
//

#include "../inc/libmx.h"

static char *mx_do_replace(const char *str, const char *sub, const char *replace, int i);

char *mx_replace_substr(const char *str, const char *sub, const char *replace) {
    int i = 0;
    char *result = NULL;
    char *temp = NULL;

    if (!str || !sub || !replace)
        return NULL;

    result = mx_strdup(str);

    while (str[i]) {
        if (mx_strncmp(&result[i], sub, mx_strlen(sub)) == 0) {
            temp = mx_do_replace(result, sub, replace, i);
            free(result);
            result = mx_strdup(temp);
            free(temp);
        }
        i++;
    }
    return result;
}

static char *mx_do_replace(const char *str, const char *sub, const char *replace, int i) {

    char *beg = NULL;
    char *end = NULL;
    char *result = NULL;
    char *temp = NULL;
    int len = mx_strlen(sub);

    beg = mx_strndup(str, i);
    end = mx_strdup(str + i + len);

    temp = mx_strjoin(beg, replace);
    result = mx_strjoin(temp, end);

    free(beg);
    free(end);
    free(temp);
    return result;
}
