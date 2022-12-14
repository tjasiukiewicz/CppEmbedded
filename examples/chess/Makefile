.PHONY := clean

OBJ := main.o board.o piece.o position.o move.o pawn.o rook.o bishop.o knight.o queen.o king.o
CXXFLAGS := -Wall -Wextra -pedantic -g
CXX := g++
LD_FLAGS :=

main: $(OBJ)
	$(CXX) $(LD_FLAGS) -o main $(OBJ)

clean:
	@rm -f $(OBJ) main > /dev/null 2>&1
