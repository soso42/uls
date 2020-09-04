//
// Created by Soso Janashvili on 04.09.2020.
//

#include "../inc/uls.h"

static void print_error_message(const char *ch);

void mx_check_flags(char **argv) {

    char *params = NULL;

    if (!argv[1] || argv[1][0] != '-')
        return;

    if (argv[1] != NULL && argv[1][0] == '-')
        params = argv[1];

    if (params[1] == '\0')
        return;

    for (int i = 1; params[i]; i++) {
        if (mx_get_char_index(ARGUMENTS, params[i]) < 0)
            print_error_message(&params[i]);
    }

}

static void print_error_message(const char *ch) {
    mx_printerror("uls illegal option -- ");
    mx_printerror(ch);
    mx_printerror("\nusage: uls [-ACGRSTaclmrtu1] [file ...]\n");
    exit(1);
}
