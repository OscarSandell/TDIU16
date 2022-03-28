#include "live5.h"
#include <cstdlib>
#include <cstdio>

int list_num_moves = 0;

void list_create(sorted_list *me, int max) {
	// me->data = malloc(sizeof(int)*max);
	me->data = (int *)calloc(max, sizeof(int));
	me->size = max;
	me->filled = 0;
}

void list_destroy(sorted_list *me) {
	free(me->data);
}

static bool list_done(const sorted_list *me, int *pos, int value) {
	if (pos == me->data)
		return true;
	return value >= *(--pos);
}

bool list_add(sorted_list *me, int value) {
	if (me->filled >= me->size)
		return false;

	int *into = me->data + me->filled++;
	while (!list_done(me, into, value)) {
		--into;
		*(into + 1) = *into;
		// Note: The above is equivalent to:
		// into[1] = into[0]; (works for iterators in C++ as well)
		++list_num_moves;
	}

	*into = value;
	return true;
}

int list_size(const sorted_list *me) {
	return me->filled;
}

int list_get(const sorted_list *me, int pos) {
	if (pos >= me->filled || pos < 0) {
		// If we know more about the data, we could return
		// some invalid value, eg. NULL.
		printf("out of range: %d\n", pos);
		abort();
	}

	return me->data[pos];
}
