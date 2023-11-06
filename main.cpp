#include "tictactoe.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main () {

    TicTacToe partie;
    // Génération d'un nombre aléatoire entre 0 et 1
    int piece = rand() % 2;
    int bestMove = 0;
    bestMove = 0;
    partie.Affichage();
    while (partie.arbitre() == -2) {
        if (piece == 0) {
            partie.jeuOrdi(bestMove);
            partie.play(bestMove, false);    
            partie.jeuHumain(bestMove);
            partie.play(bestMove, true);
        } else {
            partie.jeuHumain(bestMove);
            partie.play(bestMove, true);
            partie.jeuOrdi(bestMove);
            partie.play(bestMove, false);
        }

        if (partie.arbitre() == 1){
            cout << "L'ordinateur a gagné !" << endl;
            partie.Affichage();
        } else if (partie.arbitre() == -1) {
            cout << "Vous avez gagné !" << endl;
            partie.Affichage();
        } else if (partie.arbitre() == 0) {
            cout << "Match nul !" << endl;
            partie.Affichage();
        }
    }
    return 0;
}