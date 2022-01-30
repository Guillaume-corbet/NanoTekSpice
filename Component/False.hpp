/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** False
*/

#ifndef FALSE_HPP_
#define FALSE_HPP_

#include "../Pin.hpp"
#include "../IComponent.hpp"
#include "../AComponent.hpp"

class False : public AComponent{
    public:
        False(const std::string &name);
        ~False();
        nts::Tristate compute(size_t pin = 1);
        void dump() const;
    protected:
    private:
};

#endif /* !FALSE_HPP_ */
