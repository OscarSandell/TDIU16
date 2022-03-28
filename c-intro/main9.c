#include <stdio.h>
#include <stdlib.h>
#include "live9.h"

static void print_first(int count, const struct sorted_list *l) {
	printf("De första %d elementen:\n", count);
	for (int i = 0; i < count; i++) {
		printf("%3d", list_get(l, i));
		if (i % 10 == 9)
			printf("\n");
	}
}

static bool compare(int a, int b) {
	return a < b;
}

int main(void) {
	struct sorted_list *l = list_create(100, &compare);

	for (int i = 0; i < 100; i++)
		list_add(l, 100 - i);

	printf("Antal förflyttningar: %d\n", list_num_moves());
	printf("Antal element: %d\n", list_size(l));
	print_first(40, l);

	list_destroy(l);

	return 0;
}
