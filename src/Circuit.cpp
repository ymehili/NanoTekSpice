/*
** EPITECH PROJECT, 2025
** B-OOP-400-LYN-4-1-tekspice-spencer.pay
** File description:
** Circuit
*/

#include "Circuit.hpp"
#include <iostream>
#include <unistd.h>

void Circuit::start()
{
    std::string command;
    bool istty = isatty(STDIN_FILENO);

    while (true)
    {
        std::cout << "> ";
        std::cout.flush();

        if (!std::getline(std::cin, command)) {
            if (istty) {
                std::cout << std::endl;
            }
            break;
        }

        try {
            if (command == "exit")
                break;
            else if (command == "simulate")
                simulate();
            else if (command == "display")
                display();
            else if (!command.empty())
                _buffer.push_back(command);
        } catch (const std::exception& e) {
            std::cerr << e.what() << std::endl;
        }
    }
}