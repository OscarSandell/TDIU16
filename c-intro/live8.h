#pragma once
#include <stdbool.h>

struct sorted_list;

// typedef struct sorted_list sorted_list;

struct sorted_list *list_create(int max);
void list_destroy(struct sorted_list *me);

bool list_add(struct sorted_list *me, int value);

int list_size(const struct sorted_list *me);

int list_get(const struct sorted_list *me, int pos);

int list_num_moves(void);
