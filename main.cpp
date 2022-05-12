#include <iostream>
#include "Game.h"

using namespace std;


int main() {


    cout << "Let's  play Othello/Reversi!" << endl;

    // Displaying menu, having a separate function for menu seemed over complicated and pointless

    int play;
    cout << "\n\nMENU" << endl;
    cout<<"-------------"<<endl;
    cout << "[1] New" << endl;
    cout << "[2] Load" << endl;
    cout << "[3] Quit" << endl;
    cin >> play;

    if(play == 1) {

        string player1, player2;
        cout << "Enter a name for Player 1" << endl;
        cin >> player1;
        cout << "Enter a name for Player 2" << endl;
        cin >> player2;


        Game g = {player1, player2};
        g.play();
    }

    if(play == 2) {

        Game g = Game::load();

        g.play();

    }

    else cout << "Goodbye!" << endl;


    return 0;
}
