/*
** EPITECH PROJECT, 2025
** Untitled (Workspace)
** File description:
** AndComponent
*/

#ifndef ANDCOMPONENT_HPP_
#define ANDCOMPONENT_HPP_

#include "../AComponent.hpp"

namespace nts {
    class AndComponent : public AComponent {
        public:
            AndComponent() : AComponent(2) {}
            ~AndComponent() = default;

            Tristate compute(std::size_t pin = 3) {
                if (pin != 3)
                    return Tristate::Undefined;
                Tristate a = _links[0].first ? _links[0].first->compute(_links[0].second) : Tristate::Undefined;
                Tristate b = _links[1].first ? _links[1].first->compute(_links[1].second) : Tristate::Undefined;
                if (a == Tristate::True && b == Tristate::True)
                    return Tristate::True;
                if (a == Tristate::Undefined || b == Tristate::Undefined)
                    return Tristate::Undefined;
                return Tristate::False;
            }
    };
}

#endif /* !ANDCOMPONENT_HPP_ */