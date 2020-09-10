//
// Created by Soso Janashvili on 06.09.2020.
//

#include "../inc/uls.h"

void mx_print_format_details(t_main *main, t_filelist *filelist) {

    struct stat file_stat;

    for (t_filelist *cur = filelist; cur != NULL; cur = cur->next) {
        stat(cur->filename, &file_stat);

//        listxattr();

        mx_printstr("");

        mx_printstr(getpwuid(file_stat.st_uid)->pw_name);    // Print user name
        mx_printstr("  ");
        mx_printstr(getgrgid(file_stat.st_gid)->gr_name);    // Print group name
        mx_printstr("  ");
        //ctime(file_stat.st_mode)

//        mx_printstr("                    ");
//        mx_printstr(mx_itoa((int)file_stat.st_size));

        mx_printstr(cur->filename);                         // Print file name
        mx_printstr("\n");
    }

}
