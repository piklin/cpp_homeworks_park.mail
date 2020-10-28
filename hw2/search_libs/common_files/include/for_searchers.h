//
// Created by Evgeny Kharitonov on 27.10.2020.
//

#ifndef HW2_FOR_SEACHERS_H
#define HW2_FOR_SEACHERS_H

#include "interface.h"

#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/mman.h>

#define ARRAY_IS_NULL -1
#define FORK_ERROR -2
#define INVALID_POINTER -3

struct proc_res {
    size_t start_seq_length;
    size_t end_seq_length;

    size_t max_seq_length;
    size_t max_seq_start;
};

int comp(ssize_t first, ssize_t second);

int finding_maximum_sequence_in_rand_array(size_t array_length,
                                           size_t *seq_length);


int finding_maximum_sequence_proc_count(ssize_t *array,
                                        size_t array_length,
                                        size_t *seq_start,
                                        size_t *seq_length,
                                        int (*comp)(ssize_t, ssize_t),
                                        size_t process_count);

int finding_sequences(ssize_t * array,
                       size_t array_length,
                       int (*comparator)(ssize_t, ssize_t),
                       struct proc_res *result);

#endif //HW2_FOR_SEACHERS_H
