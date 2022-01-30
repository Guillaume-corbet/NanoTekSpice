/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** Component4030
*/

#ifndef COMPONENT4030_HPP_
#define COMPONENT4030_HPP_

#include <vector>
#include "../Pin.hpp"
#include "../AComponent.hpp"

class Component4030 : public AComponent {
    public:
        Component4030(std::string name);
        ~Component4030();
        nts::Tristate compute(size_t pin = 1);
        void dump() const;
    protected:
    private:
};
#endif /* !COMPONENT4030_HPP_ */
