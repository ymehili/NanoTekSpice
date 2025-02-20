/*
** EPITECH PROJECT, 2025
** B-OOP-400-LYN-4-1-tekspice-spencer.pay
** File description:
** main
*/

#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <map>
#include <sstream>
#include "src/Circuit.hpp"

enum TOKENTYPE
{
    DOTCHIPSETS,
    DOTLINKS,
    STRING,
    INTEGER,
    COLON,
    NEWLINE,
    END
};

struct Token
{
    TOKENTYPE type;
    std::string value;
    int line;
};

bool isworddigit(std::string str)
{
    for (size_t i = 0; i < str.size(); ++i)
    {
        if (!std::isdigit(str[i]))
            return false;
    }
    return true;
}

std::vector<Token> tokenize(std::ifstream &file)
{
    std::vector<Token> tokens;
    std::string line;
    int lineNumber = 0;

    while (std::getline(file, line))
    {
        lineNumber++;
        for (size_t i = 0; i < line.size(); ++i)
        {
            char c = line[i];
            if (c == ' ' || c == '\t')
                continue;
            else if (c == '#')
            {
                tokens.push_back({NEWLINE, "\n", lineNumber});
                break;
            }
            else if (c == '.')
            {
                std::string keyword;
                while (std::isalpha(line[i]))
                {
                    keyword += line[i];
                    i++;
                }
                if (keyword == "chipsets")
                    tokens.push_back({DOTCHIPSETS, keyword, lineNumber});
                else if (keyword == "links")
                    tokens.push_back({DOTLINKS, keyword, lineNumber});
                else
                    std::cerr << "Error: Unexpected keyword at line " << lineNumber << std::endl;
            }
            else if (std::isalpha(c) || std::isdigit(c))
            {
                std::string identifier;
                while (std::isalpha(line[i]) || std::isdigit(line[i]))
                {
                    identifier += line[i];
                    i++;
                }
                if (isworddigit(identifier))
                    tokens.push_back({INTEGER, identifier, lineNumber});
                else
                    tokens.push_back({STRING, identifier, lineNumber});
            }
            else if (c == ':')
                tokens.push_back({COLON, ":", lineNumber});
            else if (c == '\n')
                tokens.push_back({NEWLINE, "\n", lineNumber});
            else if (c == EOF)
                tokens.push_back({END, "EOF", lineNumber});
            else
                std::cerr << "Error: Unexpected character at line " << lineNumber << std::endl;
        }
    }

    return tokens;
}

void parse(std::vector<Token> tokens, Circuit &circuit)
{
    int i = 0;

    if (tokens[i].type != DOTCHIPSETS)
        std::cerr << "Error: Expected .chipsets" << std::endl;

    for (i = 1; tokens[i].type != DOTLINKS; i++)
    {
        if (tokens[i].type == STRING || tokens[i].type == INTEGER)
        {
            std::string type = tokens[i].value;
            i++;
            if (tokens[i].type != STRING)
                std::cerr << "Error: Expected string at line " << tokens[i].line << std::endl;

            std::string name = tokens[i].value;
            i++;
            if (tokens[i].type != NEWLINE)
                std::cerr << "Error: Expected newline at line " << tokens[i].line << std::endl;

            circuit.createComponent(type, name);
        }
        else
            std::cerr << "Error: Expected component type at line " << tokens[i].line << std::endl;
    }

    if (tokens[i].type != DOTLINKS)
        std::cerr << "Error: Expected .links" << std::endl;

    for (i++; tokens[i].type != END; i++)
    {
        if (tokens[i].type == STRING)
        {
            std::string name1 = tokens[i].value;

            i++;
            if (tokens[i].type != COLON)
                std::cerr << "Error: Expected colon at line " << tokens[i].line << std::endl;

            i++;
            if (tokens[i].type != INTEGER)
                std::cerr << "Error: Expected integer at line " << tokens[i].line << std::endl;
            std::string pin1 = tokens[i].value;
            i++;

            if (tokens[i].type != STRING)
                std::cerr << "Error: Expected string at line " << tokens[i].line << std::endl;
            std::string name2 = tokens[i].value;
            i++;

            if (tokens[i].type != COLON)
                std::cerr << "Error: Expected colon at line " << tokens[i].line << std::endl;
            i++;

            if (tokens[i].type != INTEGER)
                std::cerr << "Error: Expected integer at line " << tokens[i].line << std::endl;
            std::string pin2 = tokens[i].value;
            i++;

            if (tokens[i].type != NEWLINE)
                std::cerr << "Error: Expected newline at line " << tokens[i].line << std::endl;

            circuit.connect(name1, std::stoi(pin1), name2, std::stoi(pin2));
        }
        else
            std::cerr << "Error: Expected component name at line " << tokens[i].line << std::endl;
    }
}

void start(Circuit &circuit)
{
    std::string command;
    while (true)
    {
        std::cout << "> ";
        std::getline(std::cin, command);

        if (command == "exit")
            break;
        else if (command == "simulate")
            circuit.simulate();
        else if (command == "display")
            circuit.display();
        else if (command.find('=') != std::string::npos)
        {
            std::istringstream iss(command);
            std::string name, value;
            if (std::getline(iss, name, '=') && std::getline(iss, value))
                circuit.setInputValue(name, std::stoi(value));
            else
                std::cerr << "Error: Invalid input command" << std::endl;
        }
        else
            std::cerr << "Error: Unknown command" << std::endl;
    }
}

int main(int ac, char **av)
{
    std::ifstream file(av[1]);
    if (!file.is_open())
        return 1;

    std::vector<Token> tokens;
    Circuit circuit;

    tokens = tokenize(file);
    parse(tokens, circuit);

    start(circuit);
    return 0;
}
