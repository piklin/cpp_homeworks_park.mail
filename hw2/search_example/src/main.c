//
// Created by Evgeny Kharitonov on 27.10.2020.
//

#include "interface.h"

#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <limits.h>

#define MALLOC_ERROR -100

int comp(ssize_t first, ssize_t second);

int comp(ssize_t first, ssize_t second) {
    return first < second;
}

void rand_array_filling(ssize_t *array, ssize_t len) {
    srand(time(NULL));

    for (size_t i = 0; i < len; ++i) {
        array[i] = rand();
    }

}

int testing_algorithm(ssize_t len, clock_t *time) {
    ssize_t *array = malloc(len * sizeof(ssize_t));
    if (array == NULL) {
        return MALLOC_ERROR;
    }
    rand_array_filling(array, len);

    size_t seq_start = 0;
    size_t seq_len = 0;

    clock_t start = clock();
    int res = finding_maximum_sequence(array, len, &seq_start, &seq_len, comp);
    if (res < 0) {
        free(array);
        return res;
    }
    clock_t stop = clock();

    free(array);
    *time = stop - start;
    return EXIT_SUCCESS;
}

int main(int argc, char **argv) {

    ssize_t len = strtol(argv[1], (argv + strlen(argv[1])), 10);

    if (len < 0) {
        return EXIT_SUCCESS;
    }

    clock_t time = 0;
    int res = testing_algorithm(len, &time);
    if (res < 0) {
        return EXIT_FAILURE;
    }
    printf("\n-----\nworking time %zu\n-----\n", time);

    return EXIT_SUCCESS;
}
