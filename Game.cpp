
#include "Game.h"

#include <string>
#include <iostream>
#include <fstream>

using namespace std;

Game::Game(std::string name1, std::string name2):
black(name1, Position::BLACK),
white(name2, Position::WHITE)
{}

void Game::play() {

    while (true) {
        if (isOver()) break;
        Board::printBoard(board);
        if (makeMove()) {
            Board::printBoard((board));
            if (currentPlayer == &black) currentPlayer = &white;
            else currentPlayer = &black;


        }

        if(inSaveMode) {
            save();
            cout << "You have saved, thanks for playing." << endl;
            return;
        }

    }
    points();
    if (scoreBoard[0] > scoreBoard[1]) cout<<black .getName()<<" wins!"<<endl;
    else if (scoreBoard[1] < scoreBoard[0]) cout<<white .getName()<<"White wins!"<<endl;
    else cout<<"It's a tie!"<<endl;
}

// The below all could have been implemented into one function under the circumstance that a two
//dimensional array was used. I didn't use one...hence the 8 separate functions.

bool Game::checkLeft(int val) {

    // array for leftmost column
    int arr_r[8] = {};
    int  r = 0;
    for (int i = 0; i < 8; ++i) {
        arr_r[i] = r;
        r += 8;
    }

    int i = 0;
    while (true) {
        if (board[val - (1 + i) ] != currentPlayer ->getMark() && board[val - (1 + i)] != Position::EMPTY){
            i++;
            if(board[val - (1 + i)] == currentPlayer ->getMark()){
                return true;
            }
            for (int j = 0; j < 8; ++j) {

                if (val - (1 + i) < 0) return false;
                if (val - (1 + i) == arr_r[j]) return false;
            }
        }
        else return false;
    }

}
bool Game::checkRight(int val) {

    // array for rightmost column
    int arr_l[8] = {};
    int l = 7;
    for (int i = 0; i < 8; ++i) {
        arr_l[i] = l;
        l += 8;
    }

    int i = 0;
    while (true) {
        if (board[val + (1 + i) ] != currentPlayer ->getMark() && board[val + (1 + i)] != Position::EMPTY){
            i++;
            if(board[val + (1 + i)] == currentPlayer ->getMark()){
                return true;
            }
            for (int j = 0; j < 8; ++j) {
                if ((val + (1 + i)) > 63) return false;
                if (val + (1 + i) == arr_l[j]) return false;
            }
        }
        else return false;
    }



}
bool Game::checkTop(int val) {

    // array for top row;
    int arr_t[8] = {};
    for (int i = 0; i < 8; ++i) {
        arr_t[i] = i;

    }

    int i = 0;
    while (true) {
        if (board[val - (8 * (i + 1)) ] != currentPlayer ->getMark() && board[val - (8 * (i + 1)) ] != Position::EMPTY){
            i++;
            if(board[val - (8 * (i + 1)) ] == currentPlayer ->getMark()){
                return true;
            }
            for (int j = 0; j < 8; ++j) {
                if ((val - (8 * (i + 1))) < 0) return false;
                if (val - (8 * (i + 1)) == arr_t[j]) return false;
            }
        }
        else return false;
    }
}
bool Game::checkBottom(int val) {

    // array for bottom row;
    int arr_b[8] = {};
    int bot = 56;
    for (int i = 0; i < 8; ++i) {
        arr_b[i] = bot + i;

    }
    int i = 0;
    while (true) {
        if (board[val + (8 * (i + 1)) ] != currentPlayer ->getMark() && board[val + (8 * (i + 1)) ] != Position::EMPTY){
            i++;
            if(board[val + (8 * (i + 1)) ] == currentPlayer ->getMark()){
                return true;
            }
            for (int j = 0; j < 8; ++j) {

                if (val + (8 * (i + 1)) > 63) return false;
                if (val + (8 * (i + 1)) == arr_b[j]) return false;
            }
        }
        else return false;
    }




}
bool Game::checkTopLeft(int val) {


    // array for leftmost column
    int arr_l[8] = {};
    int  l = 0;
    for (int i = 0; i < 8; ++i) {
        arr_l[i] = l;
        l += 8;
    }

    // array for top row;
    int arr_t[8] = {};
    for (int i = 0; i < 8; ++i) {
        arr_t[i] = i;
    }

    int i = 0;
    while (true) {
        if (board[val - (9 * (i + 1)) ] != currentPlayer ->getMark() && board[val - (9 * (i + 1)) ] != Position::EMPTY){
            i++;
            if(board[val - (9 * (i + 1)) ] == currentPlayer ->getMark()){
                return true;
            }
            for (int j = 0; j < 8; ++j) {
                if (val - (9 * (i + 1)) < 0 ) return false;
                if (val - (9 * (i + 1)) == arr_l[j]) return false;
            }

            for (int j = 0; j < 8; ++j) {

                if (val - (9 * (i + 1)) < 0) return false;
                if (val - (9 * (i + 1)) == arr_t[j]) return false;
            }

        }
        else return false;
    }


}
bool Game::checkBottomRight(int val) {

    // array for rightmost column
    int arr_l[8] = {};
    int l = 7;
    for (int i = 0; i < 8; ++i) {
        arr_l[i] = l;
        l += 8;
    }
    // array for bottom row;
    int arr_b[8] = {};
    int bot = 56;
    for (int i = 0; i < 8; ++i) {
        arr_b[i] = bot + i;

    }
    int i = 0;
    while (true) {
        if (board[val + (9 * (i + 1)) ] != currentPlayer ->getMark() && board[val + (9 * (i + 1)) ] != Position::EMPTY){
            i++;
            if(board[val + (9 * (i + 1)) ] == currentPlayer ->getMark()){
                return true;
            }
            for (int j = 0; j < 8; ++j) {
                if (val + (9 * (i + 1)) > 63) return false;
                if (val + (9 * (i + 1)) == arr_l[j]) return false;
            }

            for (int j = 0; j < 8; ++j) {

                if (val + (9 * (i + 1)) > 63) return false;
                if (val + (9 * (i + 1)) == arr_b[j]) return false;
            }

        }
        else return false;
    }

}
bool Game::checkTopRight(int val) {

    // array for rightmost column
    int arr_r[8] = {};
    int r = 7;
    for (int i = 0; i < 8; ++i) {
        arr_r[i] = r;
        r += 8;
    }
    // array for top row;
    int arr_t[8] = {};
    for (int i = 0; i < 8; ++i) {
        arr_t[i] = i;

    }


    int i = 0;
    while (true) {
        if (board[val - (7 * (i + 1)) ] != currentPlayer ->getMark() && board[val - (7 * (i + 1)) ] != Position::EMPTY){
            i++;
            if(board[val - (7 * (i + 1)) ] == currentPlayer ->getMark()){
                return true;
            }
            for (int j = 0; j < 8; ++j) {
                if (val - (7 * (i + 1)) < 0) return false;
                if (val - (7 * (i + 1)) == arr_r[j]) return false;
            }

            for (int j = 0; j < 8; ++j) {
                if (val - (7 * (i + 1)) < 0) return false;
                if (val - (7 * (i + 1)) == arr_t[j]) return false;
            }

        }
        else return false;
    }



}
bool Game::checkBottomLeft(int val) {

    // array for bottom row;
    int arr_b[8] = {};
    int bot = 56;
    for (int i = 0; i < 8; ++i) {
        arr_b[i] = bot + i;
    }
    // array for leftmost column
    int arr_l[8] = {};
    int  r = 0;
    for (int i = 0; i < 8; ++i) {
        arr_l[i] = r;
        r += 8;
    }

    int i = 0;
    while (true) {
        if (board[val + (7 * (i + 1)) ] != currentPlayer ->getMark() && board[val + (7 * (i + 1)) ] != Position::EMPTY){
            i++;
            if(board[val + (7 * (i + 1)) ] == currentPlayer ->getMark()){
                return true;
            }
            for (int j = 0; j < 8; ++j) {
                if (val + (7 * (i + 1)) > 63) return false;
                if (val + (7 * (i + 1)) == arr_l[j]) return false;
            }

            for (int j = 0; j < 8; ++j) {

                if (val + (7 * (i + 1)) > 63) return false;
                if (val + (7 * (i + 1)) == arr_b[j]) return false;
            }

        }
        else return false;
    }



}

