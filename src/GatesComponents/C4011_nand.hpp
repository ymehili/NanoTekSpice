/*
** EPITECH PROJECT, 2025
** B-OOP-400-LYN-4-1-tekspice-spencer.pay
** File description:
** C4011_nand
*/

#ifndef C4011_NAND_HPP_
#define C4011_NAND_HPP_

#include "../AComponent.hpp"

namespace nts
{
    class C4011 : public AComponent
    {
    public:
        C4011() : AComponent(14) {}
        ~C4011() = default;

        Tristate compute(std::size_t pin) override
        {
            switch (pin)
            {
            case 3:
                return computeNAND(1, 2);
            case 4:
                return computeNAND(5, 6);
            case 10:
                return computeNAND(8, 9);
            case 11:
                return computeNAND(12, 13);
            default:
                return Tristate::Undefined;
            }
        }

    private:
        Tristate computeNAND(std::size_t pin1, std::size_t pin2){
            Tristate a = _links[pin1 - 1].first ? _links[pin1 - 1].first->compute(_links[pin1 - 1].second) : Tristate::Undefined;
            Tristate b = _links[pin2 - 1].first ? _links[pin2 - 1].first->compute(_links[pin2 - 1].second) : Tristate::Undefined;

            if (a == Tristate::False || b == Tristate::False)
                return Tristate::True;
            if (a == Tristate::Undefined || b == Tristate::Undefined)
                return Tristate::Undefined;
            return Tristate::False;
        }
    };
}

#endif /* !C4011_NAND_HPP_ */
