/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** Clock
*/

#include "Clock.hpp"

Clock::Clock(const std::string &name, size_t state):AComponent::AComponent(name)
{
    this->_output->push_back(new Pin(1));
    if (state == 0) {
        this->_output->at(0)->setState(nts::FALSE);
    } else if (state == 1) {
        this->_output->at(0)->setState(nts::TRUE);
    }
}

Clock::~Clock()
{
}

nts::Tristate Clock::compute(size_t pin)
{
    nts::Tristate state;

    if (this->_output->at(0)->getNumber() == pin) {
        state = this->_output->at(0)->getState();
        if (state == nts::TRUE)
            this->_output->at(0)->setState(nts::FALSE);
        else if (state == nts::FALSE)
            this->_output->at(0)->setState(nts::TRUE);
        return (state);
    }
    return (nts::UNDEFINED);
}

void Clock::dump() const
{
    std::cout << "Clock" << std::endl;
    this->_output->at(0)->dump();
}

void Clock::setState(size_t state)
{
    if (state == 0)
        this->_output->at(0)->setState(nts::FALSE);
    else if (state == 1)
        this->_output->at(0)->setState(nts::TRUE);
}