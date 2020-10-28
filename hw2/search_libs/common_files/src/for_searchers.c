//
// Created by Evgeny Kharitonov on 27.10.2020.
//

#include "for_searchers.h"

int comp(ssize_t first, ssize_t second) {
    return first < second;
}

void killer(pid_t *array, size_t count) {
    for (size_t i = 1; i < count; ++i) {
        kill(array[i], SIGTERM);
        waitpid(array[i], NULL, 0);
    }
}

/*int finding_maximum_sequence_proc_count(ssize_t *array,
                                        size_t array_length,
                                        size_t *seq_start,
                                        size_t *seq_length,
                                        int (*comparator)(ssize_t, ssize_t),
                                        size_t process_count) {
    if (array == NULL) {
        return ARRAY_IS_NULL;
    }

    size_t this_proc_number = 0;

    pid_t pids_array[process_count];
    pids_array[this_proc_number] = getpid();

    struct proc_res *results = mmap(NULL,
                    sizeof(struct proc_res) * process_count,
                    PROT_WRITE,
                    MAP_SHARED|MAP_ANONYMOUS,
                    -1,
                    0);

    for (size_t i = 1; i < process_count; i++) {
        pid_t pid = fork();
        if (pid < 0) {
            killer(pids_array, i);
            return FORK_ERROR;
        }
        if (pid == 0) {
            break;
        }
        pids_array[i] = pid;
    }

}*/

int finding_sequences(ssize_t * array,
                      size_t array_length,
                      int (*comparator)(ssize_t, ssize_t),
                      struct proc_res *result) {
    if (array == NULL) {
        return ARRAY_IS_NULL;
    }

    if (result == NULL) {
        return INVALID_POINTER;
    }

    size_t local_seq_length = 1;
    size_t local_seq_start = 0;

    int start_seq_flag = 1;

    for (size_t i = 1; i < array_length; ++i) {
        if (comparator(array[i - 1], array[i])) {
            local_seq_length++;
            if (i == array_length - 1) {
                result->end_seq_length = local_seq_length;
            }
        } else {
            if (start_seq_flag) {
                result->start_seq_length = local_seq_length;
                start_seq_flag = 0;
            }

            if (local_seq_length > result->max_seq_length) {
                result->max_seq_length = local_seq_length;
                result->max_seq_start = local_seq_start;
            }
            local_seq_start = i;
            local_seq_length = 1;
        }
    }
    return 0;
}
