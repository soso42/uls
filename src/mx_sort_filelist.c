//
// Created by Soso Janashvili on 07.09.2020.
//

#include "../inc/uls.h"

void mx_sort_filelist(t_main *main, t_filelist *filelist) {

    if (main->flags == NULL)
        return;

    // If r flag is present sort files in descending order
    // else in ascending
    if (mx_get_char_index(main->flags, 'r') > 0)
        mx_bubblesort_list_des(filelist);
    else
        mx_bubblesort_list_asc(filelist);

}
