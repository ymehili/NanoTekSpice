/*
** EPITECH PROJECT, 2025
** Untitled (Workspace)
** File description:
** InputComponent
*/

#ifndef INPUTCOMPONENT_HPP_
#define INPUTCOMPONENT_HPP_

#include "../AComponent.hpp"

namespace nts
{
    class InputComponent : public nts::AComponent
    {
    private:
        Tristate _value;

    public:
        InputComponent() : AComponent("input", 1), _value(Tristate::Undefined) {}
        ~InputComponent() = default;

        void setValue(Tristate value)
        {
            _value = value;
        }

        Tristate compute(std::size_t pin = 1)
        {
            if (pin != 1)
                return Tristate::Undefined;
            return _value;
        }
    };
}

#endif /* !INPUTCOMPONENT_HPP_ */
