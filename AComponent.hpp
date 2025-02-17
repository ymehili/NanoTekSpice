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
        std::size_t _inputpins;
        std::size_t _outputpins;

        std::map<std::size_t, std::pair<IComponent *, std::size_t>> _links;
    public:
        AComponent(std::string name, std::size_t inputpins, std::size_t outputpins) : _name(name), _inputpins(inputpins), _outputpins(outputpins) {};
        ~AComponent() = default;

        Tristate compute(std::size_t pin) = 0;
        void simulate() {};

        void setLink(std::size_t pin, IComponent &other, std::size_t otherPin) override {
            _links[pin] = std::make_pair(&other, otherPin);
            other.setLink(otherPin, *this, pin);
        }

        auto getLink(std::size_t pin) {
            std::pair<IComponent *, std::size_t> pair =  _links[pin];
            pair.first->compute(pair.second);
        }
    };
}

#endif /* !ACOMPONENT_HPP_ */
