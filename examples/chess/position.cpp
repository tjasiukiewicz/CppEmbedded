#include <cassert>
#include "config.hpp"
#include "position.hpp"

Position::Position(char col_, unsigned row_)
	: col{0}, row{0} {
	assert((col_ >= 'a') && (col_ <= ('a' + Board_Width)));
	assert((row_ >= 1) && (row_ < Board_Width));
	col = col_ - 'a';
	row = row_ - 1;
}

unsigned Position::get_row() const {
	return row;
}

unsigned Position::get_col() const {
	return col;
}
