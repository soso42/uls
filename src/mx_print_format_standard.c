//
// Created by Soso Janashvili on 06.09.2020.
//

#include "../inc/uls.h"

static int get_block_width(t_filelist *filelist);
static int get_n_nodes(t_filelist *filelist);

void mx_print_format_standard(t_main *main, t_filelist *filelist) {

    int win_width = 150;
    int block_width = get_block_width(filelist);
    int ncols = 4; // win_width / block_width;
    int nfiles = get_n_nodes(filelist);              // Number of files
    int nrows = (nfiles / ncols);

    for (int i = 0; i < nrows; i++) {
        for (int j = 0; j < ncols;) {

            for (t_filelist *cur = filelist; cur != NULL; cur = cur->next) {

                if (((i + j) % 2 == 0) && cur->filename != NULL) {
                    mx_printstr((cur->filename));
                    mx_print_space(block_width - mx_strlen(cur->filename));
                }
                j++;
            }
            mx_printstr("\n");
        }
    }
}

static int get_block_width(t_filelist *filelist) {
    int len;
    int max_len = 0;
    int i = 0;
    for (t_filelist *temp = filelist; temp != NULL; temp = temp->next) {
        len = mx_strlen(temp->filename);
        if (len > max_len)
            max_len = len;
    }

    while (i / max_len < 1)
        i += 8;

    return i;
}

static int get_n_nodes(t_filelist *filelist) {
    int n = 0;
    for (t_filelist *temp = filelist; temp != NULL; temp = temp->next) {
        n++;
    }
    return n;
}
