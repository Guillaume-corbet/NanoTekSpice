/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** False
*/

#include "False.hpp"

False::False(const std::string &name):AComponent::AComponent(name)
{
    this->_output->push_back(new Pin(1));
    this->_output->at(0)->setState(nts::FALSE);
}

False::~False()
{
}

nts::Tristate False::compute(size_t pin)
{
    if (this->_output->at(0)->getNumber() == pin)
        return (this->_output->at(0)->getState());
    return (nts::UNDEFINED);
}

void False::dump() const
{
    std::cout << "False" << std::endl;
    this->_output->at(0)->dump();
}