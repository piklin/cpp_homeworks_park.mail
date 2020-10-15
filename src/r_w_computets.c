#include "r_w_computers.h"

void put_node(struct node **start_node, struct node *node) {
    if (*start_node == NULL) {
        *start_node = node;
        return;
    } else if ((*start_node)->next == NULL) {
        (*start_node)->next = node;
        return;
    }

    struct node *tmp_node = *start_node;
    while (strcmp(tmp_node->next->data.brand, node->data.brand) > 0) {
        tmp_node = tmp_node->next;
        if (tmp_node->next == NULL) {
            tmp_node->next = node;
            return;
        }
    }

    node->next = tmp_node->next;
    tmp_node->next = node;
}

void delete_computers(struct node *start_node) {
    if (start_node == NULL) {
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

void write_computers(FILE *f, struct node *start_node) {
    struct node *tmp_node = start_node;
    while (tmp_node != NULL) {
        print_comp(f, tmp_node);
        tmp_node = tmp_node->next;
    }
}

int read_computers(FILE *f, struct node **start_node, ssize_t count) {
    struct node *tmp_node = NULL;

    for (ssize_t i = 0; i < count; ++i) {
        tmp_node = calloc(1, sizeof(struct node));
        if (tmp_node == NULL) {
            fprintf(stderr, "Calloc error\n");
            return CALLOC_ERROR;
        }
        int res = scan_comp(f, tmp_node);
        if (res < 0) {
            free(tmp_node);
            return res;
        }

        put_node(start_node, tmp_node);
    }
    return 0;
}

void print_comp(FILE *f, struct node *node) {
    fprintf(f, "%s %hu %u %u\n", node->data.brand,
            node->data.core_count,
            node->data.clock_frequency,
            node->data.ram_count);
}

int scan_comp(FILE *f, struct node *node) {
    int res = fscanf(f, "%"STR(NAME_LENGTH)"s %hu %u %u",
                     (*node).data.brand,
                     &(*node).data.core_count,
                     &(*node).data.clock_frequency,
                     &(*node).data.ram_count);
    if (res != 4) {
        return WRONG_INPUT_FORMAT;
    }
    //node->data.brand[NAME_LENGTH] = '\0';
    return 0;
}
