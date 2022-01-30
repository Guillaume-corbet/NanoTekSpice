/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** Circuit
*/

#ifndef CIRCUIT_HPP_
#define CIRCUIT_HPP_

#include <vector>
#include "IComponent.hpp"
#include "AComponent.hpp"

class Circuit {
    public:
        Circuit();
        ~Circuit();
        std::vector<nts::IComponent *> *getComponent() const;
        std::vector<nts::IComponent *> *getOutput()const;
        nts::IComponent *getOneComponent(size_t pos) const;
        nts::IComponent *getOneComponentByName(std::string name) const;
        void addOneComponent(nts::IComponent *component);
        void addOneOutput(nts::IComponent *component);
    protected:
    private:
        std::vector<nts::IComponent *> *_component;
        std::vector<nts::IComponent *> *_output;
};

#endif /* !CIRCUIT_HPP_ */