#include <iostream>
#include "src/SpecialComponents/InputComponent.hpp"
#include "src/SpecialComponents/OutputComponent.hpp"
#include "src/SpecialComponents/TrueComponent.hpp"
#include "src/SpecialComponents/FalseComponent.hpp"

int main() {
    nts::InputComponent input;
    nts::OutputComponent output;
    nts::TrueComponent trueComp;
    nts::FalseComponent falseComp;

    // Test TrueComponent
    std::cout << "TrueComponent: " << (trueComp.compute() == nts::Tristate::TRUE ? "TRUE" : "FALSE") << std::endl;

    // Test FalseComponent
    std::cout << "FalseComponent: " << (falseComp.compute() == nts::Tristate::FALSE ? "FALSE" : "TRUE") << std::endl;

    // Test InputComponent
    input.setValue(nts::Tristate::TRUE);
    std::cout << "InputComponent (set to TRUE): " << (input.compute() == nts::Tristate::TRUE ? "TRUE" : "FALSE") << std::endl;

    input.setValue(nts::Tristate::FALSE);
    std::cout << "InputComponent (set to FALSE): " << (input.compute() == nts::Tristate::FALSE ? "FALSE" : "TRUE") << std::endl;

    // Test OutputComponent
    output.setLink(0, input);
    input.setValue(nts::Tristate::TRUE);
    std::cout << "OutputComponent (linked to InputComponent set to TRUE): " << (output.compute() == nts::Tristate::TRUE ? "TRUE" : "FALSE") << std::endl;

    input.setValue(nts::Tristate::FALSE);
    std::cout << "OutputComponent (linked to InputComponent set to FALSE): " << (output.compute() == nts::Tristate::FALSE ? "FALSE" : "TRUE") << std::endl;

    return 0;
}