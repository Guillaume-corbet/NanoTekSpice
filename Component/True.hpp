/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** True
*/

#ifndef TRUE_HPP_
#define TRUE_HPP_

#include "../Pin.hpp"
#include "../IComponent.hpp"
#include "../AComponent.hpp"

class True : public AComponent{
    public:
        True(const std::string &name);
        ~True();
        nts::Tristate compute(size_t pin = 1);
        void dump() const;
    protected:
    private:
};

#endif /* !TRUE_HPP_ */
