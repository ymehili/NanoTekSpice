/*
** EPITECH PROJECT, 2025
** Untitled (Workspace)
** File description:
** XorComponent
*/

#ifndef XORCOMPONENT_HPP_
#define XORCOMPONENT_HPP_

#include "../AComponent.hpp"

namespace nts
{
    class XorComponent : public AComponent
    {
    public:
        XorComponent() : AComponent(3) {}
        ~XorComponent() = default;

        Tristate compute(std::size_t pin = 3)
        {
            if (pin != 3)
                return Tristate::Undefined;
            Tristate a = _links[0].first ? _links[0].first->compute(_links[0].second) : Tristate::Undefined;
            Tristate b = _links[1].first ? _links[1].first->compute(_links[1].second) : Tristate::Undefined;

            if (a == Tristate::Undefined || b == Tristate::Undefined)
                return Tristate::Undefined;

            if ((a == Tristate::True && b == Tristate::False) ||
                (a == Tristate::False && b == Tristate::True))
                return Tristate::True;

            return Tristate::False;
        }
    };
}

#endif /* !XORCOMPONENT_HPP_ */