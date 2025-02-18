/*
** EPITECH PROJECT, 2025
** Untitled (Workspace)
** File description:
** NotComponent
*/

#ifndef NOTCOMPONENT_HPP_
#define NOTCOMPONENT_HPP_

#include "../AComponent.hpp"

namespace nts {
    class NotComponent : public AComponent {
        public:
            NotComponent() : AComponent("not", 2) {}
            ~NotComponent() = default;

            Tristate compute(std::size_t pin = 2) override {
                if (pin != 2)
                    return Tristate::Undefined;
                Tristate input = _links[0].first ? _links[0].first->compute(_links[0].second) : Tristate::Undefined;
                if (input == Tristate::True)
                    return Tristate::False;
                if (input == Tristate::False)
                    return Tristate::True;
                return Tristate::Undefined;
            }
    };
}

#endif /* !NOTCOMPONENT_HPP_ */