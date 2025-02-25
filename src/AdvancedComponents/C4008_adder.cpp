/*
** EPITECH PROJECT, 2025
** B-OOP-400-LYN-4-1-tekspice-spencer.pay
** File description:
** C4008
*/

#include "include/C4008_adder.hpp"

namespace nts
{
    std::pair<Tristate, Tristate> C4008::add(Tristate a, Tristate b, Tristate cin)
    {
        if (a == Tristate::Undefined || b == Tristate::Undefined || cin == Tristate::Undefined)
            return {Tristate::Undefined, Tristate::Undefined};

        bool a_val = (a == Tristate::True);
        bool b_val = (b == Tristate::True);
        bool cin_val = (cin == Tristate::True);

        bool sum = a_val ^ b_val ^ cin_val;
        bool cout = (a_val && b_val) || (a_val && cin_val) || (b_val && cin_val);

        return {sum ? Tristate::True : Tristate::False, cout ? Tristate::True : Tristate::False};
    }

    Tristate C4008::compute(std::size_t pin)
    {
        if (pin < 10 || pin > 14)
            return Tristate::Undefined;

        Tristate a1 = _links[6].first ? _links[6].first->compute(_links[6].second) : Tristate::Undefined;
        Tristate a2 = _links[4].first ? _links[4].first->compute(_links[4].second) : Tristate::Undefined;
        Tristate a3 = _links[2].first ? _links[2].first->compute(_links[2].second) : Tristate::Undefined;
        Tristate a4 = _links[0].first ? _links[0].first->compute(_links[0].second) : Tristate::Undefined;

        Tristate b1 = _links[5].first ? _links[5].first->compute(_links[5].second) : Tristate::Undefined;
        Tristate b2 = _links[3].first ? _links[3].first->compute(_links[3].second) : Tristate::Undefined;
        Tristate b3 = _links[1].first ? _links[1].first->compute(_links[1].second) : Tristate::Undefined;
        Tristate b4 = _links[14].first ? _links[14].first->compute(_links[14].second) : Tristate::Undefined;

        Tristate c0 = _links[8].first ? _links[8].first->compute(_links[8].second) : Tristate::Undefined;

        auto [o1, c1] = add(a1, b1, c0);
        auto [o2, c2] = add(a2, b2, c1);
        auto [o3, c3] = add(a3, b3, c2);
        auto [o4, c4] = add(a4, b4, c3);

        switch (pin)
        {
        case 10:
            return o1;
        case 11:
            return o2;
        case 12:
            return o3;
        case 13:
            return o4;
        case 14:
            return c4;
        }
    }
}