/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** Pin
*/

#include "Pin.hpp"

Pin::Pin(size_t number)
{
    _number = number;
    _state = nts::Tristate::UNDEFINED;
}

Pin::~Pin()
{

}

size_t Pin::getNumber() const
{
    return (this->_number);
}

nts::Tristate Pin::getState() const
{
    return (this->_state);
}

void Pin::setState(nts::Tristate state)
{
    this->_state = state;
}

void Pin::dump() const
{
    if (this->_state == nts::UNDEFINED)
        std::cout << "\t\tPin " << this->_number << ": U" << std::endl;
    else
        std::cout << "\t\tPin " << this->_number << ": " << this->_state << std::endl;
}

Pin *Pin::getNext() const
{
    return (this->_next);
}

Pin *Pin::getPrev() const
{
    return (this->_prev);
}

void Pin::setNext(Pin *next)
{
    this->_next = next;
}

void Pin::setPrev(Pin *prev)
{
    this->_prev = prev;
}

nts::IComponent *Pin::getPrevComp() const
{
    return (this->_prevComp);
}

void Pin::setPrevComp(nts::IComponent *comp)
{
    this->_prevComp = comp;
}