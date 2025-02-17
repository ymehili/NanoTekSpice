/*
** EPITECH PROJECT, 2025
** Untitled (Workspace)
** File description:
** FalseComponent
*/

#ifndef FALSECOMPONENT_HPP_
#define FALSECOMPONENT_HPP_

#include "AComponent.hpp"

namespace nts
{
    class FalseComponent : public nts::AComponent
    {
    public:
        FalseComponent();
        ~FalseComponent();

        int compute(std::size_t pin);
    };
}

#endif /* !FALSECOMPONENT_HPP_ */
