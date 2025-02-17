/*
** EPITECH PROJECT, 2025
** B-OOP-400-LYN-4-1-tekspice-spencer.pay
** File description:
** IComponent
*/

#ifndef ICOMPONENT_HPP_
#define ICOMPONENT_HPP_

#include <cstddef>

namespace nts
{
    class IComponent
    {
    public:
        enum Tristate
        {
            UNDEFINED = (-true),
            TRUE = true,
            FALSE = false
        };
        virtual ~IComponent() = default;

        virtual Tristate compute(std::size_t pin) = 0;
        virtual void setLink(std::size_t pin, IComponent &other, std::size_t otherPin) = 0;
        virtual void simulate() = 0;
    };
}

#endif /* !ICOMPONENT_HPP_ */