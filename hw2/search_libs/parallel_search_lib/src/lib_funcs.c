//
// Created by Evgeny Kharitonov on 27.10.2020.
//

#include "lib_funcs.h"

int finding_maximum_sequence(const ssize_t *array,
                             size_t array_length,
                             size_t *seq_start,
                             size_t *seq_length,
                             int (*comparator)(ssize_t, ssize_t)) {
    return finding_maximum_sequence_proc_count(array, array_length, seq_start, seq_length, comparator, 2);
}
//TODO вставить число процессов

int finding_maximum_sequence_in_rand_array(size_t array_length,
                                           size_t *seq_length,
                                           int (*comparator)(ssize_t, ssize_t)) {

    ssize_t *array = malloc(array_length * sizeof(ssize_t));

    size_t start;
    int res = finding_maximum_sequence(array, array_length, &start, seq_length, comparator);
    free(array);
    return res;
}