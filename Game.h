//
// Created by Hat_Shed on 2021-11-12.
//

#ifndef UNTITLED54_GAME_H
#define UNTITLED54_GAME_H

#include <string>

#include "Player.h"
#include "Position.h"
#include "Board.h"

class Game {

public:

    //Default constructor
    Game(std::string name1, std::string name2);

    //Constructor for loading (There's most likely a mistake here, I could not figure it out)
    Game(std::string p1Name, std::string p2Name, std::string current, std::string data) :
            Game(p1Name, p2Name)
    {
        boardData = data;
        if(p1Name.compare(current)==0) {
            currentPlayer = &black;
        } else {
            currentPlayer = &white;
        }
    }

    // Non validation functions defined here:

    void play();
    bool makeMove();
    void points();
    void save();
    static Game load();


    // validation:

    bool checkLeft(int val);
    bool checkRight(int val);
    bool checkTop(int val);
    bool checkBottom(int val);
    bool checkTopLeft(int val);
    bool checkBottomRight(int val);
    bool checkTopRight(int val);
    bool checkBottomLeft(int val);
    bool isOver();





private:


    Board b;
    Player black, white, *currentPlayer = &black;
    int scoreBoard[2] = {};
    int pos;
    bool inSaveMode = false;
    char *board = b.board1;
    std::string boardData;

};


#endif //UNTITLED54_GAME_H
