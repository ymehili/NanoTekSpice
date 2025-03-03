/*
** EPITECH PROJECT, 2025
** B-OOP-400-LYN-4-1-tekspice-spencer.pay
** File description:
** C4512_selector
*/

#ifndef C4512_SELECTOR_HPP_
#define C4512_SELECTOR_HPP_

#include "../../AComponent.hpp"

namespace nts
{
    class C4512 : public AComponent
    {
    public:
        C4512() : AComponent(16) {}
        ~C4512() = default;

        Tristate compute(std::size_t pin) override;
    };
}

#endif /* !C4512_SELECTOR_HPP_ */