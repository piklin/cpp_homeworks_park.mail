//
// Created by Evgeny Kharitonov on 27.10.2020.
//

#include "for_searchers.h"

void killer(const pid_t *array, size_t count, pid_t mypid) {
    for (size_t i = 0; i < count; ++i) {
        if (array[i] != mypid) {
            kill(array[i], SIGTERM);
            waitpid(array[i], NULL, 0);
        }
    }
}

int finding_maximum_sequence_proc_count(const ssize_t *array,
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

    ssize_t proc_len = 0;
    if (process_count > 1) {
        proc_len = array_length / process_count + 1;
    } else {
       proc_len = array_length;
    }

    struct proc_res *results = (struct proc_res *)mmap(NULL,
                    sizeof(struct proc_res) * process_count,
                    PROT_WRITE,
                    MAP_SHARED|MAP_ANONYMOUS,
                    -1,
                    0);

    for (size_t i = 1; i < process_count; i++) {
        pid_t pid = fork();
        if (pid < 0) {
            killer(pids_array, i, getpid());
            munmap(results, sizeof(struct proc_res) * process_count);
            return FORK_ERROR;
        }
        if (pid == 0) {
            this_proc_number = i;
            break;
        }
        pids_array[i] = pid;
    }

    const ssize_t *this_proc_array = array + this_proc_number * proc_len;
    size_t this_proc_array_len = 0;
    if (this_proc_number == process_count - 1) {
        this_proc_array_len = array_length - (process_count - 1) * proc_len;
    } else {
        this_proc_array_len = proc_len;
    }
    struct proc_res result = {};
    int res = finding_sequences(this_proc_array, this_proc_array_len, comparator, &result);
    if (res < 0) {
        killer(pids_array, process_count, getpid());
        munmap(results, sizeof(struct proc_res) * process_count);
        return res;
    }

    results[this_proc_number] = result;
    if (this_proc_number) {
        exit(0);
    }

    for (size_t i = 0; i < process_count - 1; ++i) {
        wait(NULL);
    }

    size_t max_sequence_in_results_len = 1;
    size_t max_sequence_in_results_start = 0;
    size_t jump_seq_len = 0;
    size_t jump_seq_start = 0;

    for (size_t i = 1; i < process_count; ++i) {
        if (comparator(results[i - 1].end_value, results[i].start_value)) {

            if (jump_seq_len == 0) {
                jump_seq_len = results[i - 1].end_seq_length + results[i].start_seq_length;
                jump_seq_start = proc_len * i - results[i - 1].end_seq_length;
            } else {
                jump_seq_len += results[i].start_seq_length;
            }

            if (results[i].start_seq_length != proc_len) {
                if (jump_seq_len > max_sequence_in_results_len) {
                    max_sequence_in_results_len = jump_seq_len;
                    max_sequence_in_results_start = jump_seq_start;
                }
                jump_seq_len = 0;
                jump_seq_start = 0;
            }
        }
    }
    for (size_t i = 0; i < process_count; i++) {
        if (results[i].max_seq_length > max_sequence_in_results_len) {
            max_sequence_in_results_len = results[i].max_seq_length;
            max_sequence_in_results_start = proc_len * i + results[i].max_seq_start;
        }
    }

    *seq_start = max_sequence_in_results_start;
    *seq_length = max_sequence_in_results_len;

    munmap(results, sizeof(struct proc_res) * process_count);
    return 0;
}

int finding_sequences(const ssize_t *array,
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

    result->start_value = array[0];
    result->end_value = array[array_length - 1];

    int start_seq_flag = 1;

    for (size_t i = 1; i < array_length; ++i) {
        if (comparator(array[i - 1], array[i])) {
            local_seq_length++;
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
    result->end_seq_length = local_seq_length;
    if (local_seq_length > result->max_seq_length) {
        result->max_seq_length = local_seq_length;
        result->max_seq_start = local_seq_start;
    }
    if (local_seq_length == array_length) {
        result->start_seq_length = local_seq_length;
    }
    return 0;
}

