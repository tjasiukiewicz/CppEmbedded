#include "move.hpp"

Position::Position(char col, unsigned row)
	: col{0}, row{0} {
}

unsigned Position::get_row() const {
	return 0;
}

unsigned Position::get_col() const {
	return 0;
}

Move::Move(const Position& from, const Position& to) {
}

const Position& Move::get_from() const {
	return Position('a', '1');
}

const Position& Move::get_to() const {
	return Position('a', '1');
}
