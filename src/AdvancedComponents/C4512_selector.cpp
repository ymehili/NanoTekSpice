/*
** EPITECH PROJECT, 2025
** B-OOP-400-LYN-4-1-tekspice-spencer.pay
** File description:
** C4512_selector
*/

#include "include/C4512_selector.hpp"

namespace nts
{
    Tristate C4512::compute(std::size_t pin)
    {
        if (pin != 14)
            return Tristate::Undefined;

        Tristate inhibit = _links[10 - 1].first ? _links[10 - 1].first->compute(_links[10 - 1].second) : Tristate::Undefined;
        Tristate enable = _links[15 - 1].first ? _links[15 - 1].first->compute(_links[15 - 1].second) : Tristate::Undefined;

        if (inhibit == Tristate::True || enable == Tristate::False)
            return Tristate::Undefined;

        Tristate in_a = _links[11 - 1].first ? _links[11 - 1].first->compute(_links[11 - 1].second) : Tristate::Undefined;
        Tristate in_b = _links[12 - 1].first ? _links[12 - 1].first->compute(_links[12 - 1].second) : Tristate::Undefined;
        Tristate in_c = _links[13 - 1].first ? _links[13 - 1].first->compute(_links[13 - 1].second) : Tristate::Undefined;

        if (in_a == Tristate::Undefined || in_b == Tristate::Undefined || in_c == Tristate::Undefined)
            return Tristate::Undefined;

        int channel = 0;
        if (in_a == Tristate::True)
            channel |= 1;
        if (in_b == Tristate::True)
            channel |= 2;
        if (in_c == Tristate::True)
            channel |= 4;

        int dataPin;
        switch (channel)
        {
        case 0:
            dataPin = 1;
            break;
        case 1:
            dataPin = 2;
            break;
        case 2:
            dataPin = 3;
            break;
        case 3:
            dataPin = 4;
            break;
        case 4:
            dataPin = 5;
            break;
        case 5:
            dataPin = 6;
            break;
        case 6:
            dataPin = 7;
            break;
        case 7:
            dataPin = 9;
            break;
        default:
            return Tristate::Undefined;
        }

        return _links[dataPin - 1].first ? _links[dataPin - 1].first->compute(_links[dataPin - 1].second) : Tristate::Undefined;
    }
}