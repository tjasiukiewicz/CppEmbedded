#include <iostream>
#include "board.hpp"
#include "move.hpp"
#include "display.hpp"

int main() {
	Board board;
	Display display;
	board.visit(display);
	Display::show();
	if (board.move_piece({{'e', 2}, {'e', 4}})) {
		std::cout << "Legal move\n";
	} else {
		std::cout << "Illegal move\n";
	}

	board.visit(display);
	Display::show();
}
