/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** Component4081
*/

#ifndef COMPONENT4081_HPP_
#define COMPONENT4081_HPP_

#include <vector>
#include "../Pin.hpp"
#include "../AComponent.hpp"

class Component4081 : public AComponent {
    public:
        Component4081(std::string name);
        ~Component4081();
        nts::Tristate compute(size_t pin = 1);
        void dump() const;
    protected:
    private:
};

#endif /* !COMPONENT4081_HPP_ */
