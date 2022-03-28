#pragma once
#include <vector>

class sorted_list {
public:
	sorted_list(int max);
	~sorted_list();

	void add(int value);

	int size() const;

	int get(int pos) const;

	static int num_moves;
private:
	std::vector<int> data;
	int filled;

	bool done(std::vector<int>::iterator data, int value) const;
};
