//
// Created by Soso Janashvili on 01.09.2020.
//

#include "../inc/uls.h"

int main(int argc, char **argv) {

    t_main main;

    mx_parse_data(&main, argc, argv);

    //mx_list_files(".", 0);

    for (int i = 0; main.dirs[i] != NULL; i++) {

        if (!mx_file_exists(main.dirs[i])) {
            mx_error_no_such_file(main.dirs[i]);
            continue;
        }

        if (mx_is_regular_file(main.dirs[i])) {
            mx_printstr(main.dirs[i]);
            mx_printstr("\n\n");
        }

        mx_list_files(&main, main.dirs[i], 0);
    }

    mx_alloc_clean_up(&main);
    return 0;
}
