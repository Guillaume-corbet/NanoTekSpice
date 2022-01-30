/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** Factory
*/

#ifndef FACTORY_HPP_
#define FACTORY_HPP_

#include <memory>
#include <map>
#include "Component/Component4001.hpp"
#include "Component/Component4011.hpp"
#include "Component/Component4030.hpp"
#include "Component/Component4069.hpp"
#include "Component/Component4071.hpp"
#include "Component/Component4081.hpp"
#include "Component/Input.hpp"
#include "Component/Output.hpp"
#include "Component/True.hpp"
#include "Component/False.hpp"
#include "Component/Clock.hpp"

class Factory {
    public:
        Factory(std::vector<std::string> *vecArgs);
        ~Factory();
        std::unique_ptr<nts::IComponent> createComponent(const std::string &type, const std::string &value);
    protected:
    private:
        std::unique_ptr<nts::IComponent> createInput(const std::string &value) const noexcept;
        std::unique_ptr<nts::IComponent> createOutput(const std::string &value) const noexcept;
        std::unique_ptr<nts::IComponent> create4001(const std::string &value) const noexcept;
        std::unique_ptr<nts::IComponent> createTrue(const std::string &value) const noexcept;
        std::unique_ptr<nts::IComponent> createFalse(const std::string &value) const noexcept;
        std::unique_ptr<nts::IComponent> createClock(const std::string &value) const noexcept;
        std::unique_ptr<nts::IComponent> create4011(const std::string &value) const noexcept;
        std::unique_ptr<nts::IComponent> create4030(const std::string &value) const noexcept;
        std::unique_ptr<nts::IComponent> create4071(const std::string &value) const noexcept;
        std::unique_ptr<nts::IComponent> create4081(const std::string &value) const noexcept;
        std::unique_ptr<nts::IComponent> create4069(const std::string &value) const noexcept;
        std::vector<std::string> *_vecArgs;
        std::map<std::string, std::unique_ptr<nts::IComponent> (Factory::*)(const std::string &value) const> _mapInput;
};

#endif /* !FACTORY_HPP_ */