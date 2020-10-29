//
// Created by Evgeny Kharitonov on 27.10.2020.
//

#ifndef HW2_LIB_FUNCS_H
#define HW2_LIB_FUNCS_H

#include "interface.h"
#include "for_searchers.h"

#include <stdio.h>
#include <sys/sysinfo.h>

int finding_maximum_sequence(const ssize_t *array,
                             size_t array_length,
                             size_t *seq_start,
                             size_t *seq_length,
                             int (*comp)(ssize_t, ssize_t));

#endif //HW2_LIB_FUNCS_H
