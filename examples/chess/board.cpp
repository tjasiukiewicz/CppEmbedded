#include "pawn.hpp"
#include "rook.hpp"
#include "bishop.hpp"
#include "knight.hpp"
#include "queen.hpp"
#include "king.hpp"
#include "board.hpp"

namespace {

inline void fill_pawn_line(Board::row_type& row, const Color color) {
	for (auto col = 0U; col < Board_Width; ++col) {
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

void Board::visit(Display& display) {
	char tab[Board_Height * Board_Width * sizeof(char)];
	for (auto row = 0U; row < Board_Height; ++row) {
		for (auto col = 0U; col < Board_Width; ++col) {
			auto & o_piece = fields[row][col];
			if (o_piece.has_value()) {
				tab[row * Board_Width + col] = o_piece.value().get_repr();
			} else {
				tab[row * Board_Width + col] = ' ';
			}
		}
	}
	Display::fill_fields(tab);
}
