CXX=g++
CXXFLAGS=-Wall -Werror -Wextra -Wno-unused-value -pedantic -std=c++17 -g

SRC=src/main.cc
OBJ=$(SRC:.cc=.o)
EXEC=main

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CXX) -o $@ $(OBJ) $(LBLIBS)

clean:
	rm -rf $(OBJ) $(EXEC)
