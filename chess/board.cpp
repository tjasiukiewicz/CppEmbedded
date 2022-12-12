#include <iostream>
#include <cctype>
#include "board.hpp"

namespace {

inline void show_col_names() {
	// TODO: Uzależnić ilość nazw od Board::Board_Width
	std::cout << "   a b c d e f g h\n";
}

inline void show_row_separator() {
	// TODO: Uzależnić ilość +- od Board::Board_Width
	std::cout << "  +-+-+-+-+-+-+-+-+\n";
}

inline void show_row(int row_number, const char row[Board::Board_Width]) {
	std::cout << row_number + 1 << ' ';
	for (auto col = 0U; col < Board::Board_Width; ++col) {
		std::cout << "|" << row[col];
	}
	std::cout << "| " << row_number + 1 << '\n';
	show_row_separator();
}

} // Anonymous namespace

Board::Board() {
	for (auto row = 0U; row < Board_Height; ++row) {
		for (auto col = 0U; col < Board_Width; ++col) {
			fields[row][col] = ' ';
		}
	}
	// Umieszczenie bierek.
	const static char pieces[Board_Width + 1] = "rnbqkbnr";
	for (auto col = 0U; col < Board_Width; ++col) {
		fields[0][col] = toupper(pieces[col]);
		fields[1][col] = 'P';
		fields[Board_Height - 1][col] = pieces[col];
		fields[Board_Height - 2][col] = 'p';
	}
}

void Board::show() const {
	show_col_names();
	show_row_separator();
	auto row = Board_Height;
	while (row--) {
		show_row(row, fields[row]);
	}
	show_col_names();
}
