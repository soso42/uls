//
// Created by Soso Janashvili on 06.09.2020.
//

#include "../inc/uls.h"

void mx_delete_filelist(t_filelist *filelist) {

    t_filelist *cur = NULL;

    while (filelist) {

        cur = filelist->next;

        mx_strdel(&filelist->filename);
        //mx_strdel(&filelist->user_name);

        if (filelist != NULL)
            free(filelist);

        filelist = cur;
    }

}
