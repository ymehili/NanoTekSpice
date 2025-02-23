/*
** EPITECH PROJECT, 2025
** Untitled (Workspace)
** File description:
** ClockComponent
*/

#ifndef CLOCKCOMPONENT_HPP_
#define CLOCKCOMPONENT_HPP_

namespace nts
{
    class ClockComponent : public nts::AComponent
    {
    private:
        Tristate _value;

    public:
        ClockComponent() : AComponent(1), _value(Tristate::Undefined) {}
        ~ClockComponent() = default;

        void setValue(Tristate value)
        {
            _value = value;
        }

        void simulate(std::size_t tick = 0)
        {
            (void)tick;
            if (_value != Tristate::Undefined)
                _value = (_value == Tristate::True) ? Tristate::False : Tristate::True;
        }

        Tristate compute(std::size_t pin = 1)
        {
            if (pin != 1)
                return Tristate::Undefined;
            return _value;
        }
    };
}

#endif /* !CLOCKCOMPONENT_HPP_ */