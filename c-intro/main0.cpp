#include <iostream>
#include <iomanip>
#include "live0.h"

using namespace std;

void print_first(int count, const sorted_list &l) {
	cout << "De första " << count << " elementen:" << endl;
	for (int i = 0; i < count; i++) {
		cout << setw(3) << l.get(i);
		if (i % 10 == 9)
			cout << endl;
	}
}

int main() {
	sorted_list l(100);

	for (int i = 0; i < 100; i++)
		l.add(100 - i);

	cout << "Antal förflyttningar: " << sorted_list::num_moves << endl;
	cout << "Antal element: " << l.size() << endl;
	print_first(40, l);

	return 0;
}
