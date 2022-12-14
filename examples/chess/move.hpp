#ifndef MOVE_HPP_
#define MOVE_HPP_

#include "position.hpp"

class Move {
public:
	Move(const Position& from, const Position& to);
	const Position& get_from() const;
	const Position& get_to() const;
private:
	Position from;
	Position to;
};

#endif // MOVE_HPP_
