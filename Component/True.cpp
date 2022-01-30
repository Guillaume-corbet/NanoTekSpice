/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** True
*/

#include "True.hpp"

True::True(const std::string &name):AComponent::AComponent(name)
{
    this->_output->push_back(new Pin(1));
    this->_output->at(0)->setState(nts::TRUE);
}

True::~True()
{
}

nts::Tristate True::compute(size_t pin)
{
    if (this->_output->at(0)->getNumber() == pin)
        return (this->_output->at(0)->getState());
    return (nts::UNDEFINED);
}

void True::dump() const
{
    std::cout << "True" << std::endl;
    this->_output->at(0)->dump();
}