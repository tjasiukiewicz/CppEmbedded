#ifndef PIECE_HPP_
#define PIECE_HPP_

enum class Color {
	White,
	Black
};

class Piece {
public:
	Piece(Color color, char repr);

	// noncopyable
	Piece(const Piece&) = delete;
	Piece& operator=(const Piece&) = delete;

	// movable
	Piece(Piece&& other);
	Piece& operator=(Piece&& other);

	Color get_color() const;
	char get_repr() const;
private:
	Color color;
	char repr;
};

#endif // PIECE_HPP_
