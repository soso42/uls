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
#include <pwd.h>
#include <sys/xattr.h>
#include <grp.h>
#include <time.h>
//#include <uuid/uuid.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

// Macros
#define ARGUMENTS "lRart1CmUcASG"      // List of supported flags

#ifdef __APPLE__
#ifndef st_mtime
#define st_mtime st_mtimespec.tv_sec
#endif
#endif

typedef struct s_main {
    char **dirs;                  // The list of directories where we run ls
    char *flags;
}           t_main;

typedef struct s_filelist {
    char *filename;
    //char *user_name;
    struct s_filelist *next;
}           t_filelist;

char *mx_getdir(char *argv);

// Errors
void mx_error_illegal_option(const char *ch);
void mx_error_no_such_file(char *filename);

// Memory
void mx_alloc_clean_up(t_main *main);

// Parse
void mx_parse_data(t_main *main, int argc, char **argv);
void mx_parse_flags(t_main *main, char **argv);
void mx_parse_file_paths(t_main *main, int argc, char **argv);
int mx_get_shell_width();

// Output
void mx_list_files(t_main *main, char *basePath, int root);
void mx_print_filelist(t_filelist* filelist);
void mx_process_filelist(t_main *main, char *path);
t_filelist *mx_fl_create_node(char *filename);
void mx_fl_push_back(t_filelist **list, char *filename);
void mx_delete_filelist(t_filelist *filelist);
void mx_print_format_one(t_main *main, t_filelist *filelist);
void mx_print_format_details(t_main *main, t_filelist *filelist, char *path);
void mx_print_format_standard(t_main *main, t_filelist *filelist);
void mx_sort_filelist(t_main *main, t_filelist *filelist);
void mx_format_output(t_main *main, t_filelist *filelist, char *path);
void mx_filter_filelist(t_main *main, t_filelist *filelist);
void mx_print_file_size(char *name, int size_len);
void mx_print_m_time(struct stat *file_stat);
void mx_print_rwx(char *name);

// Utils
int mx_file_exists(char *filename);
int mx_is_regular_file(const char *filename);
int mx_is_dir(const char *filename);
void mx_print_space(int n);
off_t mx_fsize(const char *filename);
int mx_get_sf_max_len(t_filelist *filelist, char *path);

// Linked list
void mx_bubblesort_list_asc(t_filelist *head);
void mx_bubblesort_list_des(t_filelist *head);
void mx_fl_pop_front(t_filelist **head);
int mx_get_n_nodes(t_filelist *filelist);

//test
void mx_get_attributes(t_filelist *filelist, char *path);

#endif //ULS_ULS_H
