#include <iostream>

void its_int(int& a) {
	std::cout << "a is & int!\n";
}

void foo(int&& a) {
	std::cout << "I'm foo(&&) a=" << a << '\n';
	its_int(a);
}

int main() {
	int a = 12;
	foo(std::move(a));
}
