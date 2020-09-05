//
// Created by Soso Janashvili on 01.09.2020.
//

#include "../inc/uls.h"

int main(int argc, char **argv) {

    t_main strct;

    mx_parse_data(&strct, argv);

    mx_list_files(".", 0);

    mx_alloc_clean_up(&strct);
    return 0;
}
