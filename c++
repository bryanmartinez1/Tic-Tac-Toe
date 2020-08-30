#include <iostream>
#include <vector>
#include <string>

using namespace std;

void board(vector<char> p) {
    cout << endl;
    for (int j = 0; j < p.size(); ++j) {
            cout << p[j] << "  ";
            if (j == 2 or j == 5 or j == 8) {
                cout << endl;
            }
        }
        cout << endl;
}

bool winner(vector <char> game, char x, char o) {
    //Won Vetically
    if (game[0] == game[1] && game[1] == game[2]) {
        return true;
    }
    else if (game[3] == game[4] && game[4] == game[5]) {
        return true;
    }
    else if (game[6] == game[7] && game[7] == game[8]) {
        return true;
    }
    //Won Horzontally
    else if (game[0] == game[3] && game[3] == game[6]) {
        return true;
    }
    else if (game[1] == game[4] && game[4] == game[7]) {
        return true;
    }
    else if (game[2] == game[5] && game[5] == game[8]) {
        return true;
    }
    //Won Diagonally
    else if (game[0] == game[4] && game[4] == game[8]) {
        return true;
    }
    else if (game[2] == game[4] && game[4] == game[6]) {
        return true;
    }
    else {
        return false;
    }
}

int main() {
    vector<char> places = {'0', '1', '2', '3', '4', '5', '6', '7', '8'};
    int here1, here2;
    char p1Symbol, p2Symbol;
    bool iswinner = false;
    bool p1wins = false;
    bool p2wins = false;
    bool tie = false;
    int turns = 0;
    
    cout << "Welcome to Multiplayer Tic Tac Toe Game!" << endl;
    cout << "Player 1, please input the character you would like to use" << endl;
    cin >> p1Symbol;
    cout << "Player 2, please input the character you would like to use" << endl;
    cin >> p2Symbol;
    
    board(places);
    
    while (iswinner == false) {
        cout << "Player 1, where would you like to place the character:" << endl;
        cin >> here1;
        places[here1] = p1Symbol;
        board(places);
        iswinner = winner(places, p1Symbol, p2Symbol);
        turns += 1;
        if (iswinner == true) {
            p1wins = true;
            break;
        }
        if (turns == 9 ) {
            tie = true;
            break;
        }
        cout << "Player 2, where would you like to place the character:" << endl;
        cin >> here2;
        places[here2] = p2Symbol;
        board(places);
        iswinner = winner(places, p1Symbol, p2Symbol);
        turns += 1;
        if (iswinner == true) {
            p2wins = true;
            break;
        }
    }
    
    if (p1wins) { 
        cout << endl << "Player 1 Wins" << endl;
    }
    
    else if (p2wins) { 
        cout << endl << "Player 2 Wins" << endl;
    }
    
    else if (tie) {
        cout << endl << "Its a tie" << endl;
    }
    return 0;
}
