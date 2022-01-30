/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** Circuit
*/

#include "Circuit.hpp"

Circuit::Circuit()
{
    this->_component = new std::vector<nts::IComponent *>;
    this->_output = new std::vector<nts::IComponent *>;
}

Circuit::~Circuit()
{
    delete(_component);
}

std::vector<nts::IComponent *> *Circuit::getComponent() const
{
    return (this->_component);
}

std::vector<nts::IComponent *> *Circuit::getOutput() const
{
    return (this->_output);
}

nts::IComponent *Circuit::getOneComponent(size_t pos) const
{
    return (this->_component->at(pos));
}

nts::IComponent *Circuit::getOneComponentByName(std::string name) const
{
    size_t i = 0;

    while (i < this->_component->size()) {
        if (dynamic_cast<AComponent *>(this->_component->at(i))->getName() == name) {
            return (this->_component->at(i));
        }
        i = i + 1;
    }
    i = 0;
    while (i < this->_output->size()) {
        if (dynamic_cast<AComponent *>(this->_output->at(i))->getName() == name) {
            return (this->_output->at(i));
        }
        i = i + 1;
    }
    return (NULL);
}

void Circuit::addOneComponent(nts::IComponent *component)
{
    this->_component->push_back(component);
}

void Circuit::addOneOutput(nts::IComponent *component)
{
    this->_output->push_back(component);
}