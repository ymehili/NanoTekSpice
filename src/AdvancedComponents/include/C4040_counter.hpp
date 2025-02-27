/*
** EPITECH PROJECT, 2025
** B-OOP-400-LYN-4-1-tekspice-spencer.pay
** File description:
** C4040_counter
*/

#ifndef C4040_COUNTER_HPP_
#define C4040_COUNTER_HPP_

#include "../../AComponent.hpp"

namespace nts
{
    class C4040 : public AComponent
    {
    private:
        std::size_t _counter;
        Tristate _prevclock;

    public:
        C4040() : AComponent(16), _counter(0), _prevclock(Tristate::Undefined) {}
        ~C4040() = default;

        Tristate compute(std::size_t pin) override;
    };
}

#endif /* !C4040_COUNTER_HPP_ */