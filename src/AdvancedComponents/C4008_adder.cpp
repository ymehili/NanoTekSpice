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

        Tristate a1 = _links[7 - 1].first ? _links[7 - 1].first->compute(_links[7 - 1].second) : Tristate::Undefined;
        Tristate a2 = _links[5 - 1].first ? _links[5 - 1].first->compute(_links[5 - 1].second) : Tristate::Undefined;
        Tristate a3 = _links[3 - 1].first ? _links[3 - 1].first->compute(_links[3 - 1].second) : Tristate::Undefined;
        Tristate a4 = _links[1 - 1].first ? _links[1 - 1].first->compute(_links[1 - 1].second) : Tristate::Undefined;

        Tristate b1 = _links[6 - 1].first ? _links[6 - 1].first->compute(_links[6 - 1].second) : Tristate::Undefined;
        Tristate b2 = _links[4 - 1].first ? _links[4 - 1].first->compute(_links[4 - 1].second) : Tristate::Undefined;
        Tristate b3 = _links[2 - 1].first ? _links[2 - 1].first->compute(_links[2 - 1].second) : Tristate::Undefined;
        Tristate b4 = _links[15 - 1].first ? _links[15 - 1].first->compute(_links[15 - 1].second) : Tristate::Undefined;

        Tristate in_c = _links[9 - 1].first ? _links[9 - 1].first->compute(_links[9 - 1].second) : Tristate::Undefined;

        auto [o0, c0] = add(a1, b1, in_c);
        auto [o1, c1] = add(a2, b2, c0);
        auto [o2, c2] = add(a3, b3, c1);
        auto [o3, out_c] = add(a4, b4, c2);

        switch (pin)
        {
        case 10:
            return o0;
        case 11:
            return o1;
        case 12:
            return o2;
        case 13:
            return o3;
        case 14:
            return out_c;
        }
        return Tristate::Undefined;
    }
}