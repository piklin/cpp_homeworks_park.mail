//
// Created by Evgeny Kharitonov on 13.10.2020.
//
#include "main.h"

int main() {
    size_t count;
    int res = scanf("%zu", &count);
    if (res != 1) {
        fprintf(stderr, "Wrong input format\n");
    }

    struct node *start_node = NULL;
    FILE *in = DEFAULT_INPUT;
    FILE *out = DEFAULT_OUTPUT;

    res = read_computers(in, &start_node, count);
    if (res < 0) {
        fprintf(stderr, "Error code %d\n", res);
        return res;
    }
    write_computers(out, start_node);
    delete_computers(start_node);
    return 0;
}