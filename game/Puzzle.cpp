#include "Puzzle.h"
#include <ctime>
#include <cstdlib>
#include <cstdio>

bool Puzzle::moveUp() {
    bool moved = false;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (square[i][j].isEmpty())
                continue;
            for (int k = i - 1; k >= 0; k--) {
                if (k == 0 && square[k][j].isEmpty()) {
                    square[k][j].setNumber(square[i][j].getNumber());
                    square[i][j].setNumber(1);
                    moved = true;
                } else if (!square[k][j].isEmpty() && square[k][j].getNumber() != square[i][j].getNumber()) {
                    break;
                } else if (k > 0 && square[k][j].isEmpty() && square[k - 1][j].isEmpty())
                    continue;
                else if (k > 0 && square[k][j].isEmpty() && square[k - 1][j].getNumber() == square[i][j].getNumber() &&
                         !square[k - 1][j].isAdded()) {
                    square[k - 1][j].addNumber();
                    square[i][j].setNumber(1);
                    addScore(square[k - 1][j].getNumber());
                    moved = true;
                    break;
                } else if (k > 0 && square[k][j].isEmpty() && !square[k - 1][j].isEmpty()) {
                    square[k][j].setNumber(square[i][j].getNumber());
                    square[i][j].setNumber(1);
                    moved = true;
                } else if (square[k][j].isAdded())
                    break;
                else if (square[k][j].getNumber() == square[i][j].getNumber()) {
                    square[k][j].addNumber();
                    square[i][j].setNumber(1);
                    addScore(square[k][j].getNumber());
                    moved = true;
                    break;
                }
            }
        }
    }
    return moved;
}

bool Puzzle::moveDown() {
    bool moved = false;
    for (int i = n - 2; i >= 0; i--) {
        for (int j = 0; j < n; j++) {
            if (square[i][j].isEmpty())
                continue;
            for (int k = i + 1; k < n; k++) {
                if (k == n - 1 && square[k][j].isEmpty()) {
                    square[k][j].setNumber(square[i][j].getNumber());
                    square[i][j].setNumber(1);
                    moved = true;
                } else if (!square[k][j].isEmpty() && square[k][j].getNumber() != square[i][j].getNumber()) {
                    break;
                } else if (k < n - 1 && square[k][j].isEmpty() && square[k + 1][j].isEmpty())
                    continue;
                else if (k < n - 1 && square[k][j].isEmpty() &&
                         square[k + 1][j].getNumber() == square[i][j].getNumber() &&
                         !square[k + 1][j].isAdded()) {
                    square[k + 1][j].addNumber();
                    square[i][j].setNumber(1);
                    addScore(square[k + 1][j].getNumber());
                    moved = true;
                    break;
                } else if (k < n - 1 && square[k][j].isEmpty() && !square[k + 1][j].isEmpty()) {
                    square[k][j].setNumber(square[i][j].getNumber());
                    square[i][j].setNumber(1);
                    moved = true;
                } else if (square[k][j].isAdded())
                    break;
                else if (square[k][j].getNumber() == square[i][j].getNumber()) {
                    square[k][j].addNumber();
                    square[i][j].setNumber(1);
                    addScore(square[k][j].getNumber());
                    moved = true;
                    break;
                }
            }
        }
    }
    return moved;
}

bool Puzzle::moveLeft() {
    bool moved = false;
    for (int i = 0; i < n; i++) {
        for (int j = 1; j < n; j++) {
            if (square[i][j].isEmpty())
                continue;
            for (int k = j - 1; k >= 0; k--) {
                if (k == 0 && square[i][k].isEmpty()) {
                    square[i][k].setNumber(square[i][j].getNumber());
                    square[i][j].setNumber(1);
                    moved = true;
                } else if (!square[i][k].isEmpty() && square[i][k].getNumber() != square[i][j].getNumber()) {
                    break;
                } else if (k > 0 && square[i][k].isEmpty() && square[i][k - 1].isEmpty())
                    continue;
                else if (k > 0 && square[i][k].isEmpty() && square[i][k - 1].getNumber() == square[i][j].getNumber() &&
                         !square[i][k - 1].isAdded()) {
                    square[i][k - 1].addNumber();
                    square[i][j].setNumber(1);
                    addScore(square[i][k - 1].getNumber());
                    moved = true;
                    break;
                } else if (k > 0 && square[i][k].isEmpty() && !square[i][k - 1].isEmpty()) {
                    square[i][k].setNumber(square[i][j].getNumber());
                    square[i][j].setNumber(1);
                    moved = true;
                } else if (square[i][k].isAdded())
                    break;
                else if (square[i][k].getNumber() == square[i][j].getNumber()) {
                    square[i][k].addNumber();
                    square[i][j].setNumber(1);
                    addScore(square[i][k].getNumber());
                    moved = true;
                    break;
                }
            }
        }
    }
    return moved;
}

