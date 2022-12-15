#ifndef BOARD_HPP_
#define BOARD_HPP_

#include <array>
#include <optional>
#include "config.hpp"
#include "display.hpp"
#include "piece.hpp"
#include "move.hpp"

class Board {
public:
	using row_type = std::array<std::optional<Piece>, Board_Width>;
	using fields_type = std::array<row_type, Board_Height>;

	Board();
	bool move_piece(const Move& move);
	void visit(Display& display);
private:
	fields_type fields;
};

#endif // BOARD_HPP_
