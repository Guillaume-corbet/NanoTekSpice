/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** Component4011
*/

#ifndef COMPONENT4011_HPP_
#define COMPONENT4011_HPP_

#include <vector>
#include "../Pin.hpp"
#include "../AComponent.hpp"

class Component4011 : public AComponent {
    public:
        Component4011(std::string name);
        ~Component4011();
        nts::Tristate compute(size_t pin = 1);
        void dump() const;
    protected:
    private:
};

#endif /* !COMPONENT4011_HPP_ */
