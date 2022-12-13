#ifndef BOARD_HPP_
#define BOARD_HPP_

#include <array>
#include <optional>
#include "piece.hpp"
#include "move.hpp"

class Board {
public:
	constexpr static int Board_Width = 8;
	constexpr static int Board_Height = 8;
	using row_type = std::array<std::optional<Piece>, Board_Width>;
	using fields_type = std::array<row_type, Board_Height>;

	Board();
	void show() const;
	bool move_piece(const Move& move);
private:
	fields_type fields;
};

#endif // BOARD_HPP_
