//
// Created by Evgeny Kharitonov on 13.10.2020.
//
#include "r_w_computers.h"

int main() {
    size_t count;
    scanf("%zu", &count);
    struct node *start_node = NULL;
    int res = read_computers(&start_node, count);
    write_computers(start_node);
    delete_computers(start_node);
    return 0;
}
