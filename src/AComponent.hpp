/*
** EPITECH PROJECT, 2025
** B-OOP-400-LYN-4-1-tekspice-spencer.pay
** File description:
** AComponent
*/

#ifndef ACOMPONENT_HPP_
#define ACOMPONENT_HPP_
#include "IComponent.hpp"
#include <map>

namespace nts
{
    class AComponent : public nts::IComponent
    {
    protected:
        std::string _name;
        std::size_t _nbpins;

        std::map<std::size_t, std::pair<IComponent *, std::size_t>> _links;

    public:
        AComponent::AComponent(const std::string &name, std::size_t nbpins)
            : _name(name), _nbpins(nbpins)
        {
            for (std::size_t i = 0; i < nbpins; ++i)
            {
                _links[i] = {nullptr, 0};
            }
        }

        ~AComponent() = default;

        virtual Tristate compute(std::size_t pin = 1) = 0;
        void simulate(std ::size_t tick){
        };

        void AComponent::setLink(std::size_t pin, IComponent &other, std::size_t otherPin)
        {
            if (pin == 0 || pin > _nbpins)
                return;
            _links[pin - 1] = {&other, otherPin};
        }
    };
}

#endif /* !ACOMPONENT_HPP_ */
