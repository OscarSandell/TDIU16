#pragma once

#include <stdbool.h>

struct sorted_list;

// typedef struct sorted_list sorted_list;

typedef bool (*list_compare)(int, int);

struct sorted_list *list_create(int max, list_compare compare);
void list_destroy(struct sorted_list *me);

bool list_add(struct sorted_list *me, int value);

int list_size(const struct sorted_list *me);

int list_get(const struct sorted_list *me, int pos);

int list_num_moves(void);
