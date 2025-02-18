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
        Tristate _value = UNDEFINED;
    public:
        InputComponent() : AComponent("input", 1) {}
        ~InputComponent() = default;

        void setValue(Tristate value)
        {
            _value = value;
        }

        Tristate compute()
        {
            return _value;
        }
    };
}

#endif /* !INPUTCOMPONENT_HPP_ */
