#include <cstdio>
#include "live1.h"

void print_first(int count, const sorted_list &l) {
	printf("De första %d elementen:\n", count);
	for (int i = 0; i < count; i++) {
		printf("%3d", l.get(i));
		if (i % 10 == 9)
			printf("\n");
	}
}

int main() {
	sorted_list l(100);

	for (int i = 0; i < 100; i++)
		l.add(100 - i);

	printf("Antal förflyttningar: %d\n", sorted_list::num_moves);
	printf("Antal element: %d\n", l.size());
	print_first(40, l);

	return 0;
}
