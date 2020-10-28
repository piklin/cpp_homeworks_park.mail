//
// Created by Evgeny Kharitonov on 27.10.2020.
//

#include "interface.h"

int comp(ssize_t first, ssize_t second);

int comp(ssize_t first, ssize_t second) {
    return first < second;
}

int main() {
    size_t seq = 0;
    finding_maximum_sequence_in_rand_array(2000000000, &seq, comp);
    printf("%zu\n", seq);
    return 0;
}
