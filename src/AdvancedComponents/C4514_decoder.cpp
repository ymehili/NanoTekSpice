/*
** EPITECH PROJECT, 2025
** B-OOP-400-LYN-4-1-tekspice-spencer.pay
** File description:
** C4514_decoder
*/

#include "include/C4514_decoder.hpp"

namespace nts
{
    Tristate C4514::compute(std::size_t pin)
    {
        const std::size_t outputPins[] = {11, 9, 10, 8, 7, 6, 5, 4, 18, 17, 20, 19, 14, 13, 16, 15};

        Tristate strobe = _links[1 - 1].first ? _links[1 - 1].first->compute(_links[1 - 1].second) : Tristate::Undefined;
        Tristate inhibit = _links[23 - 1].first ? _links[23 - 1].first->compute(_links[23 - 1].second) : Tristate::Undefined;

        if (inhibit == Tristate::True) {
            for (int i = 0; i < 16; i++) {
                if (pin == outputPins[i])
                    return Tristate::False;
            }
            return Tristate::Undefined;
        }

        if (strobe == Tristate::True) {
            Tristate in0 = _links[2 - 1].first ? _links[2 - 1].first->compute(_links[2 - 1].second) : Tristate::Undefined;
            Tristate in1 = _links[3 - 1].first ? _links[3 - 1].first->compute(_links[3 - 1].second) : Tristate::Undefined;
            Tristate in2 = _links[21 - 1].first ? _links[21 - 1].first->compute(_links[21 - 1].second) : Tristate::Undefined;
            Tristate in3 = _links[22 - 1].first ? _links[22 - 1].first->compute(_links[22 - 1].second) : Tristate::Undefined;

            if (in0 == Tristate::Undefined || in1 == Tristate::Undefined ||
                in2 == Tristate::Undefined || in3 == Tristate::Undefined) {
                return Tristate::Undefined;
            }

            _latchval = 0;
            if (in0 == Tristate::True) _latchval |= 1;
            if (in1 == Tristate::True) _latchval |= 2;
            if (in2 == Tristate::True) _latchval |= 4;
            if (in3 == Tristate::True) _latchval |= 8;
            _latch = true;
        }

        if (!_latch)
            return Tristate::Undefined;

        for (int i = 0; i < 16; i++) {
            if (pin == outputPins[i]) {
                return (i == _latchval) ? Tristate::True : Tristate::False;
            }
        }

        return Tristate::Undefined;
    }
}