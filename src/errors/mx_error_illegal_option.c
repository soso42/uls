//
// Created by Soso Janashvili on 06.09.2020.
//

#include "../../inc/uls.h"

void mx_error_illegal_option(const char *ch) {
    mx_printerror("uls illegal option -- ");
    mx_printerror(ch);
    mx_printerror("\nusage: uls [-ACGRSTaclmrtu1] [file ...]\n");
    exit(1);
}
