//
// Created by Soso Janashvili on 04.09.2020.
//

#include "../inc/uls.h"

void mx_parse_file_paths(t_main *main, char **argv) {

    int i = 0;
    main->dirs = (char **)malloc(100 * sizeof(char *));

    if (!argv[1] || argv[1][0] == '-')
        i = 2;
    else
        i = 1;

    for (int j = 0; argv[i]; j++) {

        if (!mx_file_exists(argv[i]))
            mx_error_no_such_file(argv[i]);

        main->dirs[j] = argv[i];
        i++;
    }
}
