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
        TrueComponent(): AComponent("true", 1) {};
        ~TrueComponent() = default;

        Tristate compute() {
            return Tristate::TRUE;
        }
    };
}

#endif /* !TRUECOMPONENT_HPP_ */
