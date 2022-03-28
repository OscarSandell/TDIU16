#pragma once

struct sorted_list {
	int *data;
	int size;
	int filled;
};

void list_create(sorted_list *me, int max);
void list_destroy(sorted_list *me);

bool list_add(sorted_list *me, int value);

int list_size(const sorted_list *me);

int list_get(const sorted_list *me, int pos);

extern int list_num_moves;
