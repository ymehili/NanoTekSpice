/*
** EPITECH PROJECT, 2025
** B-OOP-400-LYN-4-1-tekspice-spencer.pay
** File description:
** LoggerComponent
*/

#ifndef LOGGERCOMPONENT_HPP_
#define LOGGERCOMPONENT_HPP_

#include "../AComponent.hpp"
#include <iostream>
#include <fstream>

#define CLOCK_INDEX 8
#define INHIBIT_INDEX 9
#define BYTE_INPUTS 7 // 8 - 1 since we start at 0

namespace nts
{
    class LoggerComponent : public AComponent
    {
    public:
        LoggerComponent() : AComponent(10) {}
        ~LoggerComponent() = default;

        void simulate(std::size_t pin = 1)
        {
            (void)pin;
            Tristate clock_state = _links[CLOCK_INDEX].first ? _links[CLOCK_INDEX].first->compute(_links[CLOCK_INDEX].second) : Tristate::Undefined;
            if (clock_state != Tristate::True) // if Undefined or False, do nothing
                return;

            Tristate inhibit = _links[INHIBIT_INDEX].first ? _links[INHIBIT_INDEX].first->compute(_links[INHIBIT_INDEX].second) : Tristate::Undefined;
            if (inhibit != Tristate::False) // if Undefined or True, do nothing (false = no inhibition -> we print)
                return;

            char character = 0;
            for (int i = 0; i < BYTE_INPUTS; i++){
                Tristate bit_state = _links[i].first ? _links[i].first->compute(_links[i].second) : Tristate::Undefined;
                if (bit_state == Tristate::Undefined)
                    return;
                if (bit_state == Tristate::True)
                    character |= (1 << i);
            }

            std::ofstream logFile("log.bin", std::ios::app | std::ios::binary);
            if (logFile.is_open()){
                logFile.write(&character, 1);
                logFile.close();
            } else {
                std::cerr << "Error: Unable to open log.bin for writing." << std::endl;
            }
            return;
        }

        Tristate compute(std::size_t pin = 1)
        {
            (void)pin;
            return Tristate::Undefined;
        }
    };
}

#endif /* !LOGGERCOMPONENT_HPP_ */
