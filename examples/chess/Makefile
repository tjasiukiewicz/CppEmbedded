.PHONY := clean

OBJ := main.o board.o piece.o move.o
CXXFLAGS := -Wall -Wextra -pedantic -g
CXX := g++
LD_FLAGS :=

main: $(OBJ)
	$(CXX) $(LD_FLAGS) -o main $(OBJ)

clean:
	@rm -f $(OBJ) main > /dev/null 2>&1
