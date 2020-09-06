//
// Created by Soso Janashvili on 04.09.2020.
//

#include "../inc/uls.h"

void mx_parse_flags(t_main *main, char **argv) {

    char *params = NULL;

    if (!argv[1] || argv[1][0] != '-')
        return;

    if (argv[1] != NULL && argv[1][0] == '-')
        params = argv[1];

    if (params[1] == '\0')
        return;

    for (int i = 1; params[i]; i++) {
        if (mx_get_char_index(ARGUMENTS, params[i]) < 0)
            mx_error_illegal_option(&params[i]);
    }

    main->flags = argv[1];
}
