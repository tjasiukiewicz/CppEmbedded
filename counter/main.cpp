#include <iostream>

template<int Min_value, int Max_value>
struct Counter {
	constexpr static int min_value = Min_value;
	constexpr static int max_value = Max_value;
	Counter()
		: count{Min_value} {
	}
	Counter& operator++() {
		++count;
		if (count > Max_value) {
			count = Min_value;
		}
		return *this;
	}
	Counter& operator--() {
		--count;
		if (count < Min_value) {
			count = Max_value;
		}
		return *this;
	}
	int get() const {
		return count;
	}

private:
	int count;
};

int main() {
	Counter<3,5> cnt;
	std::cout << cnt.get() << '\n';
	++cnt;
	++cnt;
	std::cout << cnt.get() << '\n';
	++cnt;
	std::cout << cnt.get() << '\n';
	std::cout << sizeof(cnt) << '\n';
	std::cout << cnt.min_value << '\n';
}
