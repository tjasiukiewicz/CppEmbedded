#include <iostream>
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

inline void show_row(int row_number, const Board::row_type& row) {
	std::cout << row_number + 1 << ' ';
	for (auto col = 0U; col < Board::Board_Width; ++col) {
		std::cout << '|' << (
				row[col].has_value()
				? (row[col]).value().get_repr(): ' '
		);
	}
	std::cout << "| " << row_number + 1 << '\n';
	show_row_separator();
}

} // Anonymous namespace

Board::Board() {
	for (auto row = 0U; row < Board_Height; ++row) {
		for (auto col = 0U; col < Board_Width; ++col) {
			fields[row][col] = {};
		}
	}
	// Umieszczenie bierek.
	constexpr static char pieces[Board_Width + 1] = "rnbqkbnr";
	for (auto col = 0U; col < Board_Width; ++col) {
		fields[0][col] = {Color::White, pieces[col]};
		fields[1][col] = {Color::White, 'p'};
		fields[Board_Height - 1][col] = {Color::Black, pieces[col]};
		fields[Board_Height - 2][col] = {Color::Black, 'p'};
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

bool Board::move_piece(const Move& move) {
	return true;
}
