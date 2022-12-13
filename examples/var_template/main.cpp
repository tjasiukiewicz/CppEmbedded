#include <iostream>

template<typename Arg>
void show_arguments(Arg arg) {
	std::cout << arg << '\n';
}

template<typename Arg, typename... Args>
void show_arguments(Arg arg, Args... args) {
	std::cout << arg << ", ";
	show_arguments(args...);
}

int main() {
	show_arguments(1, 2, 3, "Ala", 3.1415);
}
