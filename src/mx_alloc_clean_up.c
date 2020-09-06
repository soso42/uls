//
// Created by Soso Janashvili on 04.09.2020.
//

#include "../inc/uls.h"

void mx_alloc_clean_up(t_main *main) {
    free(main->dirs);
}
