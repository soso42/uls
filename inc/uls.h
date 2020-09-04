//
// Created by Soso Janashvili on 01.09.2020.
//

#ifndef ULS_ULS_H
#define ULS_ULS_H

#include "../libmx/inc/libmx.h"

//#include <sys/ioctl.h>
#include <unistd.h>
#include <dirent.h>

// Macros
#define ARGUMENTS "lRart1CmUacASG"

typedef struct s_main {
    char **dirs;                  // The list directories where we run ls
}           t_main;

void mx_print_content(char *path);
char *mx_getdir(char *argv);

// Errors
void mx_check_params(char **argv);

// Memory
void mx_alloc_clean_up(t_main *strct);

// Parse
void mx_parse_data(t_main *main, char **argv);
void mx_parse_dirs(t_main *main, char **argv);
int mx_get_shell_width();

#endif //ULS_ULS_H
