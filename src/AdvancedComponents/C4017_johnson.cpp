/*
** EPITECH PROJECT, 2025
** B-OOP-400-LYN-4-1-tekspice-spencer.pay
** File description:
** C4017_johnson
*/

#include "include/C4017_johnson.hpp"

namespace nts
{
    Tristate C4017::compute(std::size_t pin)
    {
        Tristate in_1 = _links[14 - 1].first ? _links[14 - 1].first->compute(_links[14 - 1].second) : Tristate::Undefined;
        Tristate in_2 = _links[13 - 1].first ? _links[13 - 1].first->compute(_links[13 - 1].second) : Tristate::Undefined;
        Tristate reset = _links[15 - 1].first ? _links[15 - 1].first->compute(_links[15 - 1].second) : Tristate::Undefined;

        if (reset == Tristate::True)
            _counter = 0;

        else if (in_1 == Tristate::True && _prev != Tristate::True && in_2 != Tristate::Undefined)
            _counter = (_counter + 1) % 10;

        _prev = in_1;

        switch (pin)
        {
        case 3:
            return (_counter == 0) ? Tristate::True : Tristate::False;
        case 2:
            return (_counter == 1) ? Tristate::True : Tristate::False;
        case 4:
            return (_counter == 2) ? Tristate::True : Tristate::False;
        case 7:
            return (_counter == 3) ? Tristate::True : Tristate::False;
        case 10:
            return (_counter == 4) ? Tristate::True : Tristate::False;
        case 1:
            return (_counter == 5) ? Tristate::True : Tristate::False;
        case 5:
            return (_counter == 6) ? Tristate::True : Tristate::False;
        case 6:
            return (_counter == 7) ? Tristate::True : Tristate::False;
        case 9:
            return (_counter == 8) ? Tristate::True : Tristate::False;
        case 11:
            return (_counter == 9) ? Tristate::True : Tristate::False;
        case 12:
            return (_counter >= 5) ? Tristate::True : Tristate::False;
        }
    }
}