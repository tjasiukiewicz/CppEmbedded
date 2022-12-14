#include <iostream>
#include "board.hpp"
#include "move.hpp"

int main() {
	Board board;
	board.show();

	if (board.move_piece({{'e', 2}, {'e', 4}})) {
		std::cout << "Legal move\n";
	} else {
		std::cout << "Illegal move\n";
	}
	
	board.show();
}
