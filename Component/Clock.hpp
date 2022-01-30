/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** Clock
*/

#ifndef CLOCK_HPP_
#define CLOCK_HPP_

#include "../Pin.hpp"
#include "../IComponent.hpp"
#include "../AComponent.hpp"

class Clock : public AComponent {
    public:
        Clock(const std::string &name, size_t state);
        ~Clock();
            nts::Tristate compute(size_t pin = 1);
            void dump() const;
            void setState(size_t state);
    protected:
    private:
};
#endif /* !CLOCK_HPP_ */
