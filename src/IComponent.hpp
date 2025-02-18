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
    enum class Tristate
    {
        UNDEFINED = -1,
        FALSE = 0,
        TRUE = 1
    };

    class IComponent
    {
    public:
        virtual ~IComponent() = default;

        virtual Tristate compute(std::size_t pin = 1) = 0;
        virtual void setLink(std::size_t pin, IComponent &other, std::size_t otherPin) = 0;
        virtual void simulate() = 0;
        virtual Tristate getValue() = 0;
    };
}

#endif /* !ICOMPONENT_HPP_ */