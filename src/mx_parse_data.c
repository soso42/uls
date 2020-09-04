//
// Created by Soso Janashvili on 04.09.2020.
//

#include "../inc/uls.h"

void mx_parse_data(t_main *main, char **argv) {

    mx_check_flags(argv);           // Check validity of flags [-ACGRSTaclmrtu1]

    // Here may be a function call to parse -flags

    mx_parse_file_paths(main, argv);          // Create a list of directories
                                              // where we will run ls command


}