bool Puzzle::moveRight() {
    bool moved = false;
    for (int i = 0; i < n; i++) {
        for (int j = n - 2; j >= 0; j--) {
            if (square[i][j].isEmpty())
                continue;
            for (int k = j + 1; k < n; k++) {
                if (k == n - 1 && square[i][k].isEmpty()) {
                    square[i][k].setNumber(square[i][j].getNumber());
                    square[i][j].setNumber(1);
                    moved = true;
                } else if (!square[i][k].isEmpty() && square[i][k].getNumber() != square[i][j].getNumber()) {
                    break;
                } else if (k < n - 1 && square[i][k].isEmpty() && square[i][k + 1].isEmpty())
                    continue;
                else if (k < n - 1 && square[i][k].isEmpty() &&
                         square[i][k + 1].getNumber() == square[i][j].getNumber() &&
                         !square[i][k + 1].isAdded()) {
                    square[i][k + 1].addNumber();
                    square[i][j].setNumber(1);
                    addScore(square[i][k + 1].getNumber());
                    moved = true;
                    break;
                } else if (k < n - 1 && square[i][k].isEmpty() && !square[i][k + 1].isEmpty()) {
                    square[i][k].setNumber(square[i][j].getNumber());
                    square[i][j].setNumber(1);
                    moved = true;
                } else if (square[i][k].isAdded())
                    break;
                else if (square[i][k].getNumber() == square[i][j].getNumber()) {
                    square[i][k].addNumber();
                    square[i][j].setNumber(1);
                    addScore(square[i][k].getNumber());
                    moved = true;
                    break;
                }
            }
        }
    }
    return moved;
}

void Puzzle::print() {
    //just proper printing
    for (int i = 0; i < n * 6 + 1; i++)
        printf("-");
    printf("\n");
    for (int i = 0; i < n; i++) {
        //just proper printing
        for (int j = 0; j < n; j++)
            printf("|%5s", "");
        printf("|\n");
        for (int j = 0; j < n; j++) {
            printf("|");
            if (square[i][j].isEmpty())
                printf("%5s", "");
                //-3 fills with spaces
            else if (square[i][j].getNumber() / 10 > 10)    //if number between 100 and 1000 print one space
                printf(" %-4d", square[i][j].getNumber());
            else if (square[i][j].getNumber() / 10 > 1000)      //if number > 10000 print no space
                printf("%-5d", square[i][j].getNumber());
            else
                printf("  %-3d", square[i][j].getNumber());
        }
        printf("|\n");
        //just proper printing
        for (int j = 0; j < n; j++)
            printf("|%5s", "");
        printf("|\n");
        //just proper printing
        for (int k = 0; k < n * 6 + 1; k++)
            printf("-");
        printf("\n");
    }
}

bool Puzzle::endGame() {
    std::vector<std::vector<Square>> bigSquare;   //create bigger square +two rows, +two columns with values 99
    std::vector<Square> bigRow;
    for (int i = 0; i < n + 2; i++) {
        Square s(99);
        bigRow.push_back(s);
    }
    bigSquare.push_back(bigRow);            //add one row in the beginning
    for (int i = 0; i < n; i++) {
        std::vector<Square> row = square[i];        //get row and add 99 at the beginning and end of the row
        Square s(99);
        row.insert(row.begin(), s);
        row.insert(row.end(), s);
        bigSquare.push_back(row);       //add one row in the end
    }
    bigSquare.push_back(bigRow);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (bigSquare[i][j].isEmpty())         // if there is an empty cell game does not end
                return false;
            // if there is equal value in above,right,left,under game does not end, move is possible
            if (bigSquare[i][j].getNumber() == bigSquare[i + 1][j].getNumber())
                return false;
            if (bigSquare[i][j].getNumber() == bigSquare[i - 1][j].getNumber())
                return false;
            if (bigSquare[i][j].getNumber() == bigSquare[i][j + 1].getNumber())
                return false;
            if (bigSquare[i][j].getNumber() == bigSquare[i][-1].getNumber())
                return false;
        }
    }
    return true;
}

bool Puzzle::add() {
    int count = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (!square[i][j].isEmpty())
                count++;
    if (count == n * n)
        return false;
    while (1) {
        int x = rand() % 4;
        int y = rand() % 4;
        if (!square[x][y].isEmpty())
            continue;
        int multiplier = rand() % 2 + 1;
        square[x][y].setNumber(multiplier * 2);
        break;
    }
    return true;
}

void Puzzle::addScore(int points) {
    score = score + points;
}

void Puzzle::initalize() {
    int added = 0;
    srand(time(nullptr));
    while (added != 2) {
        int x = rand() % 4;     //generate two random integers from 0 to 3
        int y = rand() % 4;
        if (!square[x][y].isEmpty())        //if square is occupied continue again
            continue;
        int multiplier = rand() % 2 + 1;        //get random number between 1 and 2
        Square temp(multiplier * 2);        //make Square with value 2 or 4
        square[x][y] = temp;
        added++;
    }
}

void Puzzle::restart() {            //empty all cells by initializing all squares to 1
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            square[i][j].setNumber(1);
    Puzzle::initalize();        //add two numbers
    score = 0;      //set score to 0
}

Puzzle::Puzzle(int n) {
    Puzzle::n = n;      //get n and construct vector containing vector of Squares
    for (int i = 0; i < n; i++) {
        std::vector<Square> row;
        for (int j = 0; j < n; j++) {
            Square empty(1);
            row.push_back(empty);
        }
        square.push_back(row);
    }
    Puzzle::initalize();        //add two random values
}

int Puzzle::getScore() const {
    return score;
}

void Puzzle::setNotAdded() {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            square[i][j].setNotAdded();     //set all squares's added to false
}

void Puzzle::save() {
    setSaved(true);
    savedSquare = square;
}

void Puzzle::load() {
    setSaved(false);
    square = savedSquare;
}

bool Puzzle::isSaved() const {
    return saved;
}

void Puzzle::setSaved(bool value) {
    Puzzle::saved = value;
}
