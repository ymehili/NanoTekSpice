/*
** EPITECH PROJECT, 2025
** B-OOP-400-LYN-4-1-tekspice-spencer.pay
** File description:
** Parser
*/

#include "Parser.hpp"
#include <iostream>

bool Parser::isworddigit(const std::string& str)
{
    for (char c : str) {
        if (!std::isdigit(c))
            return false;
    }
    return true;
}

std::vector<Token> Parser::tokenize(std::ifstream& file)
{
    std::string line;
    int lineNumber = 0;

    while (std::getline(file, line)) {
        lineNumber++;
        bool addNewline = true;

        for (size_t i = 0; i < line.size(); ++i) {
            char c = line[i];
            if (c == ' ' || c == '\t')
                continue;
            else if (c == '#') {
                tokens.push_back({NEWLINE, "\n", lineNumber});
                addNewline = false;
                break;
            }
            else if (c == '.') {
                std::string keyword;
                i++;
                while (i < line.size() && std::isalpha(line[i])) {
                    keyword += line[i];
                    i++;
                }
                if (keyword == "chipsets")
                    tokens.push_back({DOTCHIPSETS, keyword, lineNumber});
                else if (keyword == "links")
                    tokens.push_back({DOTLINKS, keyword, lineNumber});
                else
                    throw std::runtime_error("Error: Unexpected keyword at line " + std::to_string(lineNumber) + " : " + keyword);
            }
            else if (std::isalpha(c) || std::isdigit(c)) {
                std::string identifier;
                while (i < line.size() && line[i] != ' ' && line[i] != '\n' && line[i] != '\t' && line[i] != ':') {
                    identifier += line[i];
                    i++;
                }
                i--;
                if (isworddigit(identifier))
                    tokens.push_back({INTEGER, identifier, lineNumber});
                else
                    tokens.push_back({STRING, identifier, lineNumber});
            }
            else if (c == ':')
                tokens.push_back({COLON, ":", lineNumber});
            else if (c == EOF)
                tokens.push_back({END, "EOF", lineNumber});
            else if (c != '\n')
                throw std::runtime_error("Error: Unexpected character at line " + std::to_string(lineNumber));
        }
        if (addNewline && !line.empty()) {
            tokens.push_back({NEWLINE, "\n", lineNumber});
        }
    }
    tokens.push_back({END, "EOF", lineNumber});
    return tokens;
}

void Parser::parse(Circuit& circuit)
{
    std::size_t i = 0;

    while (tokens[i].type != DOTCHIPSETS && tokens[i].type != END)
        i++;

    if (tokens[i].type != DOTCHIPSETS && tokens[i++].type != NEWLINE)
        throw std::runtime_error("Error: Expected .chipsets");

    i++;

    for (; i < tokens.size() && tokens[i + 1].type != DOTLINKS; i++) {
        if (tokens[i].type == STRING || tokens[i].type == INTEGER) {
            std::string type = tokens[i].value;
            i++;
            if (tokens[i].type != STRING)
                throw std::runtime_error("Error: Expected string at line " + std::to_string(tokens[i].line));

            std::string name = tokens[i].value;
            i++;
            if (tokens[i].type != NEWLINE)
                throw std::runtime_error("Error: Expected newline at line " + std::to_string(tokens[i].line));

            circuit.createComponent(type, name);
        }
        else if (tokens[i].type == DOTLINKS)
            break;
        else if (tokens[i].type == NEWLINE)
            continue;
        else
            throw std::runtime_error("Error: Expected component type at line " + std::to_string(tokens[i].line));
    }

    if (tokens[i].type != DOTLINKS && tokens[i++].type != NEWLINE)
        throw std::runtime_error("Error: Expected .links");

    if (circuit.getComponents().empty())
        throw std::runtime_error("Error: No components");

    i++;

    for (i++; i < tokens.size() && tokens[i].type != END; i++) {
        if (tokens[i].type == STRING) {
            std::string name1 = tokens[i].value;

            i++;
            if (tokens[i].type != COLON)
                throw std::runtime_error("Error: Expected colon at line " + std::to_string(tokens[i].line));

            i++;
            if (tokens[i].type != INTEGER)
                throw std::runtime_error("Error: Expected integer at line " + std::to_string(tokens[i].line));
            std::string pin1 = tokens[i].value;
            i++;

            if (tokens[i].type != STRING)
                throw std::runtime_error("Error: Expected string at line " + std::to_string(tokens[i].line));
            std::string name2 = tokens[i].value;
            i++;

            if (tokens[i].type != COLON)
                throw std::runtime_error("Error: Expected colon at line " + std::to_string(tokens[i].line));
            i++;

            if (tokens[i].type != INTEGER)
                throw std::runtime_error("Error: Expected integer at line " + std::to_string(tokens[i].line));
            std::string pin2 = tokens[i].value;
            i++;

            if (tokens[i].type != NEWLINE)
                throw std::runtime_error("Error: Expected newline at line " + std::to_string(tokens[i].line));

            circuit.connect(name1, std::stoi(pin1), name2, std::stoi(pin2));
        } else if (tokens[i].type == NEWLINE)
            continue;
        else
            throw std::runtime_error("Error: Expected component name at line " + std::to_string(tokens[i].line));
    }
}

void Parser::parseFile(const std::string& filename, Circuit& circuit)
{
    std::ifstream file(filename);
    if (!file.is_open())
        throw std::runtime_error("Error: Could not open file " + filename);

    tokens = tokenize(file);
    parse(circuit);
    file.close();
}