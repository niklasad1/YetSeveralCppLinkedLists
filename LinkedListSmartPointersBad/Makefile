CXX = clang++
CXXFLAGS = -std=c++1z
CXXFLAGS += -Wall
CXXFLAGS += -Wextra
CXXFLAGS += -pedantic
# CXXFLAGS += -Werror
CXXFLAGS += -g

SRC = main.cpp
INC =
OUT = main.out

.PHONY: cpp
cpp: cpp.out

.PHONY: clean
clean:
	rm -f *.o *.out

cpp.out: $(SRC) $(INC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(OUT)

c.out: $(SRC) $(INC)
	$(CC) $(CFLAGS) $(SRC) -o $(OUT)
