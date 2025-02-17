/*
** EPITECH PROJECT, 2025
** Untitled (Workspace)
** File description:
** InputComponent
*/

#ifndef INPUTCOMPONENT_HPP_
#define INPUTCOMPONENT_HPP_

#include "AComponent.hpp"

namespace nts {

class InputComponent : public AComponent {
public:
    InputComponent(const std::string& name); // Constructor

    Tristate compute(pin_num_t pin = 1) override; // Compute method
    void simulate(std::size_t tick) override; // Simulate method

    void setState(Tristate newState); // Method to set input state

private:
    Tristate _state; // Store the current state (True, False, Undefined)
};

} // namespace nts

#endif /* !INPUTCOMPONENT_HPP_ */
