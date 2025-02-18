CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17
SRC_DIR = src
SRC_FILES = $(wildcard $(SRC_DIR)/**/*.cpp) main.cpp
OBJ_FILES = $(SRC_FILES:.cpp=.o)
TARGET = main

all: $(TARGET)

$(TARGET): $(OBJ_FILES)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ_FILES)

fclean: clean
	rm -f $(TARGET)

re: fclean all

.PHONY: all clean fclean re