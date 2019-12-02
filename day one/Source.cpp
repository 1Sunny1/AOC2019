#include <fstream>
#include <cmath>
#include <numeric>
#include <vector>
#include <algorithm>
#include <iterator>

auto main() -> int {
	std::fstream f("input.txt");
	std::vector<int> vals;
	std::copy(std::istream_iterator<int>(f), std::istream_iterator<int>(), std::back_inserter(vals));
	return std::accumulate(std::begin(vals), std::end(vals), 0, [](auto sum, auto value) { return sum += std::round(value / 3) - 2; });
}
