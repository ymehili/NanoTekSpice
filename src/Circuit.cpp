/*
** EPITECH PROJECT, 2025
** B-OOP-400-LYN-4-1-tekspice-spencer.pay
** File description:
** Circuit
*/

#include "Circuit.hpp"
#include <iostream>

void Circuit::start()
{
    std::string command;
    while (true)
    {
        std::cout << "> ";
        std::getline(std::cin, command);

        if (command == "exit")
            break;
        else if (command == "simulate")
            simulate();
        else if (command == "display")
            display();
        else
            _buffer.push_back(command);
    }
}