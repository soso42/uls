//
// Created by Soso Janashvili on 04.09.2020.
//

#include "../inc/uls.h"

void mx_parse_data(t_main *main, char **argv) {

    mx_parse_flags(main, argv);           // Check validity of flags [-ACGRSTaclmrtu1]
                                          // and parse them if they're valid

    mx_parse_file_paths(main, argv);      // Create a list of directories
                                          // where we will run ls command

}
