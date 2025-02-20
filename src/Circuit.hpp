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
#include "IComponent.hpp"
#include "SpecialComponents/include.hpp"
#include "ElementaryComponents/include.hpp"

class Circuit {
    public:
        Circuit() {
            factories["input"] = []() { return std::make_unique<nts::InputComponent>(); };
            factories["output"] = []() { return std::make_unique<nts::OutputComponent>(); };
            factories["true"] = []() { return std::make_unique<nts::TrueComponent>(); };
            factories["false"] = []() { return std::make_unique<nts::FalseComponent>(); };
            // factories["clock"] = []() { return std::make_unique<nts::ClockComponent>(); };

            factories["and"] = []() { return std::make_unique<nts::AndComponent>(); };
            factories["or"] = []() { return std::make_unique<nts::OrComponent>(); };
            factories["xor"] = []() { return std::make_unique<nts::XorComponent>(); };
            factories["not"] = []() { return std::make_unique<nts::NotComponent>(); };
        }

        std::unique_ptr<nts::IComponent>& createComponent(const std::string& name, const std::string& type) {
            auto it = factories.find(type);
            if (it == factories.end())
                throw std::invalid_argument("Unknown component type: " + type);

            if (components.find(name) != components.end())
                throw std::invalid_argument("Component name already exists: " + name);

            components[name] = it->second();
            return components[name];
        }

        std::unique_ptr<nts::IComponent>& getComponent(const std::string& name) {
            auto it = components.find(name);
            if (it == components.end())
                throw std::invalid_argument("Component not found: " + name);
            return it->second;
        }

        void connect(const std::string& name1, const int pin1, const std::string& name2, const int pin2) {
            auto& comp1 = getComponent(name1);
            auto& comp2 = getComponent(name2);
            comp1->setLink(pin1, *comp2, pin2);
        }

        void simulate() {
        }

        void display() {
        }

        void setInputValue(std::string, int value) {
        }

    private:
        std::map<std::string, std::function<std::unique_ptr<nts::IComponent>()>> factories;
        std::map<std::string, std::unique_ptr<nts::IComponent>> components;
};

#endif /* !CIRCUIT_HPP_ */
