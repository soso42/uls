//
// Created by Soso Janashvili on 07.09.2020.
//

#include "../inc/uls.h"

void mx_format_output(t_main *main, t_filelist *filelist) {

    if (mx_get_char_index(main->flags, '1') > 0)
        mx_print_format_one(main, filelist);
    else if (mx_get_char_index(main->flags, 'l') > 0)
        mx_print_format_details(main, filelist);
    else
        mx_print_format_standard(main, filelist);

}
