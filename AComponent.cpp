/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** AComponent
*/

#include "AComponent.hpp"

AComponent::AComponent(const std::string &name)
{
    this->_name = name;
    this->_input = new std::vector<Pin *>;
    this->_output = new std::vector<Pin *>;
}

AComponent::~AComponent()
{
}

nts::Tristate AComponent::compute(size_t pin)
{
    return (nts::TRUE);
}

void AComponent::setLink(size_t pin, nts::IComponent &other, size_t otherPin)
{
    size_t i = 0;
    size_t j = 0;
    AComponent *comp = dynamic_cast<AComponent *>(&other);

    while (i < this->_output->size()) {
        if (this->_output->at(i)->getNumber() == pin) {
            while (j < comp->_input->size()) {
                if (comp->_input->at(j)->getNumber() == otherPin) {
                    this->_output->at(i)->setNext(comp->getPinInput(otherPin));
                    comp->getPinInput(otherPin)->setPrev(this->getPinOutput(pin));
                    comp->getPinInput(otherPin)->setPrevComp(this);
                    return;
                }
                j = j + 1;
            }
        }
        i = i + 1;
    }
    i = 0;
    j = 0;
    while (i < comp->_output->size()) {
        if (comp->_output->at(i)->getNumber() == otherPin) {
            while (j < this->_input->size()) {
                if (this->_input->at(j)->getNumber() == pin) {
                    comp->_output->at(i)->setNext(this->getPinInput(pin));
                    this->getPinInput(pin)->setPrev(comp->getPinOutput(otherPin));
                    this->getPinInput(pin)->setPrevComp(comp);
                    return;
                }
                j = j + 1;
            }
        }
        i = i + 1;
    }
}

void AComponent::dump() const
{
}

Pin *AComponent::getPinInput(size_t pin) const
{
    size_t i = 0;

    while (this->_input->size() > i) {
        if (this->_input->at(i)->getNumber() == pin)
            return (this->_input->at(i));
        i = i + 1;
    }
    return (NULL);
}

void AComponent::changeStatePinInput(nts::Tristate state, size_t pin)
{
    size_t i = 0;

    while (this->_input->size() > i) {
        if (this->_input->at(i)->getNumber() == pin)
            this->_input->at(i)->setState(state);
        i = i + 1;
    }
}

void AComponent::changeStatePinOutput(nts::Tristate state, size_t pin)
{
    size_t i = 0;

    while (this->_output->size() > i) {
        if (this->_output->at(i)->getNumber() == pin)
            this->_output->at(i)->setState(state);
        i = i + 1;
    }
}

Pin *AComponent::getPinOutput(size_t pin) const
{
    size_t i = 0;

    while (this->_output->size() > i) {
        if (this->_output->at(i)->getNumber() == pin)
            return (this->_output->at(i));
        i = i + 1;
    }
    return (NULL);
}

void AComponent::setName(std::string name)
{
    this->_name = name;
}

std::string AComponent::getName() const
{
    return (this->_name);
}