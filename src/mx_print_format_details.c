//
// Created by Soso Janashvili on 06.09.2020.
//

#include "../inc/uls.h"

static void print_stats(struct stat sb, char *name, int size_len) {
    struct passwd   *psswd;
    struct group    *grp;

    psswd = getpwuid(sb.st_uid);
    grp = getgrgid(sb.st_gid);

    mx_printstr(mx_is_dir(name) ? "d" : "-");
    mx_print_rwx(name);
    mx_printstr(" ");
    mx_printint(sb.st_nlink);
    mx_printstr(" ");
    mx_printstr(psswd->pw_name);
    mx_printstr(" ");
    mx_printstr(grp->gr_name);
    mx_printstr(" ");
    mx_print_file_size(name, size_len);
    mx_printstr(" ");
    mx_print_m_time(&sb);
    mx_printstr(" ");
}

static void process_file_stats(const char *parent, char *name, int size_len) {
    struct stat st_buf;
    char *path = NULL;
    char *temp = NULL;

    path = mx_strnew(mx_strlen(name) + mx_strlen(parent) + 2);
    temp = mx_strjoin(parent, "/");
    free(path);
    path = mx_strjoin(temp, name);
    free(temp);

    if (lstat(parent, &st_buf) == -1)
        perror("");
    else
        print_stats(st_buf, path, size_len);

    free(path);
}


void mx_print_format_details(t_main *main, t_filelist *filelist, char *path) {

    int size_len = mx_get_sf_max_len(filelist, path);

    for (t_filelist *cur = filelist; cur != NULL; cur = cur->next) {
        process_file_stats(path, cur->filename, size_len);
        mx_printstr(cur->filename);
        mx_printstr("\n");
    }
    mx_printstr("\n");


}


//void mx_print_nlink(char *name) {
//    char *path = NULL;
//    char *temp = NULL;
//
//    path = mx_strnew(mx_strlen(name) + mx_strlen(parent) + 2);
//    temp = mx_strjoin(parent, "/");
//    free(path);
//    path = mx_strjoin(temp, name);
//    free(temp);
//}
