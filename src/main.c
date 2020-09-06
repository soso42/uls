//
// Created by Soso Janashvili on 01.09.2020.
//

#include "../inc/uls.h"

int main(int argc, char **argv) {

    t_main main;

    mx_parse_data(&main, argv);

    //mx_list_files(".", 0);

    for (int i = 0; main.dirs[i]; i++)
        mx_list_files(main.dirs[i], 0);


    mx_alloc_clean_up(&main);
    return 0;
}
