//
// Created by Soso Janashvili on 07.09.2020.
//

#include "../inc/uls.h"

static void remove_hidden_files(t_filelist *filelist);

void mx_filter_filelist(t_main *main, t_filelist *filelist) {

    remove_hidden_files(filelist);

}

static void remove_hidden_files(t_filelist *filelist) {

    char *str = NULL;

    for (t_filelist *cur = filelist; cur != NULL; cur = cur->next) {
        str = cur->filename;
        if (str[0] == '.') {
            cur->next = cur->next->next;
            cur = cur->next;
        }
        mx_printstr(str);
        mx_printstr("\n");
    }
    mx_printstr("\n\n\n\n");
}
