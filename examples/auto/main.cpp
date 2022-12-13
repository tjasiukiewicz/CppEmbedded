#include <iostream>
#include <vector>

template<typename T1, typename T2>
auto my_max(T1 a, T2 b) -> decltype(b + a) {
	return a > b ? a: b;
}

struct X {
	X(int val_)
		: val{val_} {} 
private:
	int val;
};

int main() {
	auto a = 34;
	const auto b = 32;
	auto & c = a;
	auto d = 0.1F;
	if (d != 0.1F) {
		std::cout << "Ups!\n";
	}
	decltype(a) e = 434;

	auto vec = std::vector<int>{1, 2, 3, 4};
	for (auto & it: vec) {
		it *= 10;
	}

	for (const auto & it: vec) {
		std::cout << it << ' ';
	}
	std::cout << '\n';

	int f = 12;
	int g(14.78);
	int h{14.78};
}
