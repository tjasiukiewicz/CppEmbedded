#include <iostream>
#include "display.hpp"

namespace {

inline void show_col_names() {
	std::cout << "   ";
	for (auto i = 0U; i < Board_Width; ++i) {
		std::cout << static_cast<char>('a' + i) << ' ';
	}
	std::cout << '\n';
}

inline void show_row_separator() {
	std::cout << "  ";
	for (auto i = 0U; i < Board_Width; ++i) {
		std::cout << "+-";
	}
	std::cout << "+\n";
}

inline void show_row(int row_number, const char * row) {
	std::cout << row_number + 1 << ' ';
	for (auto col = 0U; col < Board_Width; ++col) {
		std::cout << '|' << row[col];
	}
	std::cout << "| " << row_number + 1 << '\n';
	show_row_separator();
}

} // Anonymous namespace 

void Display::fill_fields(char * tab) {
}

void Display::show() {
}

