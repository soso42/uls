//
// Created by Soso Janashvili on 06.09.2020.
//

#include "../inc/uls.h"

void mx_print_filelist(t_filelist* filelist) {

    for (t_filelist *cur = filelist; cur != NULL; cur = cur->next) {
        mx_printstr((cur->filename));
        mx_printstr("  ->  ");
    }
    mx_printstr("NULL\n");
}
