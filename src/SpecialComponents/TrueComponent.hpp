/*
** EPITECH PROJECT, 2025
** Untitled (Workspace)
** File description:
** TrueComponent
*/

#ifndef TRUECOMPONENT_HPP_
#define TRUECOMPONENT_HPP_

#include "../AComponent.hpp"

namespace nts
{
    class TrueComponent : public nts::AComponent
    {
    public:
        TrueComponent(): AComponent(1) {};
        ~TrueComponent() = default;

        Tristate compute(std::size_t pin = 1) {
            (void)pin;
            return Tristate::True;
        }
    };
}

#endif /* !TRUECOMPONENT_HPP_ */