// Similarly for makeMove, there is a lot of repetition for flipping and placing pieces.

bool Game::makeMove() {

    cout << "Hit 's' to save,'m' to move or 'c' to concede" << endl;
    char type;
    cin >> type;

    if(type == 's') {
        inSaveMode = true;
        return false;
    }
    if (type == 'c'){

        points();
        if (scoreBoard[0] > scoreBoard[1]) cout<<black .getName()<<"wins!"<<endl;
        else if (scoreBoard[1] < scoreBoard[0]) cout<<white .getName()<<"White wins!"<<endl;
        else cout<<"It's a tie!"<<endl;
        exit(0); //it's lazy I know

    }

    else {

        cout << "It is currently " << currentPlayer->getName() << "'s turn, select a position from (0 - 63)" << endl;
        cin >> pos;

        if (pos > 63 || pos < 0) {
            cout << "The position is out of range, please select another position" << endl;
            return false;
        }

        if (board[pos] != Position::EMPTY) {
            cout << "position is already taken, please select another position" << endl;
            return false;
        }

        for (int i = 0; i < 4; ++i) {
            Position unplayable;

            if (pos == unplayable.UNPLAYABLE_arr[i]) {

                cout<<"This position was deemed unplayable, it would usually be legal, but now it is illegal\n"
                      "Kindly select another position from (0 - 63)"<<endl;

                return false;
            }

        }


        if (!(checkLeft(pos) || checkRight(pos)
              || checkBottom(pos) || checkTop(pos)
              || checkTopLeft(pos) || checkTopRight(pos)
              || checkBottomLeft(pos) || checkBottomRight(pos))) {
            cout << "Not a valid move try again!" << endl;
            return false;
        }


        if (checkLeft(pos)) {

            board[pos] = currentPlayer->getMark();
            for (int i = 0; i < 8; ++i) {
                if (board[pos - (1 + i)] == currentPlayer->getMark()) break;
                board[pos - (1 + i)] = currentPlayer->getMark();
            }

        }

        if (checkRight(pos)) {

            board[pos] = currentPlayer->getMark();
            for (int i = 0; i < 8; ++i) {
                if (board[pos + (1 + i)] == currentPlayer->getMark()) break;
                board[pos + (1 + i)] = currentPlayer->getMark();
            }

        }

        if (checkTop(pos)) {

            board[pos] = currentPlayer->getMark();
            for (int i = 0; i < 8; ++i) {
                if (board[pos - (8 * (i + 1))] == currentPlayer->getMark()) break;
                board[pos - (8 * (i + 1))] = currentPlayer->getMark();
            }

        }

        if (checkBottom(pos)) {

            board[pos] = currentPlayer->getMark();
            for (int i = 0; i < 8; ++i) {
                if (board[pos + (8 * (i + 1))] == currentPlayer->getMark()) break;
                board[pos + (8 * (i + 1))] = currentPlayer->getMark();
            }

        }

        if (checkTopLeft(pos)) {

            board[pos] = currentPlayer->getMark();
            for (int i = 0; i < 8; ++i) {
                if (board[pos - (9 * (i + 1))] == currentPlayer->getMark()) break;
                board[pos - (9 * (i + 1))] = currentPlayer->getMark();
            }

        }

        if (checkBottomRight(pos)) {

            board[pos] = currentPlayer->getMark();
            for (int i = 0; i < 8; ++i) {
                if (board[pos + (9 * (i + 1))] == currentPlayer->getMark()) break;
                board[pos + (9 * (i + 1))] = currentPlayer->getMark();
            }

        }

        if (checkTopRight(pos)) {

            board[pos] = currentPlayer->getMark();
            for (int i = 0; i < 8; ++i) {
                if (board[pos - (7 * (i + 1))] == currentPlayer->getMark()) break;
                board[pos - (7 * (i + 1))] = currentPlayer->getMark();
            }

        }

        if (checkBottomLeft(pos)) {

            board[pos] = currentPlayer->getMark();
            for (int i = 0; i < 8; ++i) {
                if (board[pos + (7 * (i + 1))] == currentPlayer->getMark()) break;
                board[pos + (7 * (i + 1))] = currentPlayer->getMark();
            }

        }

        return true;

    }
}

