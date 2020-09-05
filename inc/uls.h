//
// Created by Soso Janashvili on 01.09.2020.
//

#ifndef ULS_ULS_H
#define ULS_ULS_H

#include "../libmx/inc/libmx.h"

//#include <sys/ioctl.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>

// Macros
#define ARGUMENTS "lRart1CmUacASG"      // List of supported flags

typedef struct s_flags {

}           t_flags;

typedef struct s_main {
    char **dirs;                  // The list of directories where we run ls
    bool R;
}           t_main;

void mx_print_content(char *path);
char *mx_getdir(char *argv);

// Errors
void mx_check_flags(char **argv);

// Memory
void mx_alloc_clean_up(t_main *strct);

// Parse
void mx_parse_data(t_main *main, char **argv);
void mx_parse_file_paths(t_main *main, char **argv);
int mx_get_shell_width();

// Output
void mx_list_files(char *path, int root);

// Utils
int mx_file_exists(char *filename);
int mx_is_regular_file(const char *filename);
int mx_is_folder(const char *filename);

#endif //ULS_ULS_H
