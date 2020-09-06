//
// Created by Soso Janashvili on 06.09.2020.
//

#include "../inc/uls.h"

void mx_print_format_one(t_main *main, t_filelist *filelist) {

    for (t_filelist *cur = filelist; cur != NULL; cur = cur->next) {

        if (cur->filename != NULL)
            mx_printstr((cur->filename));
        if (cur->next != NULL)
            mx_printstr("\n");
    }
    mx_printstr("\n");
}
