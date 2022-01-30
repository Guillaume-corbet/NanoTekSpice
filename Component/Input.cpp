/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** Input
*/

#include "Input.hpp"

Input::Input(const std::string &name, size_t state):AComponent::AComponent(name)
{
    this->_output->push_back(new Pin(1));
    if (state == 0) {
        this->_output->at(0)->setState(nts::FALSE);
    } else if (state == 1) {
        this->_output->at(0)->setState(nts::TRUE);
    }
}

Input::~Input()
{
}

nts::Tristate Input::compute(size_t pin)
{
    if (this->_output->at(0)->getNumber() == pin)
        return (this->_output->at(0)->getState());
    return (nts::UNDEFINED);
}

void Input::dump() const
{
    std::cout << "Input" << std::endl;
    this->_output->at(0)->dump();
}

void Input::setState(size_t state)
{
    if (state == 0)
        this->_output->at(0)->setState(nts::FALSE);
    else if (state == 1)
        this->_output->at(0)->setState(nts::TRUE);
}