#include "live0.h"
#include <stdexcept>

int sorted_list::num_moves = 0;

sorted_list::sorted_list(int max) : data(max, 0), filled(0) {}

sorted_list::~sorted_list() {}

bool sorted_list::done(std::vector<int>::iterator pos, int value) const {
	if (pos == data.begin())
		return true;
	return value >= *(--pos);
}

void sorted_list::add(int value) {
	if (filled >= int(data.size()))
		throw std::logic_error("full");

	std::vector<int>::iterator into = data.begin() + filled++;
	while (!done(into, value)) {
		--into;
		*(into + 1) = *into;
		++num_moves;
	}

	*into = value;
}

int sorted_list::size() const {
	return filled;
}

int sorted_list::get(int pos) const {
	if (pos >= filled || pos < 0)
		throw std::out_of_range("overflow");

	return data[pos];
}
