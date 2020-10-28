//
// Created by Evgeny Kharitonov on 27.10.2020.
//

#ifndef HW2_INTERFACE_H
#define HW2_INTERFACE_H

#include <stdio.h>

void hello();

int finding_maximum_sequence_in_rand_array(size_t array_length,
                                           size_t *seq_length);

int finding_maximum_sequence(ssize_t *array,
                             size_t array_length,
                             size_t *seq_start,
                             size_t *seq_length,
                             int (*comp)(ssize_t, ssize_t));

int comp(ssize_t first, ssize_t second);

#endif //HW2_INTERFACE_H
