#include "Square.h"

int Square::getNumber() const {
    return number;
}

void Square::addNumber() {      //multiply number by 2 as it was added with another and set added true
    Square::number *= 2;
    Square::added = true;
}

Square::Square(int number) : number(number) {}      //constructor with given number

bool Square::isEmpty() {            //if number equals 1 it is an empty cell
    return number == 1;
}

bool Square::isAdded() const {          //return if number was added in this iteration
    return added;
}

void Square::setNumber(int num) {       //setter
    Square::number = num;
}

void Square::setNotAdded() {            //refresh added values to false
    Square::added = false;
}

