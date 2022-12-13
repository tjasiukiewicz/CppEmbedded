#ifndef MOVE_HPP_
#define MOVE_HPP_

class Position {
public:
	Position(char col, unsigned row);
	unsigned get_row() const;
	unsigned get_col() const;
private:
	unsigned col;
	unsigned row;
};

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
