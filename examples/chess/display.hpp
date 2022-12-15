#ifndef DISPLAY_HPP_
#define DISPLAY_HPP_

#include "config.hpp"

struct Display {
	static void fill_fields(char * tab);
	static void show();
private:
	static char field[Board_Height][Board_Width];
};

#endif // DISPLAY_HPP_
