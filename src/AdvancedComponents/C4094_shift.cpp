/*
** EPITECH PROJECT, 2025
** B-OOP-400-LYN-4-1-tekspice-spencer.pay
** File description:
** C4094_shift
*/

#include "include/C4094_shift.hpp"

namespace nts
{
    Tristate C4094::compute(std::size_t pin)
    {
        Tristate clock = _links[3 - 1].first ? _links[3 - 1].first->compute(_links[3 - 1].second) : Tristate::Undefined;
        Tristate data = _links[2 - 1].first ? _links[2 - 1].first->compute(_links[2 - 1].second) : Tristate::Undefined;
        Tristate strobe = _links[1 - 1].first ? _links[1 - 1].first->compute(_links[1 - 1].second) : Tristate::Undefined;
        Tristate enable = _links[15 - 1].first ? _links[15 - 1].first->compute(_links[15 - 1].second) : Tristate::Undefined;

        if (_prevclock != Tristate::True && clock == Tristate::True)
        {
            for (int i = 7; i > 0; i--)
                _shiftreg[i] = _shiftreg[i - 1];
            _shiftreg[0] = data;

            if (strobe == Tristate::True)
            {
                for (int i = 0; i < 8; i++)
                    _storedreg[i] = _shiftreg[i];
            }
        }

        _prevclock = clock;

        switch (pin)
        {
        case 4:
            return enable == Tristate::True ? _storedreg[0] : Tristate::Undefined;
        case 5:
            return enable == Tristate::True ? _storedreg[1] : Tristate::Undefined;
        case 6:
            return enable == Tristate::True ? _storedreg[2] : Tristate::Undefined;
        case 7:
            return enable == Tristate::True ? _storedreg[3] : Tristate::Undefined;
        case 14:
            return enable == Tristate::True ? _storedreg[4] : Tristate::Undefined;
        case 13:
            return enable == Tristate::True ? _storedreg[5] : Tristate::Undefined;
        case 12:
            return enable == Tristate::True ? _storedreg[6] : Tristate::Undefined;
        case 11:
            return enable == Tristate::True ? _storedreg[7] : Tristate::Undefined;
        case 9:
            return enable == Tristate::True ? _shiftreg[7] : Tristate::Undefined;
        case 10:
            return enable;
        }
        return Tristate::Undefined;
    }
}