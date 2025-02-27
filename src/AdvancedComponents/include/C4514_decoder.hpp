/*
** EPITECH PROJECT, 2025
** B-OOP-400-LYN-4-1-tekspice-spencer.pay
** File description:
** C4514_decoder
*/

#ifndef C4514_DECODER_HPP_
#define C4514_DECODER_HPP_

#include "../../AComponent.hpp"

namespace nts
{
    class C4514 : public AComponent
    {
    private:
        int _latchval;
        bool _latch;

    public:
        C4514() : AComponent(24), _latchval(0), _latch(false) {}
        ~C4514() = default;

        Tristate compute(std::size_t pin) override;
    };
}

#endif /* !C4514_DECODER_HPP_ */