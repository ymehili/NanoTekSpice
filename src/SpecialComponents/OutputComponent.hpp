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
    private:
        Tristate _value;

    public:
        OutputComponent() : AComponent(1), _value(Tristate::Undefined) {}
        ~OutputComponent() = default;

        Tristate compute(std::size_t pin = 1)
        {
            if (pin != 1)
                return Tristate::Undefined;
            if (_links[0].first)
                _value = _links[0].first->compute(_links[0].second);
            return _value;
        }
    };
}

#endif /* !OUTPUTCOMPONENT_HPP_ */