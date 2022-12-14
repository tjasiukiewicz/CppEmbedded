#include <iostream>
#include <iostream>
#include "pawn.hpp"
#include "rook.hpp"
#include "bishop.hpp"
#include "knight.hpp"
#include "queen.hpp"
#include "king.hpp"
#include "board.hpp"

namespace {

inline void show_col_names() {
	std::cout << "   ";
	for (auto i = 0U; i < Board::Board_Width; ++i) {
		std::cout << static_cast<char>('a' + i) << ' ';
	}
	std::cout << '\n';
}

inline void show_row_separator() {
	std::cout << "  ";
	for (auto i = 0U; i < Board::Board_Width; ++i) {
		std::cout << "+-";
	}
	std::cout << "+\n";
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

inline void fill_pawn_line(Board::row_type& row, const Color color) {
	for (auto col = 0U; col < Board::Board_Width; ++col) {
		row[col] = Pawn(color);
	}
}

inline void fill_figure_line(Board::row_type& row, const Color color) {
	row[0] = Rook(color);
	row[1] = Knight(color);
	row[2] = Bishop(color);
	row[3] = Queen(color);
	row[4] = King(color);
	row[5] = Bishop(color);
	row[6] = Knight(color);
	row[7] = Rook(color);
}

} // Anonymous namespace

Board::Board()
	: fields{} {
	// Placement pieces
	fill_pawn_line(fields[1], Color::White);
	fill_pawn_line(fields[Board_Height - 2], Color::Black);
	fill_figure_line(fields[0], Color::White);
	fill_figure_line(fields[Board_Height - 1], Color::Black);
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
	auto from = move.get_from();
	auto to = move.get_to();

	auto & from_field = fields[from.get_row()][from.get_col()];
	auto & to_field = fields[to.get_row()][to.get_col()];

	bool result = false;

	if (from_field.has_value() && (!(to_field.has_value()))) {
		// Move piece
		from_field.swap(to_field);
		result = true;
	}
	return result;
}
