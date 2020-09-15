//
// Created by ss on 9/11/20.
//

#include "../inc/uls.h"

off_t fsize(const char *filename) {
    struct stat st;

    if (stat(filename, &st) == 0)
        return st.st_size;

    fprintf(stderr, "Cannot determine size of %s: %s\n",
            filename, strerror(errno));

    return -1;
}

void get_file_attr(struct stat sb, t_filelist *file) {
    struct passwd   *psswd;
    struct group    *grp;

    psswd = getpwuid(sb.st_uid);
    grp = getgrgid(sb.st_gid);

//    file->user_name = mx_strdup(psswd->pw_name);
//    mx_printstr(file->user_name);
    mx_printstr("  ");

    mx_printstr(grp->gr_name);
    mx_printstr("  ");
//    print_m_time(&sb);
//    mx_printstr("  ");
    mx_printint((int)fsize(file->filename));
    mx_printstr("  ");
    mx_printstr(file->filename);
    mx_printstr("\n");
}

void get_file(const char *parent, t_filelist *file) {
    struct stat st_buf;
    char *path = NULL;
    char *temp = NULL;

    path = mx_strnew(mx_strlen(file->filename) + mx_strlen(parent) + 2);
    temp = mx_strjoin(parent, "/");
    free(path);
    path = mx_strjoin(temp, file->filename);
    free(temp);

    if (lstat(parent, &st_buf) == -1)
        perror("");
    else
        get_file_attr(st_buf, file);

    free(path);
}

void mx_get_attributes(t_filelist *filelist, char *path) {

    for (t_filelist *cur = filelist; cur != NULL; cur = cur->next) {

        if (cur == NULL)
            break;

        get_file(path, cur);
    }

}

//static char *get_user_name(char *path) {
//
//    struct stat file_stat;
//    char *user = NULL;
//    struct passwd *pwd;
//
//    pwd = getpwuid(file_stat.st_uid);
//
//    if (pwd != NULL)
//        user = pwd->pw_name;
//
//    return mx_strdup(user);
//}