// counts the number of positions each player occupies.

void Game::points() {

    for (int i = 0; i < 64; ++i) {
        if (board[i] == 'B')
            scoreBoard[0]++;
        else if (board[i] == 'W')
            scoreBoard[1]++;
        else continue;
    }

}

// checks if there are any playable positions

bool Game::isOver() {

    for (int i = 0; i < 63; ++i) {

        if (board[i] != Position::EMPTY) continue;

        for (int j = 0; j < 4; ++j) {
            Position unplayable;

            if (pos == unplayable.UNPLAYABLE_arr[j]) continue;
        }


        //Note: the below if statement can be commented out, it is here because it made my
        // life easier when bug testing the the playable positions. I'll leave it here for you
        // benefit.

        if ((checkLeft(i) || checkRight(i)
             || checkBottom(i) || checkTop(i)
             || checkTopLeft(i) || checkTopRight(i)
             || checkBottomLeft(i) || checkBottomRight(i)))
        {
            cout<<"There are playable positions at "<<i<<endl;
        }
    }

    // Checks if there are playable positions by the current player, if there is at least one. It will return false
    // and the game will continue

    for (int i = 0; i < 63; ++i) {

        if (board[i] != Position::EMPTY) continue;

        if ((checkLeft(i) || checkRight(i)
             || checkBottom(i) || checkTop(i)
             || checkTopLeft(i) || checkTopRight(i)
             || checkBottomLeft(i) || checkBottomRight(i)))
        {
            return false;
        }
    }

    // The below is kind of pointless, I left it here just in case.

    for (int i = 0; i < 63; ++i) {

        if (board[i] == Position::EMPTY) return false;

    }

    return true;

}

// Code for saving

void Game::save() {
    //save
    cout << "Please type a file name:" << endl;
    string filename;
    cin >> filename;
    fstream fs;
    fs.open (filename, fstream::out);
    fs << black.getName() << endl;
    fs << white.getName() << endl;
    fs << currentPlayer->getName() << endl;
    for(int i = 0; i < 64; ++i) fs << board[i];
    fs.close();
    inSaveMode = false;
}

// code for loading, partially works. I'm not sure why.

Game Game::load() {
    cout << "Please type a file name:" << endl;
    string filename;
    cin >> filename;
    fstream fs;
    fs.open (filename, fstream::in);
    string p1Name, p2Name, current, data;
    fs >> p1Name >> p2Name >> current  >> data;
    fs.close();

    Game g(p1Name, p2Name, current, data);
    return g;
}
