#include <cctype>
#include "piece.hpp"

Piece::Piece(Color color_, char repr_)
	: color{color_}, repr{repr_} {

	if (color == Color::White) {
		repr = std::toupper(repr);
	} else {
		repr = std::tolower(repr);
	}
}

Piece::Piece(Piece&& other) {
	color = other.color;
	repr = other.repr;
}

Piece& Piece::operator=(Piece&& other) {
	color = other.color;
	repr = other.repr;
	return *this;
}

Color Piece::get_color() const {
	return color;
}

char Piece::get_repr() const {
	return repr;
}
