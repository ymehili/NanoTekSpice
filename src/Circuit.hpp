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
#include <memory>
#include <functional>
#include <iostream>
#include "IComponent.hpp"
#include "SpecialComponents/include.hpp"
#include "ElementaryComponents/include.hpp"
#include "GatesComponents/include.hpp"
#include "AdvancedComponents/include.hpp"

class Circuit {
    public:
        Circuit(): _tick(0) {
            factories["input"] = []() { return std::make_shared<nts::InputComponent>(); };
            factories["output"] = []() { return std::make_shared<nts::OutputComponent>(); };
            factories["true"] = []() { return std::make_shared<nts::TrueComponent>(); };
            factories["false"] = []() { return std::make_shared<nts::FalseComponent>(); };
            factories["clock"] = []() { return std::make_shared<nts::ClockComponent>(); };
            factories["logger"] = []() { return std::make_shared<nts::LoggerComponent>(); };

            factories["and"] = []() { return std::make_shared<nts::AndComponent>(); };
            factories["or"] = []() { return std::make_shared<nts::OrComponent>(); };
            factories["xor"] = []() { return std::make_shared<nts::XorComponent>(); };
            factories["not"] = []() { return std::make_shared<nts::NotComponent>(); };

            factories["4001"] = []() { return std::make_shared<nts::C4001>(); };
            factories["4011"] = []() { return std::make_shared<nts::C4011>(); };
            factories["4030"] = []() { return std::make_shared<nts::C4030>(); };
            factories["4069"] = []() { return std::make_shared<nts::C4069>(); };
            factories["4071"] = []() { return std::make_shared<nts::C4071>(); };
            factories["4081"] = []() { return std::make_shared<nts::C4081>(); };

            factories["4008"] = []() { return std::make_shared<nts::C4008>(); };
            factories["4017"] = []() { return std::make_shared<nts::C4017>(); };
            factories["4094"] = []() { return std::make_shared<nts::C4094>(); };
            factories["4514"] = []() { return std::make_shared<nts::C4514>(); };
            factories["4040"] = []() { return std::make_shared<nts::C4040>(); };
        }

        std::shared_ptr<nts::IComponent>& createComponent(const std::string& type, const std::string& name) {
            auto it = factories.find(type);
            if (it == factories.end())
                throw std::runtime_error("Unknown component type: " + type);

            if (components.find(name) != components.end())
                throw std::runtime_error("Component name already exists: " + name);

            components[name] = it->second();
            return components[name];
        }

        std::shared_ptr<nts::IComponent>& getComponent(const std::string& name) {
            auto it = components.find(name);
            if (it == components.end())
                throw std::runtime_error("Component not found: " + name);
            return it->second;
        }

        void connect(const std::string& name1, const int pin1, const std::string& name2, const int pin2) {
            auto& comp1 = getComponent(name1);
            auto& comp2 = getComponent(name2);

            if (!comp1 || !comp2)
                throw std::runtime_error("Cannot connect: component not found");

            try {
                comp1->setLink(pin1, *comp2, pin2);
                comp2->setLink(pin2, *comp1, pin1);
            } catch (const std::exception& e) {
                throw std::runtime_error(std::string("Connection error: ") + e.what());
            }
        }

        void setInputValue(std::string name, int value) {
            auto* inputComponent = dynamic_cast<nts::InputComponent*>(getComponent(name).get());
            if (!inputComponent)
                return;
            if (value == 0)
                inputComponent->setValue(nts::Tristate::False);
            else if (value == 1)
                inputComponent->setValue(nts::Tristate::True);
        }

