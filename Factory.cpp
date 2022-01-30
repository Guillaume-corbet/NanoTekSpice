/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** Factory
*/

#include "Factory.hpp"

Factory::Factory(std::vector<std::string> *vecArgs)
{
    this->_vecArgs = vecArgs;
    this->_mapInput["input"] = &Factory::createInput;
    this->_mapInput["output"] = &Factory::createOutput;
    this->_mapInput["4001"] = &Factory::create4001;
    this->_mapInput["true"] = &Factory::createTrue;
    this->_mapInput["false"] = &Factory::createFalse;
    this->_mapInput["clock"] = &Factory::createClock;
    this->_mapInput["4011"] = &Factory::create4011;
    this->_mapInput["4030"] = &Factory::create4030;
    this->_mapInput["4069"] = &Factory::create4069;
    this->_mapInput["4071"] = &Factory::create4071;
    this->_mapInput["4081"] = &Factory::create4081;
}

Factory::~Factory()
{
}

std::unique_ptr<nts::IComponent> Factory::createComponent(const std::string &type, const std::string &value)
{
    auto it = this->_mapInput.find(type);
    if (it != this->_mapInput.end()) {
        return ((this->*it->second)(value));
    } else {
        exit(84);
    }
    return (NULL);
}

std::unique_ptr<nts::IComponent> Factory::create4001(const std::string &value) const noexcept
{
    std::unique_ptr<nts::IComponent> comp(new Component4001(value));

    return (comp);
}

std::unique_ptr<nts::IComponent> Factory::create4011(const std::string &value) const noexcept
{
    std::unique_ptr<nts::IComponent> comp(new Component4011(value));

    return (comp);
}

std::unique_ptr<nts::IComponent> Factory::create4030(const std::string &value) const noexcept
{
    std::unique_ptr<nts::IComponent> comp(new Component4030(value));

    return (comp);
}

std::unique_ptr<nts::IComponent> Factory::create4069(const std::string &value) const noexcept
{
    std::unique_ptr<nts::IComponent> comp(new Component4069(value));

    return (comp);
}

std::unique_ptr<nts::IComponent> Factory::create4071(const std::string &value) const noexcept
{
    std::unique_ptr<nts::IComponent> comp(new Component4071(value));

    return (comp);
}

std::unique_ptr<nts::IComponent> Factory::create4081(const std::string &value) const noexcept
{
    std::unique_ptr<nts::IComponent> comp(new Component4081(value));

    return (comp);
}

std::unique_ptr<nts::IComponent> Factory::createInput(const std::string &value) const noexcept
{
    size_t nb = 0;

    while (nb < this->_vecArgs->size()) {
        if (this->_vecArgs->at(nb).find(value, 0) != std::string::npos) {
            nb = atoi(this->_vecArgs->at(nb).substr(value.size() + 1, 1).c_str());
            break;
        }
        nb = nb + 1;
    }
    std::unique_ptr<nts::IComponent> comp(new Input(value, nb));

    return (comp);
}

std::unique_ptr<nts::IComponent> Factory::createOutput(const std::string &value) const noexcept
{
    std::unique_ptr<nts::IComponent> comp(new Output(value));

    return (comp);
}

std::unique_ptr<nts::IComponent> Factory::createTrue(const std::string &value) const noexcept
{
    std::unique_ptr<nts::IComponent> comp(new True(value));

    return (comp);
}

std::unique_ptr<nts::IComponent> Factory::createFalse(const std::string &value) const noexcept
{
    std::unique_ptr<nts::IComponent> comp(new False(value));

    return (comp);
}

std::unique_ptr<nts::IComponent> Factory::createClock(const std::string &value) const noexcept
{
    size_t nb = 0;

    while (nb < this->_vecArgs->size()) {
        if (this->_vecArgs->at(nb).find(value, 0) != std::string::npos) {
            nb = atoi(this->_vecArgs->at(nb).substr(value.size() + 1, 1).c_str());
            break;
        }
        nb = nb + 1;
    }
    std::unique_ptr<nts::IComponent> comp(new Clock(value, nb));

    return (comp);
}