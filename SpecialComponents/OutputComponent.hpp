/*
** EPITECH PROJECT, 2025
** Untitled (Workspace)
** File description:
** OutputComponent
*/

#ifndef OUTPUTCOMPONENT_HPP_
#define OUTPUTCOMPONENT_HPP_

#include "AComponent.hpp"

namespace nts
{
    class OutputComponent : public nts::AComponent
    {
    public:
        OutputComponent() = default;
        ~OutputComponent() = default;

        int compute(std::size_t pin) {
            return 0;
        }
    };
}

#endif /* !OUTPUTCOMPONENT_HPP_ */
