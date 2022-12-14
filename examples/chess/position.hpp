#ifndef POSITION_HPP_
#define POSITION_HPP_

class Position {
public:
	Position(char col, unsigned row);
	unsigned get_row() const;
	unsigned get_col() const;
private:
	unsigned col;
	unsigned row;
};

#endif // POSITION_HPP_

