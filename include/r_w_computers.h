//
// Created by Evgeny Kharitonov on 13.10.2020.
//

#ifndef HW1_R_W_COMPUTERS_H
#define HW1_R_W_COMPUTERS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "node_struct.h"

#define CALLOC_ERROR -1;
#define WRONG_INPUT_FORMAT -2;
#define STR_(X) #X
#define STR(X) STR_(X)

int read_computers(FILE *f, struct node **start_node, ssize_t count);
void put_node(struct node **start_node, struct node *node);
void write_computers(FILE *f, struct node *start_node);
void delete_computers(struct node *start_node);
void print_comp(FILE *f, struct node *node);
int scan_comp(FILE *f, struct node *node);

#endif //HW1_R_W_COMPUTERS_H
