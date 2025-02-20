/*
** EPITECH PROJECT, 2025
** Untitled (Workspace)
** File description:
** FalseComponent
*/

#ifndef FALSECOMPONENT_HPP_
#define FALSECOMPONENT_HPP_

#include "../AComponent.hpp"

namespace nts
{
    class FalseComponent : public nts::AComponent
    {
    public:
        FalseComponent(): AComponent(1) {};
        ~FalseComponent() = default;

        Tristate compute(std::size_t pin = 1){
            (void)pin;
            return Tristate::False;
        }
    };
}

#endif /* !FALSECOMPONENT_HPP_ */
