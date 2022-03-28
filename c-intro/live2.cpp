#include "live2.h"
#include <stdexcept>

int list_num_moves = 0;

void list_create(sorted_list &me, int max) {
	me.data = std::vector<int>(max, 0);
	me.filled = 0;
}

void list_destroy(sorted_list &) {}

static bool list_done(const sorted_list &me, std::vector<int>::iterator pos, int value) {
	if (pos == me.data.begin())
		return true;
	return value >= *(--pos);
}

void list_add(sorted_list &me, int value) {
	if (me.filled >= int(me.data.size()))
		throw std::logic_error("full");

	std::vector<int>::iterator into = me.data.begin() + me.filled++;
	while (!list_done(me, into, value)) {
		--into;
		*(into + 1) = *into;
		++list_num_moves;
	}

	*into = value;
}

int list_size(const sorted_list &me) {
	return me.filled;
}

int list_get(const sorted_list &me, int pos) {
	if (pos >= me.filled || pos < 0)
		throw std::out_of_range("get");

	return me.data[pos];
}
