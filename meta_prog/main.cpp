#include <iostream>


template<int Value>
struct Reciprocal {
	constexpr static int value = Reciprocal<Value - 1>::value * Value;
};

template<>
struct Reciprocal<0> {
	constexpr static int value = 1;
};

template<int Index>
struct Fibonacci {
	constexpr static int value = Fibonacci<Index - 2>::value + Fibonacci<Index -1>::value;
};

template<>
struct Fibonacci<0> {
	constexpr static int value = 0;
};

template<>
struct Fibonacci<1> {
	constexpr static int value = 1;
};

int main() {
	std::cout << Reciprocal<8>::value << '\n';
	std::cout << Fibonacci<8>::value << '\n';
}
