//
// Created by Evgeny Kharitonov on 13.10.2020.
//

#ifndef CPP_HOMEWORKS_PARK_MAIL_COMPUTER_STRUCT_H
#define CPP_HOMEWORKS_PARK_MAIL_COMPUTER_STRUCT_H

#define NAME_LENGTH 20

struct computer {
    char brand[NAME_LENGTH + 1];
    unsigned short int core_count;
    unsigned int clock_frequency;
    unsigned int ram_count;
};

#endif //CPP_HOMEWORKS_PARK_MAIL_COMPUTER_STRUCT_H
