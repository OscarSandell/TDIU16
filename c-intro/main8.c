#include <stdio.h>
#include "live8.h"

static void print_first(int count, const struct sorted_list *l) {
	printf("De första %d elementen:\n", count);
	for (int i = 0; i < count; i++) {
		printf("%3d", list_get(l, i));
		if (i % 10 == 9)
			printf("\n");
	}
}

int main(void) {
	// This will not work now...
	// struct sorted_list l;
	struct sorted_list *l = list_create(100);

	for (int i = 0; i < 100; i++)
		list_add(l, 100 - i);

	printf("Antal förflyttningar: %d\n", list_num_moves());
	printf("Antal element: %d\n", list_size(l));
	print_first(40, l);

	list_destroy(l);

	return 0;
}
