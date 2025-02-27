/*
** EPITECH PROJECT, 2025
** B-OOP-400-LYN-4-1-tekspice-spencer.pay
** File description:
** C4040_counter
*/

#include "include/C4040_counter.hpp"

namespace nts
{
    Tristate C4040::compute(std::size_t pin)
    {
        Tristate clock = _links[10 - 1].first ? _links[10 - 1].first->compute(_links[10 - 1].second) : Tristate::Undefined;
        Tristate reset = _links[11 - 1].first ? _links[11 - 1].first->compute(_links[11 - 1].second) : Tristate::Undefined;

        if (reset == Tristate::True)
            _counter = 0;

        else if (_prevclock == Tristate::True && clock == Tristate::False)
            _counter = (_counter + 1) & 0b111111111111;

        _prevclock = clock;

        switch (pin)
        {
        case 9:
            return (_counter & 0b000000000001) ? Tristate::True : Tristate::False;
        case 7:
            return (_counter & 0b000000000010) ? Tristate::True : Tristate::False;
        case 6:
            return (_counter & 0b000000000100) ? Tristate::True : Tristate::False;
        case 5:
            return (_counter & 0b000000001000) ? Tristate::True : Tristate::False;
        case 3:
            return (_counter & 0b000000010000) ? Tristate::True : Tristate::False;
        case 2:
            return (_counter & 0b000000100000) ? Tristate::True : Tristate::False;
        case 4:
            return (_counter & 0b000001000000) ? Tristate::True : Tristate::False;
        case 13:
            return (_counter & 0b000010000000) ? Tristate::True : Tristate::False;
        case 12:
            return (_counter & 0b000100000000) ? Tristate::True : Tristate::False;
        case 14:
            return (_counter & 0b001000000000) ? Tristate::True : Tristate::False;
        case 15:
            return (_counter & 0b010000000000) ? Tristate::True : Tristate::False;
        case 1:
            return (_counter & 0b100000000000) ? Tristate::True : Tristate::False;
        default:
            return Tristate::Undefined;
        }
    }
}