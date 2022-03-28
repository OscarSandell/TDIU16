#include "live7.h"
#include <stdlib.h>
#include <stdio.h>

int list_num_moves = 0;

void list_create(struct sorted_list *me, int max) {
	// me->data = malloc(sizeof(int)*max);
	me->data = calloc(max, sizeof(int));
	me->size = max;
	me->filled = 0;
}

void list_destroy(struct sorted_list *me) {
	free(me->data);
}

static bool list_done(const struct sorted_list *me, int *pos, int value) {
	if (pos == me->data)
		return true;
	return value >= *(--pos);
}

// 'useless' helper to illustrate the concept of 'reference to pointer' in C. This is what we would
// write in C++:
#if 0
static void list_move(int *&into) {
	--into;
	*(into + 1) = *into;
}
#endif

static void list_move(int **into) {
	--*into;
	*(*into + 1) = **into;
	// Note: above and below are equivalent.
	// (*into)[1] = (*into)[0];
	++list_num_moves;
}

bool list_add(struct sorted_list *me, int value) {
	if (me->filled >= me->size)
		return false;

	int *into = me->data + me->filled++;
	while (!list_done(me, into, value)) {
		list_move(&into);
	}

	*into = value;
	return true;
}

int list_size(const struct sorted_list *me) {
	return me->filled;
}

int list_get(const struct sorted_list *me, int pos) {
	if (pos >= me->filled || pos < 0) {
		// If we know more about the data, we could return
		// some invalid value, eg. NULL.
		printf("out of range: %d\n", pos);
		abort();
	}

	return me->data[pos];
}
