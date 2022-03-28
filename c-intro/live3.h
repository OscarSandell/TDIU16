#pragma once
#include <vector>

struct sorted_list {
	std::vector<int> data;
	int filled;
};

void list_create(sorted_list *me, int max);
void list_destroy(sorted_list *me);

void list_add(sorted_list *me, int value);

int list_size(const sorted_list *me);

int list_get(const sorted_list *me, int pos);

extern int list_num_moves;
