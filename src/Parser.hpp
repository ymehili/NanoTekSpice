/*
** EPITECH PROJECT, 2025
** B-OOP-400-LYN-4-1-tekspice-spencer.pay
** File description:
** Parser
*/

#ifndef PARSER_HPP_
#define PARSER_HPP_

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include "Circuit.hpp"

enum TOKENTYPE {
    DOTCHIPSETS,
    DOTLINKS,
    STRING,
    INTEGER,
    COLON,
    NEWLINE,
    END
};

struct Token {
    TOKENTYPE type;
    std::string value;
    int line;
};

class Parser {
    public:
        Parser() = default;
        ~Parser() = default;

        void parseFile(const std::string& filename, Circuit& circuit);
        std::vector<Token> tokenize(std::ifstream& file);
        void parse(Circuit& circuit);
        bool isworddigit(const std::string& str);

    private:
        std::vector<Token> tokens;
};

#endif /* !PARSER_HPP_ */
