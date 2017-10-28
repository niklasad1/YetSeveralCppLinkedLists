CXX = clang++
CXXFLAGS = -std=c++1z
CXXFLAGS += -Wall
CXXFLAGS += -Wextra
CXXFLAGS += -pedantic
CXXFLAGS += -Werror
CXXFLAGS += -g
CXXFLAGS += -fsanitize=address
# CXXFLAGS += -fsanitize=thread
CXXFLAGS += -fno-omit-frame-pointer
CXXFLAGS += -O1

SRC = main.cpp
INC = linked_list.h linked_list_tests.h
LIB = -lgtest -lgtest_main -lpthread
OUT = main.out

.PHONY: cpp
cpp: cpp.out

.PHONY: clean
clean:
	rm -f *.o *.out

cpp.out: $(SRC) $(INC)
	$(CXX) $(CXXFLAGS) $(SRC) $(LIB) -o $(OUT)
