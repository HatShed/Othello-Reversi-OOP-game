

#ifndef UNTITLED54_PLAYER_H
#define UNTITLED54_PLAYER_H
#include <iostream>

class Player {

    // the player class just holds a char and a string, I usually wouldn't have included this
    // but this assignment requires one.

public:

    Player(std::string name, char mark);

    std::string getName(){
        return name;
    }
    char getMark(){
        return mark;
    }

private:

    std::string name;
    char mark;


};


#endif //UNTITLED54_PLAYER_H
