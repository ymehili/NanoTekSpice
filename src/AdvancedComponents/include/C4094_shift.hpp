/*
** EPITECH PROJECT, 2025
** B-OOP-400-LYN-4-1-tekspice-spencer.pay
** File description:
** C4094_shift
*/

#ifndef C4094_SHIFT_HPP_
#define C4094_SHIFT_HPP_

#include "../../AComponent.hpp"
#include <array>

namespace nts
{
    class C4094 : public AComponent
    {
    private:
        std::array<Tristate, 8> _shiftreg;
        std::array<Tristate, 8> _storedreg;
        Tristate _prevclock;

    public:
        C4094() : AComponent(16), _prevclock(Tristate::Undefined) {
            for (int i = 0; i < 8; i++) {
                _shiftreg[i] = Tristate::Undefined;
                _storedreg[i] = Tristate::Undefined;
            }
        }
        ~C4094() = default;

        Tristate compute(std::size_t pin) override;
    };
}

#endif /* !C4094_SHIFT_HPP_ */
