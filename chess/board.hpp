#ifndef BOARD_HPP_
#define BOARD_HPP_

class Board {
public:
	constexpr static int Board_Width = 8;
	constexpr static int Board_Height = 8;
	Board();
	void show() const;
private:
	char fields[Board_Height][Board_Width];
};

#endif // BOARD_HPP_
