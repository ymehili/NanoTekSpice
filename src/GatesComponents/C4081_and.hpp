/*
** EPITECH PROJECT, 2025
** B-OOP-400-LYN-4-1-tekspice-spencer.pay
** File description:
** C4081_and
*/

#ifndef C4081_AND_HPP_
#define C4081_AND_HPP_

#include "../AComponent.hpp"

namespace nts {
    class C4081 : public AComponent
    {
        C4081() : AComponent(14) {}
        ~C4081() = default;

        Tristate compute(std::size_t pin) override
        {
            switch (pin)
            {
                case 3:
                    return computeAND(1, 2);
                case 4:
                    return computeAND(5, 6);
                case 10:
                    return computeAND(8, 9);
                case 11:
                    return computeAND(12, 13);
                default:
                    return Tristate::Undefined;
            }
        }

    private:
        Tristate computeAND(std::size_t pin1, std::size_t pin2)
        {
            Tristate a = _links[pin1 - 1].first ? _links[pin1 - 1].first->compute(_links[pin1 - 1].second) : Tristate::Undefined;
            Tristate b = _links[pin2 - 1].first ? _links[pin2 - 1].first->compute(_links[pin2 - 1].second) : Tristate::Undefined;

            if (a == Tristate::False || b == Tristate::False)
                return Tristate::False;
            if (a == Tristate::Undefined || b == Tristate::Undefined)
                return Undefined;
            return Tristate::True;
        }
    };
};

#endif /* !C4081_AND_HPP_ */
