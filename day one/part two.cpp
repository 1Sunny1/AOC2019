#include <fstream>
#include <cmath>
#include <numeric>
#include <vector>
#include <algorithm>
#include <iterator>

int fuelmass(int amount) {
	int _fuelmass = 0;
	while (amount > 0) {
		_fuelmass += amount;
		amount = std::round(amount / 3) - 2;
	}
	return _fuelmass;
}

auto main() -> int {
	std::fstream f("input.txt");
	std::vector<int> vals;
	std::copy(std::istream_iterator<int>(f), std::istream_iterator<int>(), std::back_inserter(vals));
	return std::accumulate(std::begin(vals), std::end(vals), 0, [](auto sum, auto value) { return sum += fuelmass(std::round(value / 3) - 2); });
}