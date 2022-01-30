/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** Component4011
*/

#include "Component4011.hpp"

Component4011::Component4011(std::string name):AComponent::AComponent(name)
{
    this->_output->push_back(new Pin(3));
    this->_output->push_back(new Pin(4));
    this->_output->push_back(new Pin(10));
    this->_output->push_back(new Pin(11));
    this->_input->push_back(new Pin(1));
    this->_input->push_back(new Pin(2));
    this->_input->push_back(new Pin(5));
    this->_input->push_back(new Pin(6));
    this->_input->push_back(new Pin(8));
    this->_input->push_back(new Pin(9));
    this->_input->push_back(new Pin(12));
    this->_input->push_back(new Pin(13));
}

Component4011::~Component4011()
{

}

nts::Tristate Component4011::compute(size_t pin)
{
    size_t nb = 0;
    nts::Tristate a;
    nts::Tristate b;
    nts::Tristate result;

    while (this->_output->size() > nb && this->_output->at(nb)->getNumber() != pin)
        nb = nb + 1;
    if (this->_output->size() == nb)
        return (nts::UNDEFINED);
    if (this->_input->at(nb * 2)->getPrev() == NULL)
        std::cout << "nullllll" << std::endl;
    a = this->_input->at(nb * 2)->getPrevComp()->compute(this->_input->at(nb * 2)->getPrev()->getNumber());
    b = this->_input->at(nb * 2 + 1)->getPrevComp()->compute(this->_input->at(nb * 2 + 1)->getPrev()->getNumber());
    if (a == nts::TRUE && b == nts::TRUE)
        result = nts::FALSE;
    else
        result = nts::TRUE;
    this->_output->at(nb)->setState(result);
    return (result);
}

void Component4011::dump() const
{
    size_t i = 0;
    std::cout << "Component4011" << std::endl;
    std::cout << "\tInput" << std::endl;
    while (i < this->_input->size()) {
        this->_input->at(i)->dump();
        i = i + 1;
    }
    i = 0;
    std::cout << "\tOutput" << std::endl;
    while (i < this->_output->size()) {
        this->_output->at(i)->dump();
        i = i + 1;
    }
}