##
## EPITECH PROJECT, 2025
## B-OOP-400-LYN-4-1-tekspice-spencer.pay
## File description:
## Makefile
##

CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17
SRC_DIR = src
SRC_FILES = $(shell find $(SRC_DIR) -name "*.cpp") main.cpp
OBJ_DIR = .obj
OBJ_FILES = $(addprefix $(OBJ_DIR)/, $(SRC_FILES:.cpp=.o))
TARGET = nanotekspice

all: $(TARGET)

$(TARGET): $(OBJ_FILES)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(TARGET)

re: fclean all

.PHONY: all clean fclean re