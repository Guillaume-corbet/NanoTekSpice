/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** Pin
*/

#ifndef PIN_HPP_
#define PIN_HPP_

#include "IComponent.hpp"

class Pin {
    public:
        Pin(size_t number);
        ~Pin();
        size_t getNumber() const;
        nts::Tristate getState() const;
        void setState(nts::Tristate state);
        void dump() const;
        Pin *getNext() const;
        Pin *getPrev() const;
        nts::IComponent *getPrevComp() const;
        void setNext(Pin *next);
        void setPrev(Pin *prev);
        void setPrevComp(nts::IComponent *comp);
    protected:
    private:
        size_t _number;
        nts::Tristate _state;
        Pin *_next;
        nts::IComponent *_prevComp;
        Pin *_prev;
};

#endif /* !PIN_HPP_ */
