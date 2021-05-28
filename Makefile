CXX=g++
CXXFLAGS=-Wall -Werror -Wextra -Wno-unused-value -pedantic -std=c++17 -g -fsanitize=address
LDFLAGS= -fsanitize=address

SRC=main.cc
OBJ=$(SRC:.cc=.o)
EXEC=main

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CXX) $(LDFLAGS) -o $@ $(OBJ) $(LBLIBS)

clean:
	rm -rf $(OBJ) $(EXEC)