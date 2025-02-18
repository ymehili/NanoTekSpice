/*
** EPITECH PROJECT, 2025
** Untitled (Workspace)
** File description:
** OutputComponent
*/

#ifndef OUTPUTCOMPONENT_HPP_
#define OUTPUTCOMPONENT_HPP_

#include "../AComponent.hpp"

namespace nts
{
    class OutputComponent : public nts::AComponent
    {
    public:
        OutputComponent() : AComponent("input", 1) {}
        ~OutputComponent() = default;

        Tristate compute()
        {
            if (_links[pin] == nullptr)
                return UNDEFINED;
            return getLink(pin);
        }
    };
}

#endif /* !OUTPUTCOMPONENT_HPP_ */
