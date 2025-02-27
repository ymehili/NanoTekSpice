/*
** EPITECH PROJECT, 2025
** B-OOP-400-LYN-4-1-tekspice-spencer.pay
** File description:
** C4069_not
*/

#ifndef C4069_NOT_HPP_
#define C4069_NOT_HPP_

#include "../AComponent.hpp"

namespace nts
{
    class C4069 : public AComponent
    {
    public:
        C4069() : AComponent(14) {}
        ~C4069() = default;

        Tristate compute(std::size_t pin) override
        {
            switch (pin)
            {
            case 2:
                return computeNOT(1);
            case 4:
                return computeNOT(3);
            case 6:
                return computeNOT(5);
            case 8:
                return computeNOT(9);
            case 10:
                return computeNOT(11);
            case 12:
                return computeNOT(13);
            default:
                return Tristate::Undefined;
            }
        }

    private:
        Tristate computeNOT(std::size_t pin)
        {
            Tristate a = _links[pin - 1].first ? _links[pin - 1].first->compute(_links[pin - 1].second) : Tristate::Undefined;

            if (a == Tristate::Undefined)
                return Tristate::Undefined;
            if (a == Tristate::True)
                return Tristate::False;
            return Tristate::True;
        }
    };
}

#endif /* !C4069_NOT_HPP_ */
