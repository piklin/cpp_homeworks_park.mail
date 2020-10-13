#include "r_w_computers.h"
#include <stdlib.h>
#include <string.h>

void put_node(struct node **start_node, struct node *node) {
    if (*start_node == NULL) {
        *start_node = node;
        return;
    } else if ((*start_node)->next == NULL) {
        (*start_node)->next = node;
        return;
    }

    struct node *tmp_node = *start_node;
    while (strcmp(tmp_node->next->data.brand, node->data.brand) < 0) {
        tmp_node = tmp_node->next;
        if (tmp_node->next == NULL) {
            tmp_node->next = node;
            return;
        }
    }

    node->next = tmp_node->next;
    tmp_node->next = node;
}

void write_computers(struct node *start_node) {
    struct node *tmp_node = start_node;
    while (tmp_node != NULL) {
        printf("%s\n", tmp_node->data.brand);
        tmp_node = tmp_node->next;
    }
}

void delete_computers(struct node *start_node) {
    if (start_node == NULL) {
        return;
    } else if (start_node->next == NULL) {
        free(start_node);
        return;
    }
    struct node *prev = start_node;
    struct node *next = start_node->next;
    while (next != NULL) {
        free(prev);
        prev = next;
        next = next->next;
    }
    free(prev);
}

int read_computers(struct node **start_node, ssize_t count) {
    struct node *tmp_node;

    for (ssize_t i = 0; i < count; i++) {
        tmp_node = calloc(1, sizeof(struct node));
        if (tmp_node == NULL) {
            fprintf(stderr, "Calloc error\n");
            return CALLOC_ERROR;
        }
        scanf("%s", (*tmp_node).data.brand);
        scanf("%hu", &(*tmp_node).data.core_count);
        scanf("%du", &(*tmp_node).data.clock_frequency);
        scanf("%du", &(*tmp_node).data.ram_count);
        put_node(start_node, tmp_node);
    }
    return 0;
}