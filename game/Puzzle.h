#ifndef GAME_PUZZLE_H
#define GAME_PUZZLE_H


#include "Square.h"
#include <optional>
#include <vector>

class Puzzle {
private:
    int n = 4;
    int score = 0;
    bool saved = false;
    std::vector<std::vector<Square>> square;
    std::vector<std::vector<Square>> savedSquare;
public:

    bool add();

    void initalize();

    bool isSaved() const;

    void setSaved(bool value);

    explicit Puzzle(int n);

    void restart();

    bool moveUp();

    bool moveDown();

    void save();

    void load();

    bool moveLeft();

    bool moveRight();

    void addScore(int points);

    int getScore() const;

    void setNotAdded();

    void print();

    bool endGame();

};


#endif //GAME_PUZZLE_H
