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
        FalseComponent(): AComponent("false", 1) {};
        ~FalseComponent() = default;

        Tristate compute() {
            return Tristate::FALSE;
        }
    };
}

#endif /* !FALSECOMPONENT_HPP_ */
