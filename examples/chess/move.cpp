#include <cassert>
#include "move.hpp"

Move::Move(const Position& from_, const Position& to_)
	: from{from_}, to{to_} {
}

const Position& Move::get_from() const {
	return from;
}

const Position& Move::get_to() const {
	return to;
}
