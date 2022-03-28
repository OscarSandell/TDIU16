#pragma once
#include <stdbool.h>

struct sorted_list {
	int *data;
	int size;
	int filled;
};

// typedef struct sorted_list sorted_list;

void list_create(struct sorted_list *me, int max);
void list_destroy(struct sorted_list *me);

bool list_add(struct sorted_list *me, int value);

int list_size(const struct sorted_list *me);

int list_get(const struct sorted_list *me, int pos);

extern int list_num_moves;
