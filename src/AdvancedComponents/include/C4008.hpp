/*
** EPITECH PROJECT, 2025
** B-OOP-400-LYN-4-1-tekspice-spencer.pay
** File description:
** C4008
*/

#ifndef C4008_HPP_
#define C4008_HPP_

#include "../../AComponent.hpp"

namespace nts
{
    class C4008 : public AComponent
    {
    public:
        C4008() : AComponent(16) {}
        ~C4008() = default;

        Tristate compute(std::size_t pin) override;

    private:
        std::pair<Tristate, Tristate> add(Tristate a, Tristate b, Tristate cin);
    };
}

#endif /* !C4008_HPP_ */