/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** Component4069
*/

#ifndef COMPONENT4069_HPP_
#define COMPONENT4069_HPP_

#include <vector>
#include "../Pin.hpp"
#include "../AComponent.hpp"

class Component4069 : public AComponent {
    public:
        Component4069(std::string name);
        ~Component4069();
        nts::Tristate compute(size_t pin = 1);
        void dump() const;
    protected:
    private:
};

#endif /* !COMPONENT4069_HPP_ */
