/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** Output
*/

#include "Output.hpp"

Output::Output(const std::string &name):AComponent::AComponent(name)
{
    this->_input->push_back(new Pin(1));
}

Output::~Output()
{
}

nts::Tristate Output::compute(size_t pin)
{
    if (this->_input->at(0)->getPrev() != NULL) {
        this->_input->at(0)->setState(this->_input->at(0)->getPrevComp()->compute(this->_input->at(0)->getPrev()->getNumber()));
        return (this->_input->at(0)->getState());
    }
    std::cout << "undefined" << std::endl;
    return (nts::UNDEFINED);
}

void Output::dump() const
{
    std::cout << "Output" << std::endl;
    this->_input->at(0)->dump();
}