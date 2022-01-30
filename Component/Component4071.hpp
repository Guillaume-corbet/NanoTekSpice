/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** Component4071
*/

#ifndef COMPONENT4071_HPP_
#define COMPONENT4071_HPP_

#include <vector>
#include "../Pin.hpp"
#include "../AComponent.hpp"

class Component4071 : public AComponent {
    public:
        Component4071(std::string name);
        ~Component4071();
        nts::Tristate compute(size_t pin = 1);
        void dump() const;
    protected:
    private:
};

#endif /* !COMPONENT4071_HPP_ */
