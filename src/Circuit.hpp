/*
** EPITECH PROJECT, 2025
** B-OOP-400-LYN-4-1-tekspice-spencer.pay
** File description:
** Circuit
*/

#ifndef CIRCUIT_HPP_
#define CIRCUIT_HPP_

#include <map>
#include <string>
#include <vector>
#include <sstream>
#include <memory> // Add for shared_ptr
#include "IComponent.hpp"
#include "SpecialComponents/include.hpp"
#include "ElementaryComponents/include.hpp"
#include "GatesComponents/include.hpp"

class Circuit {
    public:
        Circuit() {
            factories["input"] = []() { return std::make_shared<nts::InputComponent>(); };
            factories["output"] = []() { return std::make_shared<nts::OutputComponent>(); };
            factories["true"] = []() { return std::make_shared<nts::TrueComponent>(); };
            factories["false"] = []() { return std::make_shared<nts::FalseComponent>(); };
            factories["clock"] = []() { return std::make_shared<nts::ClockComponent>(); };

            factories["and"] = []() { return std::make_shared<nts::AndComponent>(); };
            factories["or"] = []() { return std::make_shared<nts::OrComponent>(); };
            factories["xor"] = []() { return std::make_shared<nts::XorComponent>(); };
            factories["not"] = []() { return std::make_shared<nts::NotComponent>(); };

            factories["4001"] = []() { return std::make_shared<nts::C4001>(); };
            factories["4030"] = []() { return std::make_shared<nts::C4030>(); };
            factories["4071"] = []() { return std::make_shared<nts::C4071>(); };
        }

        std::shared_ptr<nts::IComponent>& createComponent(const std::string& name, const std::string& type) {
            auto it = factories.find(type);
            if (it == factories.end())
                throw std::invalid_argument("Unknown component type: " + type);

            if (components.find(name) != components.end())
                throw std::invalid_argument("Component name already exists: " + name);

            components[name] = it->second();
            return components[name];
        }

        std::shared_ptr<nts::IComponent>& getComponent(const std::string& name) {
            auto it = components.find(name);
            if (it == components.end())
                throw std::invalid_argument("Component not found: " + name);
            return it->second;
        }

        void connect(const std::string& name1, const int pin1, const std::string& name2, const int pin2) {
            auto& comp1 = getComponent(name1);
            auto& comp2 = getComponent(name2);
            comp1->setLink(pin1, *comp2, pin2);
            comp2->setLink(pin2, *comp1, pin1);
        }

        void setInputValue(std::string name, int value) {
            auto* inputComponent = dynamic_cast<nts::InputComponent*>(getComponent(name).get());
            if (!inputComponent)
                throw std::invalid_argument("Component is not an input: " + name);
            if (value == 0)
                inputComponent->setValue(nts::Tristate::False);
            else if (value == 1)
                inputComponent->setValue(nts::Tristate::True);
            else
                throw std::invalid_argument("Invalid input value: " + std::to_string(value));
        }

        void simulate() {
            for (auto &command : _buffer) {
                std::istringstream iss(command);
                std::string cmd;
                iss >> cmd;

                std::string name;
                std::string value;
                size_t pos = command.find('=');
                if (pos != std::string::npos) {
                    std::string name = command.substr(0, pos);
                    std::string value = command.substr(pos + 1);
                }
                auto* inputComponent = dynamic_cast<nts::InputComponent*>(getComponent(name).get());
                if (inputComponent)
                    inputComponent->setValue(value == "1" ? nts::Tristate::True : nts::Tristate::False);
                else{
                    auto* clockComponent = dynamic_cast<nts::ClockComponent*>(getComponent(name).get());
                    if (clockComponent)
                        clockComponent->setValue(value == "1" ? nts::Tristate::True : nts::Tristate::False);
                }
            }
            for (auto& pair : components) {
                auto* clockComponent = dynamic_cast<nts::ClockComponent*>(pair.second.get());
                if (clockComponent)
                    clockComponent->simulate();
            }
        }

        void display() {
        }

        void start();

    private:
        std::map<std::string, std::function<std::shared_ptr<nts::IComponent>()>> factories;
        std::map<std::string, std::shared_ptr<nts::IComponent>> components;
        std::vector<std::string> _buffer;
};

#endif /* !CIRCUIT_HPP_ */
