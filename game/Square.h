#ifndef GAME_SQUARE_H
#define GAME_SQUARE_H


class Square {
private:
    int number;
    bool added = false;
public:
    int getNumber() const;

    void addNumber();

    void setNumber(int num);

    void setNotAdded();

    bool isAdded() const;

    bool isEmpty();

    Square(int number);

};

#endif //GAME_SQUARE_H