        void simulate() {
            try {
                for (auto& pair : components) {
                    auto* clockComponent = dynamic_cast<nts::ClockComponent*>(pair.second.get());
                    if (clockComponent)
                        clockComponent->simulate();
                    auto* loggerComponent = dynamic_cast<nts::LoggerComponent*>(pair.second.get());
                        if (loggerComponent)
                            loggerComponent->simulate();
                }
                for (auto &command : _buffer) {
                    std::istringstream iss(command);
                    std::string cmd;
                    iss >> cmd;

                    std::string name;
                    std::string value;
                    size_t pos = command.find('=');
                    if (pos != std::string::npos) {
                        name = command.substr(0, pos);
                        value = command.substr(pos + 1);
                    }

                    if (name.empty() || value.empty()) {
                        throw std::runtime_error("Invalid command format: " + command);
                    }

                    auto* inputComponent = dynamic_cast<nts::InputComponent*>(getComponent(name).get());
                    if (inputComponent) {
                        if (value != "0" && value != "1" && value != "U") {
                            throw std::runtime_error("Invalid value for input: " + value);
                        }
                        inputComponent->setValue(value == "1" ? nts::Tristate::True : value == "0" ? nts::Tristate::False : nts::Tristate::Undefined);
                    } else {
                        auto* clockComponent = dynamic_cast<nts::ClockComponent*>(getComponent(name).get());
                        if (clockComponent) {
                            if (value != "0" && value != "1" && value != "U") {
                                throw std::runtime_error("Invalid value for clock: " + value);
                            }
                            clockComponent->setValue(value == "1" ? nts::Tristate::True : value == "0" ? nts::Tristate::False : nts::Tristate::Undefined);
                        } else {
                            throw std::runtime_error("Component not found or not an input/clock: " + name);
                        }
                    }
                }
                _buffer.clear();
                _tick++;
            } catch (const std::exception& e) {
                throw std::runtime_error(std::string("Simulation error: ") + e.what());
            }
        }

        void display() {
            try {
                std::cout << "tick: " << _tick << std::endl;
                std::cout << "input(s):" << std::endl;
                for (const auto& pair : components) {
                    auto* inputComponent = dynamic_cast<nts::InputComponent*>(pair.second.get());
                    if (inputComponent) {
                        std::cout << "  " << pair.first << ": ";
                        if (inputComponent->compute() == nts::Tristate::True)
                            std::cout << "1";
                        else if (inputComponent->compute() == nts::Tristate::False)
                            std::cout << "0";
                        else
                            std::cout << "U";
                        std::cout << std::endl;
                    }
                    auto *clockComponent = dynamic_cast<nts::ClockComponent*>(pair.second.get());
                    if (clockComponent) {
                        std::cout << "  " << pair.first << ": ";
                        if (clockComponent->compute() == nts::Tristate::True)
                            std::cout << "1";
                        else if (clockComponent->compute() == nts::Tristate::False)
                            std::cout << "0";
                        else
                            std::cout << "U";
                        std::cout << std::endl;
                    }
                }
                std::cout << "output(s):" << std::endl;
                for (const auto& pair : components) {
                    auto* outputComponent = dynamic_cast<nts::OutputComponent*>(pair.second.get());
                    if (outputComponent) {
                        nts::Tristate value = pair.second->compute(1);
                        std::cout << "  " << pair.first << ": ";
                        if (value == nts::Tristate::True)
                            std::cout << "1";
                        else if (value == nts::Tristate::False)
                            std::cout << "0";
                        else
                            std::cout << "U";
                        std::cout << std::endl;
                    }
                    // auto* loggerComponent = dynamic_cast<nts::LoggerComponent*>(pair.second.get());
                    // if (loggerComponent){
                    //     pair.second->compute(1);
                    // }
                }
            } catch (const std::exception& e) {
                throw std::runtime_error(std::string("Display error: ") + e.what());
            }
        }

        void start();

    private:
        std::map<std::string, std::function<std::shared_ptr<nts::IComponent>()>> factories;
        std::map<std::string, std::shared_ptr<nts::IComponent>> components;
        std::vector<std::string> _buffer;
        std::size_t _tick;
};

#endif /* !CIRCUIT_HPP_ */
