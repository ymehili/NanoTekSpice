/*
** EPITECH PROJECT, 2025
** B-OOP-400-LYN-4-1-tekspice-spencer.pay
** File description:
** C4030
*/

#ifndef C4030_HPP_
#define C4030_HPP_

#include "../AComponent.hpp"

namespace nts
{
    class C4030 : public AComponent
    {
    public:
        C4030() : AComponent(14) {}
        ~C4030() = default;

        Tristate compute(std::size_t pin)
        {
            switch (pin)
            {
            case 3:
                return computeXOR(1, 2);
            case 4:
                return computeXOR(5, 6);
            case 10:
                return computeXOR(8, 9);
            case 11:
                return computeXOR(12, 13);
            default:
                return Tristate::Undefined;
            }
        }

    private:
        Tristate computeXOR(std::size_t pin1, std::size_t pin2)
        {
            Tristate a = _links[pin1 - 1].first ? _links[pin1 - 1].first->compute(_links[pin1 - 1].second) : Tristate::Undefined;
            Tristate b = _links[pin2 - 1].first ? _links[pin2 - 1].first->compute(_links[pin2 - 1].second) : Tristate::Undefined;

            if (a == Tristate::Undefined || b == Tristate::Undefined)
                return Tristate::Undefined;

            if ((a == Tristate::True && b == Tristate::False) ||
                (a == Tristate::False && b == Tristate::True))
                return Tristate::True;

            return Tristate::False;
        }
    };
}

#endif /* !C4030_HPP_ */
