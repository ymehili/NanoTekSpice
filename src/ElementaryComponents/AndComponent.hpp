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
            AndComponent();
            ~AndComponent();

            Tristate compute(std::size_t pin) {
            }
    };
}

#endif /* !ANDCOMPONENT_HPP_ */
