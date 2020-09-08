//
// Created by Soso Janashvili on 08.09.2020.
//

#include "../inc/uls.h"

int mx_get_n_nodes(t_filelist *filelist) {
    int n = 0;
    for (t_filelist *temp = filelist; temp != NULL; temp = temp->next) {
        n++;
    }
    return n;
}
