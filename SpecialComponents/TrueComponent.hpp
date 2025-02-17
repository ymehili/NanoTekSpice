/*
** EPITECH PROJECT, 2025
** Untitled (Workspace)
** File description:
** TrueComponent
*/

#ifndef TRUECOMPONENT_HPP_
#define TRUECOMPONENT_HPP_

#include "AComponent.hpp"

namespace nts
{
    class TrueComponent : public nts::AComponent
    {
    public:
        TrueComponent();
        ~TrueComponent();

        int compute(std::size_t pin);
    };
}

#endif /* !TRUECOMPONENT_HPP_ */
