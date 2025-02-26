/*
** EPITECH PROJECT, 2025
** B-OOP-400-LYN-4-1-tekspice-spencer.pay
** File description:
** C4017_johnson
*/

#ifndef C4017_JOHNSON_HPP_
#define C4017_JOHNSON_HPP_

#include "../../AComponent.hpp"

namespace nts
{
    class C4017 : public AComponent
    {
    private:
        int _counter;
        Tristate _prev;

    public:
        C4017() : AComponent(16), _counter(0), _prev(Tristate::Undefined) {}
        ~C4017() = default;

        Tristate compute(std::size_t pin) override;
    };
}

#endif /* !C4017_JOHNSON_HPP_ */