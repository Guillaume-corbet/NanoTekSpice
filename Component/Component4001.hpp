/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** Component4001
*/

#ifndef COMPONENT4001_HPP_
#define COMPONENT4001_HPP_

#include <vector>
#include "../Pin.hpp"
#include "../AComponent.hpp"

class Component4001 : public AComponent {
    public:
        Component4001(std::string name);
        ~Component4001();
        nts::Tristate compute(size_t pin = 1);
        void dump() const;
    protected:
    private:
};

#endif /* !COMPONENT4001_HPP_ */