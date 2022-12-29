#include <iostream>
#include "Puzzle.h"


using namespace std;

void printConsole() {
    //to not mess main function
    printf("Control Keys:\n");
    printf("(W) %14s\n", "Up");
    printf("(A) %14s\n", "Down");
    printf("(S) %14s\n", "Right");
    printf("(D) %14s\n", "Left");
    printf("(R) %14s\n", "New Game");
    printf("(P) %14s\n", "Save");
    printf("(L) %14s\n", "Load");
    printf("(Q) %14s\n", "Quit");
}

int main() {
    Puzzle puzzle(4);
    char input;
    while (true) {//until game is not over
        if (puzzle.endGame()) {
            cout << "Game has ended!!!";
            if (!puzzle.isSaved())
                break;
            else {
                printf("Current game is over. But you have a saved game\n");
                puzzle.load();
                continue;
            }
        }
        printf("%20s", "2048 Puzzle Game\n");
        cout << "Score: " << puzzle.getScore() << '\n';
        puzzle.print(); //print Square
        printConsole(); //print Options
        cout << "Enter an input:";
        cin >> input;
        if (input >= 'A' && input <= 'Z')       //just lower the character
            input += 32;
        bool moveCompleted = false; //to check if puzzle was moved in any direction
        if (input == 'w')
            moveCompleted = puzzle.moveUp();
        else if (input == 's')
            moveCompleted = puzzle.moveDown();
        else if (input == 'd')
            moveCompleted = puzzle.moveRight();
        else if (input == 'a')
            moveCompleted = puzzle.moveLeft();
        else if (input == 'p') {
            puzzle.save();
            printf("Your progress is saved. You can continue\n");
        } else if (input == 'r') {
            puzzle.restart();       //restart all values in square
            continue;
        } else if (input == 'l' && puzzle.isSaved())
            puzzle.load();
        else if (input == 'l' && !puzzle.isSaved()) {
            cout << "There is nothing to load\n";
            continue;
        } else if (input == 'q')
            exit(0);
        else {
            cout << "There is no such an input\n";
            continue;
        }
        if (!moveCompleted) {     //if nothing changed does not do anything just go repeat
            cout << "Move was not completed\n";
            continue;
        }
        puzzle.setNotAdded();       //set added of all Squares to false
        if (!puzzle.add())     // if nothing can be added then there is
            cout << "Can't add a number. Make a right move\n";
    }
    return 0;
}
