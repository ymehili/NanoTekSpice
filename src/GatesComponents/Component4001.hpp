/*
** EPITECH PROJECT, 2025
** B-OOP-400-LYN-4-1-tekspice-spencer.pay
** File description:
** Component4001
*/

#ifndef COMPONENT4001_HPP_
#define COMPONENT4001_HPP_

#include "../AComponent.hpp"

namespace nts
{
    class Component4001 : public AComponent
    {
    public:
        Component4001() : AComponent(14) {}
        ~Component4001() = default;

        Tristate compute(std::size_t pin) override
        {
            switch (pin)
            {
            case 3:
                return computeNOR(1, 2);
            case 4:
                return computeNOR(5, 6);
            case 10:
                return computeNOR(8, 9);
            case 11:
                return computeNOR(12, 13);
            default:
                return Tristate::Undefined;
            }
        }

    private:
        Tristate computeNOR(std::size_t pin1, std::size_t pin2)
        {
            Tristate input1 = _links[pin1 - 1].first ? _links[pin1 - 1].first->compute(_links[pin1 - 1].second) : Tristate::Undefined;

            Tristate input2 = _links[pin2 - 1].first ? _links[pin2 - 1].first->compute(_links[pin2 - 1].second) : Tristate::Undefined;

            if (input1 == Tristate::Undefined || input2 == Tristate::Undefined)
                return Tristate::Undefined;

            if (input1 == Tristate::True || input2 == Tristate::True)
                return Tristate::False;

            return Tristate::True;
        }
    };
}

#endif /* !COMPONENT4001_HPP_ */
