//
// Created by Evgeny Kharitonov on 13.10.2020.
//

#ifndef HW1_R_W_COMPUTERS_H
#define HW1_R_W_COMPUTERS_H

#include <stdio.h>
#include "node_struct.h"

#define CALLOC_ERROR -1;

int read_computers(struct node **start_node, ssize_t count);
void put_node(struct node **start_node, struct node *node);
void write_computers(struct node *start_node);
void delete_computers(struct node *start_node);

#endif //HW1_R_W_COMPUTERS_H
