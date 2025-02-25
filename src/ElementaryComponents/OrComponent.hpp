/*
** EPITECH PROJECT, 2025
** Untitled (Workspace)
** File description:
** OrComponent
*/

#ifndef ORCOMPONENT_HPP_
#define ORCOMPONENT_HPP_

#include "../AComponent.hpp"

namespace nts {
    class OrComponent : public AComponent {
        public:
            OrComponent() : AComponent(3) {}
            ~OrComponent() = default;

            Tristate compute(std::size_t pin = 3) {
                if (pin != 3)
                    return Tristate::Undefined;
                Tristate a = _links[0].first ? _links[0].first->compute(_links[0].second) : Tristate::Undefined;
                Tristate b = _links[1].first ? _links[1].first->compute(_links[1].second) : Tristate::Undefined;
                if (a == Tristate::True || b == Tristate::True)
                    return Tristate::True;
                if (a == Tristate::Undefined || b == Tristate::Undefined)
                    return Tristate::Undefined;
                return Tristate::False;
            }
    };
}

#endif /* !ORCOMPONENT_HPP_ */